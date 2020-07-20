#include "raylib.h"

#define WIDTH 800
#define HEIGHT 450
#define FPS 60

const int numEnemies = 10;

struct Player {
    Vector2 position;
    Color color;
    float radius;
    float speed;
};

struct Enemy {
    Vector2 position;
    Vector2 speed;
    Color color;
    float radius;
    float maxSpeed;
};

Vector2 GetRandomScreenPosition(int offset)
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
    player.color = (Color) {20, 76, 155, 255};
    player.radius = 30;
    player.speed = 6;
    player.position = (Vector2) {(float) WIDTH/2, (float) HEIGHT/2};

    struct Enemy enemyList[numEnemies];

    for (int i = 0; i < numEnemies; i++)
    {
        enemyList[i].color = (Color) {229, 78, 48, 255};
        enemyList[i].radius = GetRandomValue(20, 35);
        enemyList[i].maxSpeed = 3;

        enemyList[i].speed = (Vector2) {GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed), GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed)};
        while (enemyList[i].speed.x == 0 && enemyList[i].speed.y == 0)
        {
            enemyList[i].speed = (Vector2) {GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed), GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed)};
        }

        enemyList[i].position = GetRandomScreenPosition(enemyList[i].radius);
    }

    while (!WindowShouldClose())
    {
        // Player Movement
        if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && player.position.x < WIDTH - player.radius)
        {
            player.position.x += player.speed;
        }

        if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && player.position.x > 0 + player.radius)
        {
            player.position.x -= player.speed;
        }

        if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && player.position.y > 0 + player.radius)
        {
            player.position.y -= player.speed;
        }

        if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && player.position.y < HEIGHT - player.radius)
        {
            player.position.y += player.speed;
        }

        // Enemy Movement
        for (int i = 0; i < numEnemies; i++)
        {
            enemyList[i].position.x += enemyList[i].speed.x;
            enemyList[i].position.y -= enemyList[i].speed.y;
        }

        // Draw
        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < numEnemies; i++)
        {
            DrawCircleV(enemyList[i].position, enemyList[i].radius, enemyList[i].color);
        }

        DrawCircleV(player.position, player.radius, player.color);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
