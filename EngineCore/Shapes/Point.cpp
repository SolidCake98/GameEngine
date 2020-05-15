//
// Created by gleb on 15.05.2020.
//

#include "Point.h"

Point::Point(float x, float y)
{
    _x = x;
    _y = y;
}

float Point::GetX() { return _x; }
float Point::GetY() {return _y; }