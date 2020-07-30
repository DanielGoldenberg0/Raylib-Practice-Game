#ifndef PRACTICEGAME_PLAYER_H
#define PRACTICEGAME_PLAYER_H

typedef struct Player
{
    Vector2 position;
    Color color;
    int radius;
    int speed;
    bool enabled;
} Player;

void PlayerStart(Player *player)
{
    player->position = GetCenterPoint();
    player->color = COLOR_WHITE;
    player->radius = 30;
    player->speed = 6;
}

void PlayerUpdate(Player *player)
{
    if (player->enabled)
    {
        if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && player->position.x < WIDTH - player->radius)
        {
            player->position.x += player->speed;
        }

        if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && player->position.x > player->radius)
        {
            player->position.x -= player->speed;
        }

        if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && player->position.y > player->radius)
        {
            player->position.y -= player->speed;
        }

        if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && player->position.y < HEIGHT - player->radius)
        {
            player->position.y += player->speed;
        }
    }
}

#endif
