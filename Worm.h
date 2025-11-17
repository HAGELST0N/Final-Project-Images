//
// Created by colin.skaarup on 11/17/2025.
//

#ifndef WORM_H
#define WORM_H

#include "FastNoiseLite.h"
#include <vector>

class Worm {
public:
    Worm();
    std::pair<float, float> getDirection(float x, float y);
    void Walk();
private:
    FastNoiseLite noise;
    float h_xPos, h_yPos, speed, length;
    std::vector<float, float> positions;
    int segCount;
};



#endif //WORM_H
