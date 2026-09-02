#ifndef PLAYER_H
#define PLAYER_H


#define PLAYER_GRAVITY 1.25f

#include <raylib.h>
#include "world.h"

typedef struct{
  //Core
  Rectangle rec;
  
  //Movement
  float movementSpeed;
  float jumpStrength;
  
  float velocityY;
  bool onGround;
  bool isJumping;

}Player;

void playerInit(Player *player);


void playerUpdate(Player *player, CollisionRecs collision);


void playerDraw(Player *player);

#endif // !PLAYER_H
