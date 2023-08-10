//
// Created by rml-phat on 2/10/22.
//

#ifndef RRTSTAR_CFS_DUBINS_ABSTACLES_H
#define RRTSTAR_CFS_DUBINS_ABSTACLES_H


#include <QDebug>
#include <QLine>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <assert.h>
#include "constants.h"

using namespace Eigen;
using namespace std;

class Obstacles
{
public:
    Obstacles();
    void addObstacle(Vector2f firstPoint, Vector2f secondPoint);
    bool isSegmentInObstacle(Vector2f &p1, Vector2f &p2);
    vector<pair<Vector2f, Vector2f> > obstacles;
};



#endif //RRTSTAR_CFS_DUBINS_ABSTACLES_H
