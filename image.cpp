#include "image.h"
#include "Noise.h"
using namespace std;

void displayImg(Worm worm, const int imgWidth, const int imgHeight, vector<int> inputImgVec, Color* pixels)
{
    for (auto v: worm.positions)
    {
        inputImgVec[int(abs(v.first+100*v.second+100))] = 255;
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