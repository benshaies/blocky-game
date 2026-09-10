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
  Rectangle selectedTile;

} Player;

void playerInit(Player *player);

bool isTileWithinRange(Rectangle pRec,Vector2 mousePos);

void playerUpdate(Player *player, CollisionRecs collision);

void playerDraw(Player *player);

#endif // !PLAYER_H
