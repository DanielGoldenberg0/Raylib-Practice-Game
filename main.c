#include "raylib.h"
#include "game.h"

#include "utility/init.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "Raylib Game");
    SetTargetFPS(FPS);

    start();

    while (!WindowShouldClose())
    {
        update();

        BeginDrawing();
        draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
