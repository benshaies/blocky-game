#include "../include/world.h"
#include <raylib.h>
#include <stdio.h>


Rectangle currentGroundRec(World world, Rectangle playerRec){
  int playerIndex = playerRec.x / TILE_SIZE;
  Rectangle returnRec;

  for(int y = 0; y < world.arr.rows; y++){
    if(world.arr.data[y][playerIndex] == 2){
      returnRec = (Rectangle){
        playerIndex * TILE_SIZE,
        y * TILE_SIZE,
        TILE_SIZE,
        TILE_SIZE,
      } ;
      break;
    }
  }
  
  return returnRec;

}


World  worldGenerate(int width, int hieght){
  
  World world;
  SB_IntArray2D_Init(&world.arr, hieght, width);

  for(int y = 0; y < world.arr.rows; y++){
    for(int x = 0; x < world.arr.cols; x++){
      if(y == 11){
        world.arr.data[y][x] = 2;
      }
      else if(y > 11){
        world.arr.data[y][x] = 1;
      }
    }
  }

  return world;


}

void worldDraw(World world){
  
  for(int y = 0; y < world.arr.rows; y++){
    for(int x = 0; x < world.arr.cols; x++){
      
      if(world.arr.data[y][x] < 1){
        continue;
      }
      
      Color color = BROWN;
      if(world.arr.data[y][x] == 2){
        color = DARKGREEN;
      }
      
      DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
      DrawRectangleLines(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);


    }
  }


}
  




