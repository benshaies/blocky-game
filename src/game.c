#include "../include/game.h"
#include <raylib.h>

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
RenderTexture target;
Vector2 mousePos = {0};

void gameInit() {
  ChangeDirectory(TextFormat("%s/..", GetApplicationDirectory()));

  InitWindow(GAME_WIDTH, GAME_HEIGHT, "blocky game");
  SetTargetFPS(60);
  target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);
}

void gameUpdate() {}

void gameDraw() {
  BeginTextureMode(target);

  ClearBackground(RAYWHITE);

  DrawRectangle(500, 500, 50, 50, BLUE);

  EndTextureMode();

  SB_GameResolution_Draw((Vector2){GAME_WIDTH, GAME_HEIGHT}, &target,
                         &mousePos);
}
