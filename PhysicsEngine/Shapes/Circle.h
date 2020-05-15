#pragma once

#include <stdexcept>
#include "Shape.h"
#include "Point.h"

namespace PEngine
{
    // Описание:
    // класс, описывающий окружность
    class Circle : public Shape
    {
        friend class Mathematics;
        friend class Physics;
        friend class Rigidbody;
        friend class ShapeFactory;

    public:
        std::string GetName() const override;
        Shape* Paralax(const Point& p, float angle) override;

        Point GetCenter() const;
        float GetR() const;

    protected:
        Circle(Point center, float R);
        Circle(float x, float y, float R);

    private:
        Point _center;
        float _R;
    };
}
