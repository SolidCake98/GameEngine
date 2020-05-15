//
// Created by gleb on 15.05.2020.
//

#include "Polygon.h"

Polygon::Polygon(Point points[], int length)
{
    InitPoints(points, length);
}

Polygon::Polygon(const Polygon &p)
{
    InitPoints(p._points, p._length);
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

void Polygon::InitPoints(Point* points, int length)
{
    _points = new Point[length];

    for (int i = 0; i < length; i++)
    {
        _points[i] = points[i];
    }

    _length = length;
}




