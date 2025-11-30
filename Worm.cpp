//
// Created by colin.skaarup on 11/17/2025.
//

#include "Worm.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>

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
    float degrees = (noiseAmt + 1) * 35;
    float highestNoise = -2;
    std::pair<float, float> where;
    x = cos(degrees);
    y = sin(degrees);
    for (int aX = -1; aX <= 1; aX++)
        for (int aY = -1; aY <= 1; aY++) {
            float tempNoise = noise.GetNoise(x + (float)aX, y + (float)aY);
            if (aX == 0 && aY == 0)
                continue;
            if (tempNoise > highestNoise && !std::contains(positions, std::make_pair(x + aX, y + aY))) {
                highestNoise = tempNoise;
                where = std::make_pair(aX, aY);
            }
        }
    if ( rand() % 5 > 2)
        return where; //std::make_pair(x, y);
    return std::make_pair(where.first * -1, where.second);
}

void Worm::Walk()
{
    while (positions.size() < maxSegCount)
    {
        auto direction = getDirection(h_xPos, h_yPos);
        float new_xPos = h_xPos + direction.first * ( rand() % (int)speed);
        float new_yPos = h_yPos + direction.second * ( rand() % (int)speed);
        // for (int i = int(h_xPos); i < abs(int(new_xPos - h_xPos)); i++) {
        //     positions.push_back(std::make_pair(i, (new_yPos - h_yPos) * ((float)i / (new_yPos - h_yPos))/*(new_yPos - h_yPos) / (new_xPos - i) */));
        // }
        //push back all values between previous and new positions
        //adds or subtracts from h_Pos based on if distance is negative or positive
        if (new_xPos - h_xPos >= 0 && new_yPos - h_yPos >= 0) {
            for (int i = 1; i < abs(int(new_xPos - h_xPos)); i++) {
                positions.push_back(std::make_pair(h_xPos + ((new_xPos - h_xPos) * ((float)i / (new_xPos - h_xPos))), h_yPos + ((new_yPos - h_yPos) * ((float)i / (new_yPos - h_yPos)))));
            }
        }
        else if (new_xPos - h_xPos < 0 && new_yPos - h_yPos >= 0) {
            for (int i = 1; i < abs(int(new_xPos - h_xPos)); i++) {
                positions.push_back(std::make_pair(h_xPos - ((new_xPos - h_xPos) * ((float)i / (new_xPos - h_xPos))), h_yPos + ((new_yPos - h_yPos) * ((float)i / (new_yPos - h_yPos)))));
            }
        }
        else if (new_xPos - h_xPos >= 0 && new_yPos - h_yPos < 0) {
            for (int i = 1; i < abs(int(new_xPos - h_xPos)); i++) {
                positions.push_back(std::make_pair(h_xPos + ((new_xPos - h_xPos) * ((float)i / (new_xPos - h_xPos))), h_yPos - ((new_yPos - h_yPos) * ((float)i / (new_yPos - h_yPos)))));
            }
        }
        else {
            for (int i = 1; i < abs(int(new_xPos - h_xPos)); i++) {
                positions.push_back(std::make_pair(h_xPos - ((new_xPos - h_xPos) * ((float)i / (new_xPos - h_xPos))), h_yPos - ((new_yPos - h_yPos) * ((float)i / (new_yPos - h_yPos)))));
            }
        }
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