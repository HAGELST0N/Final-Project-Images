#include <raylib.h>
#include <raygui.h>
#include <cstdint>
#include "Noise.h"
#include "Worm.h"
using namespace std;

#ifndef HELLORAYLIB_IMAGE_H
#define HELLORAYLIB_IMAGE_H

void displayImg(Worm worm, int imgWidth, int imgHeight, int noise[][400], Color* pixels);
void drawWormVec(const Worm* worm);
#endif //HELLORAYLIB_IMAGE_H