#include <raylib.h>
#include <raygui.h>
#include <cstdint>
#include "Noise.h"
#include "image.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int imgWidth = 400;
    const int imgHeight = 400;

    InitWindow(screenWidth, screenHeight, "Pixel Manipulation");

    SetTargetFPS(1);

    Image img = GenImageColor(imgHeight, imgHeight, WHITE);
    ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    auto pixels = (Color*)img.data;
    Texture tex = LoadTextureFromImage(img);

    vector<float> initVec = createNoise(imgWidth, imgHeight, 1334);
    vector<int> finalVec = divideNoise(initVec, 0.5);
    vector<int> initImgVec = mapNoise(initVec);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        displayImg(imgWidth, imgHeight, initImgVec, pixels);
        // your update logic goes here
        // for(int row = 0; row < imgHeight; row++)
        // {
        //     for(int col = 0; col < imgWidth; col++)
        //     {
        //         pixels[row * imgWidth + col] = (Color) {
        //             (uint8_t)initImgVec[row * imgWidth + col],
        //             (uint8_t)initImgVec[row * imgWidth + col],
        //             (uint8_t)initImgVec[row * imgWidth + col],
        //             255
        //         };
        //     }
        // }
        UpdateTexture(tex, pixels);

        // drawing logic goes here
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(tex, 200, 25, WHITE);
        EndDrawing();
    }

    UnloadTexture(tex);

    CloseWindow();
    return 0;
}