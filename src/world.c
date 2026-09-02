#include "../include/world.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct{
  int x;
  int y;
}IVec2;

IVec2 checkIndex[6];

int collisionTilesList[]= {1, 2};


void worldVarInit(){
  
  checkIndex[0] = (IVec2){0, -1};
  checkIndex[1] = (IVec2){1, 0};
  checkIndex[2] = (IVec2){1, 1};
  checkIndex[3] = (IVec2){0, 2};
  checkIndex[4] = (IVec2){-1, 1};
  checkIndex[5] = (IVec2){-1, 0};

}

CollisionRecs currentGroundRec(World world, Rectangle playerRec) {
  int playerCol = (playerRec.x + playerRec.width/2) / TILE_SIZE; // col
  int playerRow = (playerRec.y) / TILE_SIZE; // row
  
  CollisionRecs rec;

  for(int checks = 0; checks < 6; checks++){
    // Checking all 6 positions for a collision tile
    int checkX = playerCol + checkIndex[checks].x;
    int checkY = playerRow + checkIndex[checks].y; 
    if(checkX < 0 || checkY < 0){
      continue;
    }

    int id = world.tile[checkY][checkX].value;

    // loop through collision tile list
    for (int i = 0; i < COLLISION_TILES_NUM; i++) {

      // check if current id matches
      if (id == collisionTilesList[i]) {
        
        // Create rectangle for that check 
        rec.rec[checks] = (Rectangle){checkX * TILE_SIZE, checkY * TILE_SIZE, TILE_SIZE, TILE_SIZE};
        rec.isEmpty[checks] = false;
        break;

      }
      else{
        rec.isEmpty[checks] = true;
      }
    }


  }
    return rec;

}

World worldGenerate(int width, int height) {

  World world;

  world.cols = width;
  world.rows = height;

  world.tile = malloc(sizeof(Tile *) * height);
  for (int i = 0; i < height; i++) {
    world.tile[i] = malloc(sizeof(Tile) * width);
  }

  // Temporary world generation
  for (int y = 0; y < world.rows; y++) {
    for (int x = 0; x < world.cols; x++) {

      if (y == 11) {
        world.tile[y][x].value = GRASS;
      } else if (y > 11) {
        world.tile[y][x].value = DIRT;
      } else {
        world.tile[y][x].value = EMPTY;
      }
    }
  }

  return world;
}

void worldFree(World *world) {

  for (int i = 0; i < world->rows; i++) {
    free(world->tile[i]);
    world->tile[i] = NULL;
  }

  free(world->tile);
  world->tile = NULL;

  world->rows = 0;
  world->cols = 0;
}

void worldDraw(World world) {
  for (int y = 0; y < world.rows; y++) {
    for (int x = 0; x < world.cols; x++) {
      Color tileColor;

      switch (world.tile[y][x].value) {
      case EMPTY:
        break;
      case DIRT:
        tileColor = BROWN;
        break;
      case GRASS:
        tileColor = DARKGREEN;
        break;
      }

      DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE,
                    tileColor);
    }
  }
}
