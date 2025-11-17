//
// Created by colin.skaarup on 11/17/2025.
//

#ifndef WORM_H
#define WORM_H

#include <list>

#include "FastNoiseLite.h"
#include <vector>

class Worm {
public:
    Worm();
    std::pair<float, float> getDirection(float x, float y);
    void Walk();
private:
    FastNoiseLite noise;
    float h_xPos, h_yPos, speed = 10.0, length = 10.0;
    std::list<std::pair<float, float>> positions;
    int maxSegCount = 5;
};



#endif //WORM_H
