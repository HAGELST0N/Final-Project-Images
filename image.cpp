#include "image.h"
#include "Noise.h"
using namespace std;

void displayImg(Worm worm, const int imgWidth, const int imgHeight, vector<int> inputImgVec, Color* pixels)
{
    for (auto v: worm.positions)
    {
        inputImgVec[int(abs((v.first+100)*(v.second+100)))] = 255;
    }
    for(int row = 0; row < imgHeight; row++)
    {
        for(int col = 0; col < imgWidth; col++)
        {
            pixels[row * imgWidth + col] = (Color) {
                (uint8_t)inputImgVec[row * imgWidth + col],
                (uint8_t)inputImgVec[row * imgWidth + col],
                (uint8_t)inputImgVec[row * imgWidth + col],
                255
            };
        }
    }
}

vector<int> drawWormVec(Worm worm)
{
    float minX = 100, maxX = -100, minY = 100, maxY = -100;
    for (auto v: worm.positions)
    {
        if (v.first < minX){minX = v.first;}
        if (v.first > maxX){maxX = v.first;}
        if (v.second < minY){minY = v.second;}
        if (v.second > maxY){maxY = v.second;}
    }
    int rangeX = int(abs(maxX-minX))+50;
    int rangeY = int(abs(maxY-minY))+50;
    int screenHeight = rangeY+50;
    int screenWidth = rangeX+200;
}
