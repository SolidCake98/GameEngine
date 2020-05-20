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

    std::string GetName() const override;
    int GetLength() const;
    const Point& operator[](int index) const;

private:
    Point* _points;
    int _length;

    void InitPoints(Point* points, int length);
};


#endif //GAMEENGINE_POLYGON_H
