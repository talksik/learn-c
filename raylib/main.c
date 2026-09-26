#include <raylib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("hello world\n");

  InitWindow(500, 500, "Welcome");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawLine(0, 0, 500, 500, PURPLE);
    EndDrawing();
  }
  
  CloseWindow();

  return 0;
}
