#include "image.h"
using namespace std;

void displayImg(const int imgWidth, const int imgHeight, vector<int> inputImgVec)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Perlin Noise");

    SetTargetFPS(5);

    Image img = GenImageColor(imgHeight, imgHeight, WHITE);
    ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    auto pixels = (Color*)img.data;
    Texture tex = LoadTextureFromImage(img);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // your update logic goes here
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