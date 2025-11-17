//
// Created by colin.skaarup on 11/17/2025.
//

#include "Worm.h"
#include <cmath>

Worm::Worm() {

}

std::pair<float, float> Worm::getDirection(float x, float y) {
    float degrees = noise.GetNoise(x, y);
    x = cos(M_PI * degrees);
    y = sin(M_PI * degrees);
    return std::make_pair(x, y);
}

void Worm::Walk() {
    auto direction = getDirection(noise, x , y);
    inputVec[(x + direction.first) * (y + direction.second)] = 1.0;
}