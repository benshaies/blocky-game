#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_GRAVITY 1.25f

#include "world.h"
#include <raylib.h>

typedef struct {
  // Core
  Rectangle rec;

  // Movement
  float movementSpeed;
  float jumpStrength;

  float velocityY;
  bool onGround;
  bool isJumping;

  // Interactions
  int tileRange;

} Player;

void playerInit(Player *player);

void playerUpdate(Player *player, CollisionRecs collision);

void playerDraw(Player *player);

#endif // !PLAYER_H
