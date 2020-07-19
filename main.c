#include "raylib.h"

#define WIDTH 800
#define HEIGHT 450
#define FPS 60

struct Player {
    Vector2 position;
    Color color;
    float radius;
    float speed;
} player;

struct Enemy {
    Vector2 position;
    Color color;
    float radius;
    float speed;
} enemy;

void setup()
{
    InitWindow(WIDTH, HEIGHT, "Raylib Game");

    SetTargetFPS(FPS);
}

int main()
{
    setup();

    player.position = (Vector2) {(float) WIDTH/2, (float) HEIGHT/2};
    player.color = (Color) {20, 76, 155, 255};
    player.radius = 30;
    player.speed = 6;

    while (!WindowShouldClose())
    {
        // Movement
        if (IsKeyDown(KEY_RIGHT) && player.position.x < WIDTH - player.radius)
        {
            player.position.x += player.speed;
        }

        if (IsKeyDown(KEY_LEFT) && player.position.x > 0 + player.radius)
        {
            player.position.x -= player.speed;
        }

        if (IsKeyDown(KEY_UP) && player.position.y > 0 + player.radius)
        {
            player.position.y -= player.speed;
        }

        if (IsKeyDown(KEY_DOWN) && player.position.y < HEIGHT - player.radius)
        {
            player.position.y += player.speed;
        }

        // Draw
        BeginDrawing();

        ClearBackground(BLACK);

        DrawCircleV(player.position, player.radius, player.color);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
