#include "raylib.h"

#define WIDTH 800
#define HEIGHT 450
#define FPS 60

const float speed = 4;

void setup()
{
    InitWindow(WIDTH, HEIGHT, "Raylib Game");

    SetTargetFPS(FPS);
}

int main()
{
    setup();

    Vector2 circlePos = {(float) WIDTH/2, (float) HEIGHT/2};

    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyDown(KEY_RIGHT))
        {
            circlePos.x += speed;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            circlePos.x -= speed;
        }

        if (IsKeyDown(KEY_UP))
        {
            circlePos.y -= speed;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            circlePos.y += speed;
        }

        // Draw
        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircleV(circlePos, 50, ORANGE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
