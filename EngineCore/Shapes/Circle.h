//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_CIRCLE_H
#define GAMEENGINE_CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
    Circle(Point center, float R);

    std::string GetName() const override;
    Point GetCenter() const;
    float GetR() const;

private:
    Point _center;
    float _R;
};


#endif //GAMEENGINE_CIRCLE_H
