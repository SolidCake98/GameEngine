//
// Created by gleb on 15.05.2020.
//

#include "Circle.h"

Circle::Circle(Point center, float R)
{
    _center = center;
    _R = R;
}

Point Circle::GetCenter()
{
    return _center;
}

float Circle::GetR()
{
    return _R;
}


