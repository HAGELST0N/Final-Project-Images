//
// Created by patri on 10/30/2025.
// used Raylib for image generation https://github.com/gameguild-gg/raylib-cpm-cmake-boilerplate
#include "Noise.h"
#include "FastNoiseLite.h"
#include <cmath>
using namespace std;

int ourRound(float value, float divideLine);
vector<int> divideNoise(vector<float> inputVec, const float divideLine);

// generates vector of floats from -1 to 1 representing noise
// x_size, y_size: the size of the vector to generate
// seed: the seed used when generating noise
vector<float> createNoise(const int x_size, const int y_size, const int seed){
    // following modified from https://github.com/Auburn/FastNoiseLite/tree/master/Cpp#readme
    // the modifications allow it to be called as a function with parameters

    // initializing noise as perlin noise
    // Create and configure FastNoise object
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
    // modified to use seed parameter to set seed when called
    noise.SetSeed(seed);

    // Gather noise data
    // modified to use x_size and y_size
    vector<float> noiseData(x_size * y_size);
    int index = 0;

    for (int y = 0; y < y_size; y++)
    {
        for (int x = 0; x < x_size; x++)
        {
            noiseData[index++] = noise.GetNoise((float)x, (float)y);
        }
    }
    return noiseData;
}

vector<int> divideNoise(vector<float> inputVec, const float divideLine) {
    vector<int> outputVec(inputVec.size());
    for (int i = 0; i < inputVec.size(); i++) {
        outputVec[i] = ourRound(inputVec[i], divideLine);
    }
    return outputVec;
}

int ourRound(float value, float divideLine) {
    if (value >= divideLine)
        return 255;
    else
        return 0;
}

vector<int> mapNoise(vector<float>inputVec)
{
    vector<int>outputVec(inputVec.size());
    for (int i = 0;i < inputVec.size();i++)
    {
        outputVec[i] = int(round((inputVec[i]+1)*127.5));
    }
    return outputVec;
}
