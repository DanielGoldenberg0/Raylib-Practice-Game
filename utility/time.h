#ifndef EXAMPLE_TIME_H
#define EXAMPLE_TIME_H

#include "general.h"

int totalElapsedTime = 0;

double GetTimeInSeconds()
{
    return totalElapsedTime / FPS;
}

#endif
