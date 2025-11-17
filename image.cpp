#include "image.h"
#include "Noise.h"
using namespace std;

void displayImg(Worm worm, const int imgWidth, const int imgHeight, vector<int> inputImgVec, Color* pixels)
{
    for(int row = 0; row < imgHeight; row++)
    {
        for(int col = 0; col < imgWidth; col++)
        {
            worm.Walk();
            pixels[row * imgWidth + col] = (Color) {
                (uint8_t)inputImgVec[row * imgWidth + col],
                (uint8_t)inputImgVec[row * imgWidth + col],
                (uint8_t)inputImgVec[row * imgWidth + col],
                255
            };
        }
    }
}