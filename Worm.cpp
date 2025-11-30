//
// Created by colin.skaarup on 11/17/2025.
//

#include "Worm.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>

#include "raylib.h"

//from KungPhoo at https://stackoverflow.com/questions/24139428/check-if-element-is-in-the-list-contains
namespace std
{
    template<class _container,
        class _Ty> inline
        bool contains(_container _C, const _Ty& _Val)
    {return std::find(_C.begin(), _C.end(), _Val) != _C.end(); }
};

Worm::Worm() {
    srand(time(0));
    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
    noise.SetSeed(rand());
}

std::pair<float, float> Worm::getDirection(float x, float y) {
    float noiseAmt = noise.GetNoise(x, y);
    float degrees = noiseAmt * PI;
    std::pair<float, float> where;
    float dirX = cos(degrees);
    float dirY = sin(degrees);



    return std::make_pair(dirX, dirY);
}

void Worm::Walk()
{
    //generate a random point for worm to walk towards
    auto goal = getDirection(.01, .01);
    goal.first *=speed * 20;
    goal.second *=speed * 20;
    while (positions.size() < maxSegCount)
    {
        //
        float xDist = h_xPos-goal.first;
        float yDist = h_yPos-goal.second;
        float goalAngle = atan2(xDist, yDist);
        float xOffset = cos(goalAngle);
        float yOffset = sin(goalAngle);

        auto direction = getDirection(h_xPos, h_yPos);
        float new_xPos = h_xPos + (direction.first + (xOffset/2)) * speed;
        float new_yPos = h_yPos + (direction.second + (yOffset/2)) * speed;

        positions.push_back(std::make_pair(new_xPos, new_yPos));
        h_xPos = new_xPos;
        h_yPos = new_yPos;
    }
}
void Worm::print()
{
    for (auto v : positions)
        std::cout << v.first << " "<<v.second << "\n";

}