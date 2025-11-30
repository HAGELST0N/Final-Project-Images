#include "image.h"

#include <iostream>

#include "Noise.h"
using namespace std;

void displayImg(Worm worm, const int imgWidth, const int imgHeight, int inputImgVec[][400], Color* pixels)
{
    for (auto v: worm.positions)
    {
        //inputImgVec[int(abs((v.first+100)*(v.second+100)))] = 255;
        if (v.first >= 0 && v.second >= 0)
            inputImgVec[(int)v.first][(int)v.second] = 255;
        else if (v.first < 0 && v.second >= 0)
            inputImgVec[(int)(imgWidth + v.first)][(int)v.second] = 255;
        else if (v.first >= 0 && v.second < 0)
            inputImgVec[(int)v.first][(int)(imgHeight + v.second)] = 255;
        else
            inputImgVec[(int)(imgWidth + v.first)][(int)(imgHeight + v.second)] = 255;
    }
    for(int row = 0; row < imgHeight; row++)
    {
        for(int col = 0; col < imgWidth; col++)
        {
            pixels[row * imgWidth + col] = (Color) {
                // (uint8_t)inputImgVec[row * imgWidth + col],
                // (uint8_t)inputImgVec[row * imgWidth + col],
                // (uint8_t)inputImgVec[row * imgWidth + col],
                (uint8_t)inputImgVec[row][col],
                (uint8_t)inputImgVec[row][col],
                (uint8_t)inputImgVec[row][col],
                255
            };
        }
    }
}

void drawWormVec(const Worm* worm)
{
    float scalar = 5.0;
    float thicc = 1.0*scalar;
    float spacer = 5.0*scalar;
    Vector2 adjustedWormPos[worm->positions.size()];
    float minX = 100, maxX = -100, minY = 100, maxY = -100;
    for (auto v: worm->positions)
    {
        if (v.first < minX){minX = v.first;}
        if (v.first > maxX){maxX = v.first;}
        if (v.second < minY){minY = v.second;}
        if (v.second > maxY){maxY = v.second;}
    }
    float rangeX = abs(minX-maxX);
    float rangeY = abs(minY-maxY);
    std::cout << rangeX << " " << rangeY;
    int i=0;
    for (auto v : worm->positions)
    {
        adjustedWormPos[i] = {(v.first-minX+spacer)*scalar, (v.second-minY+spacer)*scalar};
        i++;
    }
    int imgWidth = int(rangeX+spacer)*scalar;
    int imgHeight = int(rangeY+spacer)*scalar;
    int screenHeight = imgHeight*1.1;
    int screenWidth = imgWidth*1.1;

    InitWindow(screenWidth, screenHeight, "Perlin Worm");
    SetTargetFPS(1);

    Image img = GenImageColor(imgWidth, imgHeight, PINK);
    ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    auto pixels = (Color*)img.data;
    Texture tex = LoadTextureFromImage(img);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // drawing logic goes here
        BeginDrawing();
        ClearBackground(BLACK);
        for (int j = 0; j < worm -> positions.size()-1; j++)
        {
            DrawSplineSegmentLinear(adjustedWormPos[j], adjustedWormPos[j+1], thicc, WHITE);
            DrawCircle(adjustedWormPos[j+1].x, adjustedWormPos[j+1].y, thicc/2, WHITE);
        }

        EndDrawing();
    }

    UnloadTexture(tex);

    CloseWindow();
}
