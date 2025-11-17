//
// Created by colin.skaarup on 11/17/2025.
//

#include "Worm.h"
#include <cmath>

Worm::Worm() {
    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
    //noise.SetSeed(seed);
}

std::pair<float, float> Worm::getDirection(float x, float y) {
    float degrees = noise.GetNoise(x, y);
    x = cos(M_PI * degrees);
    y = sin(M_PI * degrees);
    return std::make_pair(x, y);
}

void Worm::Walk()
{
    auto direction = getDirection(h_xPos, h_yPos);
    float new_xPos = h_xPos + direction.first*speed;
    float new_yPos = h_yPos + direction.second*speed;
    positions.push_back(std::make_pair(new_xPos, new_yPos));
    h_xPos = new_xPos;
    h_yPos = new_yPos;
}