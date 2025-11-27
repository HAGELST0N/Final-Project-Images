//
// Created by colin.skaarup on 11/17/2025.
//

#include "Worm.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

Worm::Worm() {
    srand(time(0));
    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
    noise.SetSeed(rand());
}

std::pair<float, float> Worm::getDirection(float x, float y) {
    float noiseAmt = noise.GetNoise(x, y);
    float degrees = (noiseAmt + 1) * 180;
    x = cos(degrees);
    y = sin(degrees);
    return std::make_pair(x, y);
}

void Worm::Walk()
{
    while (positions.size() < maxSegCount)
    {
        auto direction = getDirection(h_xPos, h_yPos);
        float new_xPos = h_xPos + direction.first*speed;
        float new_yPos = h_yPos + direction.second*speed;
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