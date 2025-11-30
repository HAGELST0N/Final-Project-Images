//
// Created by colin.skaarup on 11/17/2025.
//

#ifndef WORM_H
#define WORM_H

#include <iosfwd>
#include <list>

#include "FastNoiseLite.h"
#include <vector>

class Worm {
public:
    Worm();
    std::pair<float, float> getDirection(float x, float y);
    void Walk();
    void print();
    std::list<std::pair<float, float>> positions;
private:
    FastNoiseLite noise;
    float h_xPos = 0.01, h_yPos = 0.01, speed = 10.0, length = 10.0;
    int maxSegCount = 500;
};



#endif //WORM_H
