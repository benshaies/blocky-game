#ifndef WORLD_H
#define WORLD_H
#include "../sblib/include/sblib.h"
#include <raylib.h>

//MACROS
#define TILE_SIZE 50

typedef struct{
  SB_IntArray2D arr;
}World;

Rectangle currentGroundRec(World world, Rectangle playerRec);

World worldGenerate(int width, int hieght);

void worldDraw(World currentWorld);





#endif
