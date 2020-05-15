#pragma once

#include <math.h>
#include "Shape.h"
#include "Vertex.h"
#include "PolygonIterator.h"

namespace PEngine
{
    class Mathematics;
    class Physics;
    class Rigidbody;

    // Описание:
    // класс, описывающий полигон общего вида
    class Polygon : public Shape
    {
        friend class Mathematics;
        friend class Physics;
        friend class Rigidbody;
        friend class ShapeFactory;

    public:
        typedef PolygonIterator const_iterator;

        ~Polygon()
        {
            Vertex* current = _start;
            Vertex* prev;

            while (current != _start)
            {
                prev = current;
                current = current->next;
                delete prev;
            }

            delete _start;
        }

        std::string GetName() const override;
        Shape* Paralax(const Point& p, float angle) override;
        int GetPower() const;

        const_iterator begin() const;
        const_iterator end() const;

    protected:
        Vertex* _start;
        int _power;

        Polygon(Vertex* vertex);
        Vertex* GetStart() const;
        Point Rotate(const Point& p, float angle);
    };
}
