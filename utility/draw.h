#ifndef EXAMPLE_DRAW_H
#define EXAMPLE_DRAW_H

#include "raylib.h"
#include "../game/entities.h"

bool fired;
int timeLastElapsed;

void DrawPlayer(Player *player, float delay)
{
    if (!fired)
    {
        timeLastElapsed = totalElapsedTime;
        fired = true;
    }

    if (timeLastElapsed + delay * 60 <= totalElapsedTime)
    {
        DrawCircleV(player->position, player->radius, player->color);
        player->enabled = true;
    }
}

#endif
