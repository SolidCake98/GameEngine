//
// Created by gleb on 15.05.2020.
//

#include "Circle.h"

Circle::Circle(Point center, float R)
{
    _center = center;
    _R = R;
}

std::string Circle::GetName() const { return "Circle"; }

Point Circle::GetCenter() const
{
    return _center;
}

float Circle::GetR() const
{
    return _R;
}


