//
// Created by rml-phat on 2/10/22.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "unistd.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderArea = ui->renderArea;
    rrtstar = renderArea->rrtstar;
    simulated = false;
}

/**
 * @brief Start the simulator.
 */
void MainWindow::on_startButton_clicked() {
    if (simulated) {
        ui->statusBox->setText(tr("Please reset!"));
        renderArea->update();
        return;
    }
    simulated = true;
    // get step size and max iterations from GUI.
    rrtstar->setMaxIterations(ui->maxIterations->text().toInt());
    rrtstar->setStepSize(ui->stepSize->text().toInt());

    assert(rrtstar->step_size > 0);
    assert(rrtstar->max_iter > 0);
    int time_reach = 0;
    int step = 0;
    float Cost_nearest = 0;
    float Path_cost = 0;
    float cost_reach[5000] = {};
    float Cost_parent = 0;
    int reach = 0;
    int reach_step[5000] = {};
    int last_reach_step[5000] = {};
    int shortest_step[5000] = {};
    // RRTSTAR Algorithm ==============================================================================================
    for (int i = 0; i < renderArea->rrtstar->max_iter; i++) {
        Node *q = rrtstar->getRandomNode();
//        Node *q_rand_tmp = q_goal * (1 - phi)*(rrtstar->getRandomNode() - q_goal);
        if (q) {
            Node *qNearest = rrtstar->nearest(q->position);
            if (rrtstar->distance(q->position, qNearest->position) > rrtstar->step_size) {
                Vector3f newConfigPosOrient;
                DubinsPath path;
                if (BOT_FOLLOW_DUBIN)
                    newConfigPosOrient = rrtstar->newDubinConfig(q, qNearest, path);
                else
                    newConfigPosOrient = rrtstar->newConfig(q, qNearest);

                Vector2f newConfigPos(newConfigPosOrient.x(), newConfigPosOrient.y());
//                qDebug() << "\n======" << i << "==========";
                if (!rrtstar->obstacles->isSegmentInObstacle(newConfigPos, qNearest->position)) {
                    Node *qNew = new Node;
                    qNew->position = newConfigPos;
                    qNew->orientation = newConfigPosOrient.z();
//                    qNew->path = path;

                    vector<Node *> Qnear;
                    rrtstar->near(qNew->position, rrtstar->step_size * RRTSTAR_NEIGHBOR_FACTOR, Qnear);
//                    qDebug() << "Found Nearby Qnear.size(): " << Qnear.size();
                    Node *qMin = qNearest;

                    double cmin = rrtstar->Cost(qNearest) + rrtstar->PathCost(qNearest, qNew);
//                    qDebug() << "cmin: " << cmin;
                    for (int j = 0; j < Qnear.size(); j++) {
                        Node *qNear = Qnear[j];
                        if (!rrtstar->obstacles->isSegmentInObstacle(qNear->position, qNew->position) &&
                            (rrtstar->Cost(qNear) + rrtstar->PathCost(qNear, qNew)) < cmin) {
                            qMin = qNear;
                            cmin = rrtstar->Cost(qNear) + rrtstar->PathCost(qNear, qNew);
                        }
                    }
//                    qDebug() << "cmin_update: " << cmin;
                    rrtstar->add(qMin, qNew);

                    for (int j = 0; j < Qnear.size(); j++) {
                        Node *qNear = Qnear[j];
                        if (!rrtstar->obstacles->isSegmentInObstacle(qNew->position, qNear->position) &&
                            (rrtstar->Cost(qNew) + rrtstar->PathCost(qNew, qNear)) < rrtstar->Cost(qNear)) {
                            Node *qParent = qNear->parent;
                            // Remove edge between qParent and qNear
                            qParent->children.erase(
                                    std::remove(qParent->children.begin(), qParent->children.end(), qNear),
                                    qParent->children.end());

                            // Add edge between qNew and qNear
                            qNear->cost = rrtstar->Cost(qNew) + rrtstar->PathCost(qNew, qNear);
                            qNear->parent = qNew;
                            qNew->children.push_back(qNear);
                        }
                    }

                    if (rrtstar->reached()) {
                        reach = i + 1;
                        time_reach++;
                        cost_reach[time_reach] = Cost_nearest;
                        reach_step[time_reach] = reach;
                        for(int j = 1; j <= time_reach; j++){
                            last_reach_step[j] = reach_step[j] - reach_step[j-1];
                            qDebug() << "Cost_reach" << cost_reach[j] << "Step_reach:" << reach_step[j] << last_reach_step[j];
                            if (cost_reach[1] > cost_reach[j])
                                cost_reach[1] = cost_reach[j];
                            if (reach_step[1] > reach_step[j])
                                reach_step[1] = reach_step[j];
                            if (shortest_step[1] > last_reach_step[j])
                                shortest_step[1] = last_reach_step[j];
                            if(cost_reach[1] == cost_reach[j])
                                shortest_step[0] = reach_step[j];
                        }
                        qDebug() << "Min_cost:" << cost_reach[1] << "at th_step:" << shortest_step[0];
                    }

                    Cost_nearest = rrtstar->Cost(qNearest);
                    Path_cost = rrtstar->PathCost(qNearest, qNew);
//                    qDebug() << "Cost_nearest:" << Cost_nearest << "\tPart_cost:" << Path_cost << "\n";
                    QString result = QString::fromStdString("Algorithm: RRT*-Dubins").append("\n");
                    QString result1 = QString::fromStdString(to_string(i + 1)).prepend("Processing step: ").append(
                            "\n");
                    QString result2 = QString::fromStdString(to_string(cost_reach[1])).prepend("Cost_nearest: ").append(
                            "\t");
                    QString result3 = QString::fromStdString(to_string(shortest_step[0])).prepend("at step: ").append(
                            "\n");;
                    QString result4 = QString::fromStdString(to_string(Path_cost)).prepend("Path_cost: ").append("\n");
                    ui->textBrowser->setText(result + result1 + result2 + result3 + result4);
                }
            }
        }

//        qDebug ("step: %d",i+1);
        QString iter = QString::fromStdString(to_string(reach_step[1])).prepend("First reached: ").append(" steps");
        QString iter1 = QString::fromStdString(to_string(time_reach)).prepend("; Time: ");
        if (rrtstar->reached()) {

            ui->statusBox->setText(iter + iter1);
            qDebug("Reached destination at %d st and %d times", i + 1, time_reach);
//                sleep(1);
//                break;
        } else {
//                ui->statusBox->setText(tr("Exceeded max iterations!...."));
            ui->statusBox->setText(iter + iter1);
        }
        renderArea->update();
        qApp->processEvents();

    }

    Node *q;
    if (rrtstar->reached()) {
        q = rrtstar->lastNode;
    }
    else
    {
        // if not reached yet, then shortestPath will start from the closest node to end point.
        q = rrtstar->nearest(rrtstar->endPos);
    }
    while (q != NULL) {
        step++;
        rrtstar->path.push_back(q);
        Cost_parent = rrtstar->Cost(q);
        qDebug() << "q_parent:" << q;
        qDebug() << "Cost_parent:" << Cost_parent;
        q = q->parent;

    }
    renderArea->update();
    qApp->processEvents();
}

/**
 * @brief Delete all obstacles, nodes and paths from the simulator.
 */
void MainWindow::on_resetButton_clicked()
{
    simulated = false;
    ui->statusBox->setText(tr(""));
    rrtstar->obstacles->obstacles.clear();
    rrtstar->obstacles->obstacles.resize(0);
    rrtstar->deleteNodes(rrtstar->root);
    rrtstar->nodes.clear();
    rrtstar->nodes.resize(0);
    rrtstar->path.clear();
    rrtstar->path.resize(0);
    rrtstar->initialize();
    renderArea->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

