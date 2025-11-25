#include "image.h"
#include "Noise.h"
using namespace std;

void displayImg(Worm worm, const int imgWidth, const int imgHeight, int inputImgVec[][400], Color* pixels)
{
    for (auto v: worm.positions)
    {
        //inputImgVec[int(abs((v.first+100)*(v.second+100)))] = 255;
        inputImgVec[(int)v.first][(int)v.second] = 255;
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

vector<int> drawWormVec(const Worm* worm)
{
    std::list<std::pair<float, float>> adjustedWormPos;
    float minX = 100, maxX = -100, minY = 100, maxY = -100;
    for (auto v: worm->positions)
    {
        if (v.first < minX){minX = v.first;}
        if (v.first > maxX){maxX = v.first;}
        if (v.second < minY){minY = v.second;}
        if (v.second > maxY){maxY = v.second;}
    }
    for (auto v : worm->positions)
    {
        adjustedWormPos.push_back(std::make_pair(v.first-minX, v.second-minY));
    }
    int imgWidth = int(abs(maxX-minX))+50;
    int imgHeight = int(abs(maxY-minY))+50;
    int screenHeight = imgHeight+50;
    int screenWidth = imgWidth+200;

    InitWindow(screenWidth, screenHeight, "Perlin Worm");
    SetTargetFPS(5);

    Image img = GenImageColor(imgWidth, imgHeight, BLACK);
    ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    auto pixels = (Color*)img.data;
    Texture tex = LoadTextureFromImage(img);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // drawing logic goes here
        BeginDrawing();
        ClearBackground(PINK);
        DrawTexture(tex, 200, 25, WHITE);
        EndDrawing();
    }

    UnloadTexture(tex);

    CloseWindow();
}
