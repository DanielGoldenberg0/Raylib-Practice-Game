#ifndef EXAMPLE_COLOR_H
#define EXAMPLE_COLOR_H

#define GAME_BLACK (Color) {19, 19, 19, 255}
#define GAME_WHITE (Color) {236, 236, 236, 255}
#define GAME_RED (Color) {229, 78, 48, 255}

Color GetRandomColor()
{
    int r = GetRandomValue(0, 255);
    int g = GetRandomValue(0, 255);
    int b = GetRandomValue(0, 255);

    return (Color) {r, g, b, 255};
}

#endif
