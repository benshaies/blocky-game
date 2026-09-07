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
      continue;
    }

    else{
      if(CheckCollisionRecs(player->rec, collision.rec[i])){
        Rectangle colRec = GetCollisionRec(player->rec, collision.rec[i]);

        if(colRec.width > colRec.height){
          player->rec.y -= colRec.height;
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

  if(IsKeyDown(KEY_S)){
    player->rec.y += player->movementSpeed;
  }
  else if(IsKeyDown(KEY_W)){
    player->rec.y -= player->movementSpeed;
  }

  //if (IsKeyPressed(KEY_SPACE) && player->onGround) {
  //  player->velocityY = -25;
   // player->onGround = false;
  //}

  //if (!player->onGround) {
   // player->velocityY += PLAYER_GRAVITY;
  //} else {
  //}

  //player->rec.y += player->velocityY;
}

void playerUpdate(Player *player, CollisionRecs collision) {

  playerMovement(player);

  playerCollisions(player, collision);
}

void playerDraw(Player *player) { DrawRectangleRec(player->rec, MAROON); }
