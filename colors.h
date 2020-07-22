#ifndef EXAMPLE_COLORS_H
#define EXAMPLE_COLORS_H

#define GAME_BLACK (Color) {13, 13, 13, 255}
#define GAME_BLUE (Color) {36, 103, 181, 255}
#define GAME_RED (Color) {229, 78, 48, 255}
#define GAME_GREEN (Color) {119, 181, 45, 255}

Color GetRandomColor()
{
    int r = GetRandomValue(0, 255);
    int g = GetRandomValue(0, 255);
    int b = GetRandomValue(0, 255);

    return (Color) {r, g, b, 255};
}

#endif
