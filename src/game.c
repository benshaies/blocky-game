#include "../include/game.h"
#include <raylib.h>

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
RenderTexture target;
Vector2 mousePos = {0};

//Player stuff
Player player;

//World stuff
Rectangle tempGroundRec = {0, 570, 1280, 150};

void gameInit() {
  ChangeDirectory(TextFormat("%s/..", GetApplicationDirectory()));

  InitWindow(GAME_WIDTH, GAME_HEIGHT, "blocky game");
  SetTargetFPS(60);
  target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);

  playerInit(&player);
}

void gameUpdate() {

  playerUpdate(&player, tempGroundRec);
}

void gameDraw() {
  BeginTextureMode(target);

  ClearBackground(RAYWHITE);

  DrawRectangleRec(tempGroundRec, BROWN);


  playerDraw(&player);
  


  EndTextureMode();

  SB_GameResolution_Draw((Vector2){GAME_WIDTH, GAME_HEIGHT}, &target,
                         &mousePos);
}
