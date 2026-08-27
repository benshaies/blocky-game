#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_GRAVITY 2.0f


#include <raylib.h>
typedef struct{
  //Core
  Vector2 pos;
  Rectangle drawRec;
  
  //Movement
  float movementSpeed;
  float jumpStrength;
  
  float velocityY;
  bool onGround;
  bool isJumping;

}Player;

void playerInit(Player *player);

void playerCollisions(Player *player, Rectangle currentRec);

void playerUpdate(Player *player);


void playerDraw(Player *player);

#endif // !PLAYER_H
