#include "../include/game.h"
#include "../include/world.h"
#include "stdio.h"
#include <raylib.h>

#define GAME_WIDTH 1300
#define GAME_HEIGHT 750
RenderTexture target;
Vector2 mousePos = {0};

// Player stuff
Player player;
CollisionRecs pCollisionRecs;

// World stuff
Color skyColor = {102, 191, 255, 255};
Rectangle tempGroundRec = {0, 570, 1280, 150};
World currentWorld;

// Camera
Camera2D cam;
Vector2 worldMouse;

void gameInit() {
  ChangeDirectory(TextFormat("%s/..", GetApplicationDirectory()));

  InitWindow(GAME_WIDTH, GAME_HEIGHT, "blocky game");
  SetTargetFPS(60);
  target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);

  worldVarInit();
  playerInit(&player);

  cam.offset = (Vector2){GAME_WIDTH/2, GAME_HEIGHT/2};
  cam.target.x = player.rec.x;
  cam.zoom = 1.0f;

  currentWorld = worldGenerate(50, 50);
}

void gameUpdate() {

  Rectangle groundRec = (Rectangle){0, 600, 2000, 100};

  cam.target = (Vector2){player.rec.x, player.rec.y};
  worldMouse = GetScreenToWorld2D(mousePos, cam);

  pCollisionRecs = getCurrentCollisionRecs(currentWorld, player.rec);

  playerUpdate(&player, pCollisionRecs);

  if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
    
    worldDeleteBlock(&currentWorld, worldMouse);
  } 
}

void gameDraw() {
  

  BeginTextureMode(target);

  ClearBackground(skyColor);

  BeginMode2D(cam);

  worldDraw(currentWorld);

  playerDraw(&player);

  EndMode2D();

  
  EndTextureMode();


  SB_GameResolution_Draw((Vector2){GAME_WIDTH, GAME_HEIGHT}, &target,
                         &mousePos);
}
