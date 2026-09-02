#ifndef WORLD_H
#define WORLD_H
#include "../sblib/include/sblib.h"
#include <raylib.h>

// MACROS
#define TILE_SIZE 50

//Tile IDS
#define SKY 0
#define GRASS 1
#define DIRT 2

typedef struct {
  Rectangle recs[6];
  bool isCollisionRec[6];
} CollisionRecs;


typedef struct {
  int value;
} Tile;

typedef struct {
  Tile **tile;

  int rows;
  int cols;
} World;

CollisionRecs currentGroundRec(World world, Rectangle playerRec);

World worldGenerate(int width, int height);

void worldFree(World *world);

void worldDraw(World currentWorld);

#endif
