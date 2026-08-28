#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_GRAVITY 1.25f

#include <raylib.h>
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


void playerUpdate(Player *player, Rectangle currentRec);


void playerDraw(Player *player);

#endif // !PLAYER_H
