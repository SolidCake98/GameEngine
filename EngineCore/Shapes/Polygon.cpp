//
// Created by gleb on 15.05.2020.
//

#include "Polygon.h"

Polygon::Polygon(Point* points, int length)
{
    _points = points;
    _length = length;
}

Polygon::~Polygon()
{
    delete _points;
}

int Polygon::GetLength() { return _length; }

const Point &Polygon::operator[](int index)
{
    return _points[index];
}


