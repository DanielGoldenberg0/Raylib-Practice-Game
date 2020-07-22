#include "raylib.h"
#include "colors.h"

#define WIDTH 800
#define HEIGHT 450
#define FPS 60

const int numEnemies = 10;

typedef struct Player {
    Vector2 position;
    Color color;
    float radius;
    float speed;
} Player;

typedef struct Enemy {
    Vector2 position;
    Vector2 velocity;
    Color color;
    float radius;
    float maxSpeed;
} Enemy;

Vector2 GetRandomPosition(int offset)
{
    int x = GetRandomValue(0 + offset, WIDTH - offset);
    int y = GetRandomValue(0 + offset, HEIGHT - offset);

    return (Vector2) {x, y};
}

void setup()
{
    InitWindow(WIDTH, HEIGHT, "Raylib Game");

    SetTargetFPS(FPS);
}

int main()
{
    setup();

    Player player;
    player.color = GAME_BLUE;
    player.radius = 30;
    player.speed = 6;
    player.position = (Vector2) {(float) WIDTH/2, (float) HEIGHT/2};

    Enemy enemyList[numEnemies];

    for (int i = 0; i < numEnemies; i++)
    {
        enemyList[i].color = GAME_RED;
        enemyList[i].radius = GetRandomValue(20, 35);
        enemyList[i].maxSpeed = 3;

        enemyList[i].velocity = (Vector2) {GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed), GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed)};
        while (enemyList[i].velocity.x == 0 && enemyList[i].velocity.y == 0)
        {
            enemyList[i].velocity = (Vector2) {GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed), GetRandomValue(-enemyList[i].maxSpeed, enemyList[i].maxSpeed)};
        }

        enemyList[i].position = GetRandomPosition(enemyList[i].radius);
    }

    while (!WindowShouldClose())
    {
        // Player Movement
        if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && player.position.x < WIDTH - player.radius)
        {
            player.position.x += player.speed;
        }

        if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && player.position.x > player.radius)
        {
            player.position.x -= player.speed;
        }

        if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && player.position.y > player.radius)
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
            enemyList[i].position.x += enemyList[i].velocity.x;
            enemyList[i].position.y -= enemyList[i].velocity.y;

            if (enemyList[i].position.x < enemyList[i].radius || enemyList[i].position.x > WIDTH - enemyList[i].radius)
            {
                enemyList[i].velocity.x = -enemyList[i].velocity.x;
            }

            if (enemyList[i].position.y < enemyList[i].radius || enemyList[i].position.y > HEIGHT - enemyList[i].radius)
            {
                enemyList[i].velocity.y = -enemyList[i].velocity.y;
            }
        }

        // Draw
        BeginDrawing();

        ClearBackground(GAME_BLACK);

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
