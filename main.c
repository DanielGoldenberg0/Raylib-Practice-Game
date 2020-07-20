#include "raylib.h"

#define WIDTH 800
#define HEIGHT 450
#define FPS 60

const int numEnemies = 5;

 struct Player {
    Vector2 position;
    Color color;
    float radius;
    float speed;
};

struct Enemy {
    Vector2 position;
    Color color;
    float radius;
    float speed;
};

Vector2 RandomPositionOnScreen(int offset)
{
    int xPos = GetRandomValue(0 + offset, WIDTH - offset);
    int yPos = GetRandomValue(0 + offset, HEIGHT - offset);

    return (Vector2) {xPos, yPos};
}

void setup()
{
    InitWindow(WIDTH, HEIGHT, "Raylib Game");

    SetTargetFPS(FPS);
}

int main()
{
    setup();

    struct Player player;
    player.position = (Vector2) {(float) WIDTH/2, (float) HEIGHT/2};
    player.color = (Color) {20, 76, 155, 255};
    player.radius = 30;
    player.speed = 6;

    struct Enemy enemyList[numEnemies];

    for (int i = 0; i < numEnemies; i++)
    {
        struct Enemy *enemy = &enemyList[i];
        (*enemy).color = (Color) {229, 78, 48, 255};
        (*enemy).radius = GetRandomValue(20, 35);
        (*enemy).speed = GetRandomValue(10, 30);

        (*enemy).position = RandomPositionOnScreen((*enemy).radius);
    }

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

        for (int i = 0; i < numEnemies; i++)
        {
            DrawCircleV(enemyList[i].position, enemyList[i].radius, enemyList[i].color);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
