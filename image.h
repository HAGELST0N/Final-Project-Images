#include <raylib.h>
#include <raygui.h>
#include <cstdint>
#include "Noise.h"
using namespace std;

#ifndef HELLORAYLIB_IMAGE_H
#define HELLORAYLIB_IMAGE_H

void displayImg(int imgWidth, int imgHeight, vector<int> noise, Color* pixels);

#endif //HELLORAYLIB_IMAGE_H