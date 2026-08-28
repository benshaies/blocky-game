#include "../include/player.h"
#include "stdio.h"
#include <raylib.h>

void playerInit(Player *player) {
  player->rec = (Rectangle){500, 500, 50, 75};

  player->movementSpeed = 4.0f;
  player->onGround = false;
  player->isJumping = false;
}

void playerCollisions(Player *player, Rectangle currentRec) {

  if (CheckCollisionRecs(player->rec, currentRec)) {

    if (player->rec.y < currentRec.y) {
      
      player->rec.y = currentRec.y - player->rec.height;
      player->onGround = true;
      player->velocityY = 0;
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

void playerUpdate(Player *player, Rectangle currentRec) {

  playerMovement(player);


  playerCollisions(player, currentRec);

}

void playerDraw(Player *player) {
  DrawRectangleRec(player->rec, BLUE); 
}




