#include <raylib.h>
#include <raygui.h>
#include <cstdint>
#include <ctime>
#include <iostream>
#include "Noise.h"
#include "image.h"
#include "Worm.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 450;
    const int imgWidth = 400;
    const int imgHeight = 400;

    //InitWindow(screenWidth, screenHeight, "Pixel Manipulation");
    srand(time(0));
    SetTargetFPS(1);

    //Image img = GenImageColor(imgWidth, imgHeight, WHITE);
    //ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    //auto pixels = (Color*)img.data;
    //Texture tex = LoadTextureFromImage(img);

    Worm worm;
    worm.Walk();

    worm.print();
    drawWormVec(&worm);
    //float** initVec = createNoise(imgWidth, imgHeight, 1334);
    //vector<int> finalVec = divideNoise(initVec, 0.5);
    //vector<int> initImgVec = mapNoise(initVec);
    vector<int> blackImgVec(imgHeight*imgWidth,0);

    int blackImgArray[imgWidth][imgHeight];
    for (int i = 0; i < imgWidth; i++)
        for (int j = 0; j < imgHeight; j++)
            blackImgArray[i][j] = 0;


    // Main game loop
    // while (!WindowShouldClose())    // Detect window close button or ESC key
    // {
    //     displayImg(worm, imgWidth, imgHeight, blackImgArray, pixels);
    //     UpdateTexture(tex, pixels);
    //
    //     // drawing logic goes here
    //     BeginDrawing();
    //     ClearBackground(PINK);
    //     DrawTexture(tex, 200, 25, WHITE);
    //     EndDrawing();
    // }
    //
    // UnloadTexture(tex);
    //
    // CloseWindow();
    return 0;
}