//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_POLYGON_H
#define GAMEENGINE_POLYGON_H

#include "Shape.h"
#include "Point.h"

class Polygon : public Shape
{
public:
    Polygon(Point points[], int length);
    Polygon(const Polygon& p);
    ~Polygon();

    int GetLength();
    const Point& operator[](int index);

private:
    Point* _points;
    int _length;

    void InitPoints(Point* points, int length);
};


#endif //GAMEENGINE_POLYGON_H
