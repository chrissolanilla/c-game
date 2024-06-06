#include "raylib.h"
#include <stdio.h>
int main() {
  int width, height;
  printf("what do you want the width to be? \n");
  scanf("%d", &width);
  printf("what do you want the heigh to be?\n");
  scanf("%d", &height);
  InitWindow(width, height, "My own name");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RED);
    DrawText("Congrats! You created your first window!", 190, 200, 20,
             LIGHTGRAY);
    EndDrawing();
  }

  // CloseWindow(); --not really needed?

  return 0;
}
