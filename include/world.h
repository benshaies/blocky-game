#ifndef WORLD_H
#define WORLD_H
#include "../sblib/include/sblib.h"
#include <raylib.h>

// MACROS
#define TILE_SIZE 50
#define COLLISION_TILES_NUM 2

//Tile IDS
#define EMPTY -1 
#define GRASS 1
#define DIRT 2





typedef struct {
  Rectangle rec[6];
  bool isEmpty[6];
} CollisionRecs;


typedef struct {
  int value;
} Tile;

typedef struct {
  Tile **tile;

  int rows;
  int cols;
} World;

void worldVarInit();

CollisionRecs currentGroundRec(World world, Rectangle playerRec);

World worldGenerate(int width, int height);

void worldFree(World *world);

void worldDraw(World currentWorld);

#endif
