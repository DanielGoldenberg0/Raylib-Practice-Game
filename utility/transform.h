#ifndef EXAMPLE_TRANSFORM_H
#define EXAMPLE_TRANSFORM_H

#include <math.h>
#include "general.h"

Vector2 GetCenterPoint()
{
    return (Vector2) {(float) WIDTH/2, (float) HEIGHT/2};
}

Vector2 GetRandomPosition(int offset)
{
    int x = GetRandomValue(0 + offset, WIDTH - offset);
    int y = GetRandomValue(0 + offset, HEIGHT - offset);

    return (Vector2) {x, y};
}

Vector2 GetRandomVelocity(int maxSpeed)
{
    return (Vector2) {GetRandomValue(-maxSpeed, maxSpeed), GetRandomValue(-maxSpeed, maxSpeed)};
}

float GetDistance(Vector2 object1, Vector2 object2)
{
    int x = object1.x - object2.x;
    int y = object1.y - object2.y;

    return sqrt(pow(x, 2) + pow(y, 2));
}

#endif
