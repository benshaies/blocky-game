#include "../include/player.h"
#include "stdio.h"
#include <raylib.h>

void playerInit(Player *player) {
  player->rec = (Rectangle){500, 0, 50, 100};

  player->movementSpeed = 4.0f;
  player->onGround = false;
  player->isJumping = false;
}

void playerCollisions(Player *player, CollisionRecs collision) {

  for (int i = 0; i < 6; i++) {

    if(collision.isEmpty[i]){

      // Botoom tile check, if the bottom tile is empty that means the player is not on the ground
      if(i == 3){
        player->onGround = false;
      }
      continue;
    }

    else{
      if(CheckCollisionRecs(player->rec, collision.rec[i])){
        Rectangle colRec = GetCollisionRec(player->rec, collision.rec[i]);
        
        switch (i) {
          case 0: //Top collision 
            player->rec.y += colRec.height;
            break;
          case 1: // Right side 
            player->rec.x -= colRec.width;
           break;
          case 2: // Right Side
            player->rec.x -= colRec.width;
            break;
          case 3: // Bottom collision
            player->rec.y -= colRec.height;
            player->onGround = true;
            break;
          case 4: // Left side
            player->rec.x += colRec.width;
            break;
          case 5: // Left Side
            player->rec.x += colRec.width;
            break;
        
        }
      }
    }
  }
}

void playerMovement(Player *player) {
  if (IsKeyDown(KEY_D)) {
    player->rec.x += player->movementSpeed;
  } else if (IsKeyDown(KEY_A)) {
    player->rec.x -= player->movementSpeed;
  }

  // Jumping code
  if (IsKeyPressed(KEY_SPACE) && player->onGround) {
    player->velocityY = -25;
    player->onGround = false;
  }

  if (!player->onGround) {
    player->velocityY += PLAYER_GRAVITY;
  } 
  else{
    player->velocityY = 0;
  }

  player->rec.y += player->velocityY;
}

void playerUpdate(Player *player, CollisionRecs collision) {

  playerMovement(player);

  playerCollisions(player, collision);
}

void playerDraw(Player *player) { DrawRectangleRec(player->rec, MAROON); }
