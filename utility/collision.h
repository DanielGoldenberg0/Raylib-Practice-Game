#ifndef PRACTICEGAME_COLLISION_H
#define PRACTICEGAME_COLLISION_H

#include "transform.h"

#include "../game/player.h"
#include "../game/enemy.h"

bool PlayerToEnemyCollision(Player player, Enemy enemy)
{
    return GetDistance(player.position, enemy.position) < player.radius + enemy.radius - 5;
}

#endif
