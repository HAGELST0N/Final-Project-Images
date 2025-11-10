//
// Created by colin.skaarup on 11/10/2025.
//
#ifndef NOISE_H
#define NOISE_H
#include <vector>
using namespace std;

int ourRound(float value, float divideLine);
vector<int> divideNoise(vector<float> inputVec, const float divideLine);
vector<float> createNoise(const int x_size, const int y_size, const int seed);
vector<int> mapNoise(const vector<float> inputVec);


#endif //NOISE_H
