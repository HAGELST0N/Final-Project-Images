#include <raylib.h>
#include <raygui.h>
#include <cstdint>
#include "Noise.h"
#include "Worm.h"
using namespace std;

#ifndef HELLORAYLIB_IMAGE_H
#define HELLORAYLIB_IMAGE_H

void displayImg(int imgWidth, int imgHeight, vector<int> inputImageVec, Color* pixels);
void drawWormVec(const Worm* worm);
#endif //HELLORAYLIB_IMAGE_H