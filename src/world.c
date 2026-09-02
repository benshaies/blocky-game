#include "../include/world.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

CollisionRecs currentGroundRec(World world, Rectangle playerRec) {
  int playerIndex = playerRec.x / TILE_SIZE;
  CollisionRecs recs;

  

  return recs;
}

World worldGenerate(int width, int height) {

  World world;
  
  world.cols = width;
  world.rows = height;

  world.tile = malloc(sizeof(Tile *) * height);
  for(int i = 0; i < height; i++ ){
    world.tile[i] = malloc(sizeof(Tile) * width);
    
    
  }
  
  //Temporary world generation
  for(int y = 0; y < world.rows; y++){
    for(int x = 0; x < world.cols; x++){
      
      if(y == 11){
        world.tile[y][x].value = GRASS; 
      }
      else if(y > 11){
        world.tile[y][x].value = DIRT;
      }
      else{
        world.tile[y][x].value = SKY;
      }
    }
  }
    
  return world;
}

void worldFree(World *world){
 
  for(int i = 0; i < world->rows; i++){
    free(world->tile[i]);
    world->tile[i] = NULL;
  }

  free(world->tile);
  world->tile = NULL;

  world->rows = 0;
  world->cols = 0;
}

void worldDraw(World world) {
  for(int y = 0; y < world.rows; y++){
    for(int x = 0; x < world.cols; x++){
      Color tileColor;

      switch (world.tile[y][x].value){
        case SKY:
          tileColor = SKYBLUE;
          break;
        case DIRT:
          tileColor = BROWN;
          break;
        case GRASS:
          tileColor = DARKGREEN;
          break;
      }

      DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, tileColor);
    }
  }
}
