#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include "snake.h"


Snake::Snake()
{
    length=3;
    x=10;
    y=10;
}

int Snake::DirectionOutput()
{
    return direction;
}
void Snake::DirectionInput(int dirct)
{
    direction = dirct;
}
int Snake::LengthOutput()
{
    return length;
}
void Snake::LengthADD()
{
    length++;
}
int Snake::getY()
{
    return y;
}
int Snake::getX()
{
    return x;
}