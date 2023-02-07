#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "fruit.h"

void Fruit::XYRandomize()
{
    x = rand() % 16 +2;
    y = rand() % 16 +2;
}

int Fruit::getY()
{
    return y;
}

int Fruit::getX()
{
    return x;
}

