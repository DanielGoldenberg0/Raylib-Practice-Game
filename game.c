#include "raylib.h"
#include "game.h"

#include "utility/collision.h"
#include "utility/draw.h"
#include "utility/time.h"

#include "game/player.h"
#include "game/enemy.h"

const int enemyCount = 8;

Player player;
Enemy enemyList[enemyCount];

bool gameOver;

void start()
{
    PlayerStart(&player);

    for (int i = 0; i < enemyCount; i++)
    {
        EnemyStart(&enemyList[i]);
    }
}

void update()
{
    totalElapsedTime++;

    PlayerUpdate(&player);

    // Enemy logic
    for (int i = 0; i < enemyCount; i++)
    {
        EnemyUpdate(&enemyList[i]);

        // Enemy-Player Collision
        if (PlayerToEnemyCollision(player, enemyList[i]) && GetTimeInSeconds() >= 1.5f)
        {
            gameOver = true;
        }
    }
}

void draw()
{
    ClearBackground(COLOR_BLACK);

    if (!gameOver)
    {
        DrawPlayer(&player, 1);

        for (int i = 0; i < enemyCount; i++)
        {
            DrawCircleV(enemyList[i].position, enemyList[i].radius, COLOR_RED);
        }
    }
    else
    {
        DrawText("Game Over", GetCenterPoint().x - 90, GetCenterPoint().y - 40, 40, COLOR_WHITE);
    }
}
