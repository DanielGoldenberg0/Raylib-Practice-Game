#ifndef PRACTICEGAME_ENEMY_H
#define PRACTICEGAME_ENEMY_H

#include "../utility/transform.h"

typedef struct Enemy
{
    Vector2 position;
    Vector2 velocity;
    int radius;
    int maxSpeed;
} Enemy;

void EnemyStart(Enemy *enemy)
{
    enemy->position = GetRandomPosition(10);
    enemy->radius = GetRandomValue(20, 40);
    enemy->maxSpeed = GetRandomValue(2, 4);

    while (enemy->velocity.x == 0 && enemy->velocity.y == 0)
    {
        enemy->velocity = GetRandomVelocity(enemy->maxSpeed);
    }
}

void EnemyUpdate(Enemy *enemy)
{
    // Enemy Movement
    enemy->position.x += enemy->velocity.x;
    enemy->position.y -= enemy->velocity.y;

    // Enemy-Wall Collision
    if (enemy->position.x < enemy->radius || enemy->position.x > WIDTH - enemy->radius)
    {
        enemy->velocity.x = -enemy->velocity.x;
    }

    if (enemy->position.y < enemy->radius || enemy->position.y > HEIGHT - enemy->radius)
    {
        enemy->velocity.y = -enemy->velocity.y;
    }
}

#endif
