#include "raylib.h"
#include <math.h>
#include <stdio.h>
int main() {
  // window dimensions
  int width, height;
  printf("what do you want the width to be? \n");
  scanf("%d", &width);
  printf("what do you want the heigh to be?\n");
  scanf("%d", &height);

  int circle_x = width / 2, circle_y = height / 2;
  int circle_radius = 25;
  int leftCircle = circle_x - circle_radius;
  int rightCircle = circle_x + circle_radius;
  int topCircle = circle_y - circle_radius;
  int bottomCircle = circle_y + circle_radius;
  // axe attributes
  int axe_x = 400, axe_y = 0;
  int axe_length = 50;
  int direction = 10;
  int leftAxe = axe_x - axe_length;
  int rightAxe = axe_x + axe_length;
  int topAxe = axe_y - axe_length;
  int bottomAxe = axe_y + axe_length;
  // speed of the player
  int speed = sqrt((width * width) + (height * height)) / 100;
  InitWindow(width, height, "My own name");
  SetTargetFPS(60);
  bool collision_with_axe;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    if (collision_with_axe) {
      DrawText("GAME OVER", 200, 200, 20, RED);
      DrawText("Press R to restart", 200, 250, 20, RED);
      if (IsKeyPressed(KEY_R)) {
        circle_x = width / 2;
        circle_y = height / 2;
        axe_y = 0;
        collision_with_axe = false;
      }
    } else {
      // game logic begins
      // update the edges
      leftCircle = circle_x - circle_radius;
      rightCircle = circle_x + circle_radius;
      topCircle = circle_y - circle_radius;
      bottomCircle = circle_y + circle_radius;
      leftAxe = axe_x;
      rightAxe = axe_x + axe_length;
      topAxe = axe_y;
      bottomAxe = axe_y + axe_length;
      DrawCircle(circle_x, circle_y, circle_radius, BLUE);
      DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
      // move the axe
      axe_y += direction;
      if (axe_y > height || axe_y < (0 - 50)) {
        direction = -direction;
      }
      // player movment
      if (IsKeyDown(KEY_D) && (circle_x + circle_radius) < width) {
        circle_x += speed;
      }
      if (IsKeyDown(KEY_A) && (circle_x - circle_radius) >= 0) {
        circle_x -= speed;
      }
      if (IsKeyDown(KEY_W) && (circle_y - circle_radius) >= 0) {
        circle_y -= speed;
      }
      if (IsKeyDown(KEY_S) && (circle_y + circle_radius) < height) {
        circle_y += speed;
      }
      collision_with_axe = (bottomAxe >= topCircle && topAxe <= bottomCircle &&
                            leftAxe <= rightCircle && rightAxe >= leftCircle);
    }
    // game logic ends
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
