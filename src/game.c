#include "../include/game.h"
#include <raylib.h>
#include "../include/world.h"
#include "stdio.h"

#define GAME_WIDTH 1300
#define GAME_HEIGHT 750
RenderTexture target;
Vector2 mousePos = {0};

//Player stuff
Player player;

//World stuff
Color skyColor = {102, 191, 255, 255};
Rectangle tempGroundRec = {0, 570, 1280, 150};
World tempWorld;

void gameInit() {
  ChangeDirectory(TextFormat("%s/..", GetApplicationDirectory()));

  InitWindow(GAME_WIDTH, GAME_HEIGHT, "blocky game");
  SetTargetFPS(60);
  target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);

  playerInit(&player);

  tempWorld = worldGenerate(GAME_WIDTH/TILE_SIZE, GAME_HEIGHT/TILE_SIZE);

}

  

void gameUpdate() {
  
  Rectangle groundRec;  

  //playerUpdate(&player, groundRec);

  

}

void gameDraw() {
  BeginTextureMode(target);
  

  ClearBackground(skyColor);

  worldDraw(tempWorld); 

  playerDraw(&player);


  EndTextureMode();

  SB_GameResolution_Draw((Vector2){GAME_WIDTH, GAME_HEIGHT}, &target,
                         &mousePos);
}
