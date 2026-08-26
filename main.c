#include "include/game.h"
#include "sblib/include/sblib.h"
#include <raylib.h>

void init() { gameInit(); }

int main() {

  init();

  while (!WindowShouldClose()) {

    gameDraw();
  }

  return 0;
}
