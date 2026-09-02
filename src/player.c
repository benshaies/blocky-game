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
  
  for(int i = 0; i < 6; i++){
    
    if(!collision.isEmpty[i] && CheckCollisionRecs(player->rec, collision.rec[i])){
      
      Rectangle overlap = GetCollisionRec(player->rec, collision.rec[i]);

      player->rec.x += overlap.width;
      player->rec.y += overlap.height;


    }
  }



}

void playerMovement(Player *player) {
  if (IsKeyDown(KEY_D)) {
    player->rec.x += player->movementSpeed;
  } else if (IsKeyDown(KEY_A)) {
    player->rec.x -= player->movementSpeed;
  }

  if (IsKeyPressed(KEY_SPACE) && player->onGround) {
    player->velocityY = -25;
    player->onGround = false;
  }

  if (!player->onGround) {
    player->velocityY += PLAYER_GRAVITY;
  } else {
  }

  player->rec.y += player->velocityY;
}

void playerUpdate(Player *player, CollisionRecs collision) {

  playerMovement(player);

  playerCollisions(player, collision);
}

void playerDraw(Player *player) { DrawRectangleRec(player->rec, MAROON); }
