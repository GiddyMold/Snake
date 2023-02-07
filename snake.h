#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#pragma once

class Snake
{
    int direction;
    int length;
public:
    int x, y;
    Snake();
    int DirectionOutput();
    void DirectionInput(int);
    int LengthOutput();
    void LengthADD();
    int getY();
    int getX();
};



#endif //SNAKE_SNAKE_H
