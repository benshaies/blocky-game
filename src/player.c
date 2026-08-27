#include "../include/player.h"
#include <raylib.h>
#include "stdio.h"

void playerInit(Player *player){
  player->pos = (Vector2 ) {500, 500};
  player->drawRec = (Rectangle){player->pos.x, player->pos.y, 50, 75};

  player->movementSpeed = 2.5f;
  player->onGround = false;
  player->isJumping = false;
}

void playerCollisions(Player *player, Rectangle currentRec){

  if(CheckCollisionRecs(player->drawRec, currentRec)){
      
    if(player->drawRec.y < currentRec.y){
      Rectangle collisionRec = GetCollisionRec(player->drawRec, currentRec);

      player->pos.y -= collisionRec.height;
      player->onGround = true;
      player->velocityY = 0;

    }

  }

}

void playerMovement(Player *player){
  if(IsKeyDown(KEY_D)){
    player->pos.x += player->movementSpeed;
  }
  else if(IsKeyDown(KEY_A)){
    player->pos.x -= player->movementSpeed;
  }

  if(IsKeyPressed(KEY_SPACE) && player->onGround){
    player->velocityY = -25; 
    player->onGround = false;

  }

  if(!player->onGround){
    player->velocityY += PLAYER_GRAVITY;
  }
  else{
  }



  player->pos.y += player->velocityY;

  printf("\n%f", player->velocityY);

  
 
}

void playerUpdate(Player *player){

   playerMovement(player);

  //Update Rectangle
  player->drawRec.x = player->pos.x;
  player->drawRec.y = player->pos.y;
  

}

void playerDraw(Player *player){
  DrawRectangleRec(player->drawRec, BLUE);
}

