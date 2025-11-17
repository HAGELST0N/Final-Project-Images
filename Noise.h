//
// Created by colin.skaarup on 11/10/2025.
//
#ifndef NOISE_H
#define NOISE_H
#include <vector>
#include "FastNoiseLite.h"
using namespace std;

int ourRound(float value, float divideLine);
vector<int> divideNoise(vector<float> inputVec, float divideLine);
vector<float> createNoise(int x_size, int y_size, int seed);
vector<int> mapNoise(vector<float> &inputVec);
pair<float, float> getDirection(FastNoiseLite &noise, float x, float y);
void Walk(FastNoiseLite &noise, vector<float> &inputVec, float x, float y);


#endif //NOISE_H
