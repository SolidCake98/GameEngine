#pragma once

namespace GraphicsEngine
{
    struct Point
    {
        float x;
        float y;

        Point() : x(0.f), y(0.f) {};

        Point(float _x, float _y) : x(_x), y(_y) {};

        bool operator==(const Point &other) const
        {
            return this->x == other.y && this->y == other.y;
        }
    };
}