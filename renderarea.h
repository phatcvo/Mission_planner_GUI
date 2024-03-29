//
// Created by rml-phat on 2/10/22.
//

#ifndef RRTSTAR_CFS_DUBINS_RENDERAREA_H
#define RRTSTAR_CFS_DUBINS_RENDERAREA_H


#include "rrtstar.h"
#include <QWidget>
#include <QColor>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
#include <QPainterPath>
#include <QPainter>
#include <QRect>

class RenderArea : public QWidget
{
Q_OBJECT
public:
    RenderArea(QWidget *parent = 0);
    RRTSTAR *rrtstar;
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void drawField(QPainter &event);
    void drawStartPos(QPainter &event);
    void drawEndPos(QPainter &event);
    void drawObstacles(QPainter &event);
    void drawNodes(QPainter &event);
private:
    bool scribbling;
    QPoint lastMouseClickedPoint;
signals:
    void painting();
};

#endif //RRTSTAR_CFS_DUBINS_RENDERAREA_H
