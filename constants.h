//
// Created by rml-phat on 2/10/22.
//

#ifndef RRTSTAR_CFS_DUBINS_CONSTANTS_H
#define RRTSTAR_CFS_DUBINS_CONSTANTS_H

const float WORLD_WIDTH = 400.0;
const float WORLD_HEIGHT = 400.0;
const float BOT_RADIUS = 10.0;
const float START_POS_X = 30.0;
const float START_ORIENT = 0.785;
const float START_POS_Y = 363.0;
const float END_POS_X = 363.0;
const float END_POS_Y = 30.0;
const float NODE_RADIUS = 1.0;
const float END_DIST_THRESHOLD = 15.0;
const float BOT_CLEARANCE = 1.2 * BOT_RADIUS;
const float BOT_TURN_RADIUS = 7;
const float RRTSTAR_NEIGHBOR_FACTOR = 8;
const bool BOT_FOLLOW_DUBIN = false;


#endif //RRTSTAR_CFS_DUBINS_CONSTANTS_H
