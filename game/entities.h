#ifndef EXAMPLE_ENTITIES_H
#define EXAMPLE_ENTITIES_H

typedef struct Player {
    Vector2 position;
    Color color;
    int radius;
    int speed;
    bool enabled;
} Player;

typedef struct Enemy {
    Vector2 position;
    Vector2 velocity;
    int radius;
    int maxSpeed;
} Enemy;

#endif
