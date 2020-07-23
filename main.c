#include "raylib.h"
#include "utility/general.h"
#include "utility/transform.h"
#include "utility/color.h"

const int numEnemies = 8;

typedef struct Player {
    Vector2 position;
    int radius;
    int speed;
} Player;

typedef struct Enemy {
    Vector2 position;
    Vector2 velocity;
    int radius;
    int maxSpeed;
} Enemy;

Player player;
Enemy enemyList[numEnemies];

void setup()
{
    InitWindow(WIDTH, HEIGHT, "Raylib Game");

    SetTargetFPS(FPS);
}

void start()
{
    player.radius = 30;
    player.speed = 6;
    player.position = GetCenterPoint();

    for (int i = 0; i < numEnemies; i++)
    {
        enemyList[i].radius = GetRandomValue(20, 35);
        enemyList[i].maxSpeed = 3;

        while (enemyList[i].velocity.x == 0 && enemyList[i].velocity.y == 0)
        {
            enemyList[i].velocity = GetRandomVelocity(enemyList[i].maxSpeed);
        }

        enemyList[i].position = GetRandomPosition(enemyList[i].radius);
    }
}

void update()
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

    // Enemy logic
    for (int i = 0; i < numEnemies; i++)
    {
        // Enemy Movement
        enemyList[i].position.x += enemyList[i].velocity.x;
        enemyList[i].position.y -= enemyList[i].velocity.y;

        // Enemy-Wall Collision
        if (enemyList[i].position.x < enemyList[i].radius || enemyList[i].position.x > WIDTH - enemyList[i].radius)
        {
            enemyList[i].velocity.x = -enemyList[i].velocity.x;
        }

        if (enemyList[i].position.y < enemyList[i].radius || enemyList[i].position.y > HEIGHT - enemyList[i].radius)
        {
            enemyList[i].velocity.y = -enemyList[i].velocity.y;
        }

        // Enemy-Player Collision
        if (GetDistance(player.position, enemyList[i].position) < player.radius + enemyList[i].radius)
        {
            enemyList[i].velocity = (Vector2) {-enemyList[i].velocity.x, -enemyList[i].velocity.y};
        }
    }
}

void draw()
{
    ClearBackground(GAME_BLACK);

    DrawCircleV(player.position, player.radius, GAME_WHITE);

    for (int i = 0; i < numEnemies; i++)
    {
        DrawCircleV(enemyList[i].position, enemyList[i].radius, GAME_RED);
    }
}

int main()
{
    setup();
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
