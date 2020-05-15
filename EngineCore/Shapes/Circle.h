//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_CIRCLE_H
#define GAMEENGINE_CIRCLE_H

#include "Point.h"

class Circle
{
public:
    Circle(Point center, float R);

    Point GetCenter();
    float GetR();

private:
    Point _center;
    float _R;
};


#endif //GAMEENGINE_CIRCLE_H
