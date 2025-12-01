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
    InitWindow(screenWidth, screenHeight, "Alternate Worm");

    SetTargetFPS(1);

    Image img = GenImageColor(imgHeight, imgHeight, WHITE);
    ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    auto pixels = (Color*)img.data;
    Texture tex = LoadTextureFromImage(img);

    vector<float> initVec = createNoise(imgWidth, imgHeight, rand());
    vector<int> finalVec = divideNoise(initVec, 0.1);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        displayImg(imgWidth, imgHeight, finalVec, pixels);
        UpdateTexture(tex, pixels);

        // drawing logic goes here
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(tex, 200, 25, WHITE);
        EndDrawing();
    }

    UnloadTexture(tex);

    CloseWindow();
}