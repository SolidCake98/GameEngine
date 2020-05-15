#pragma once

namespace PEngine
{
    // Описание:
    // структура, описывающая точку
    struct Point
    {
    public:
        float x;
        float y;

        Point();
        Point(float x, float y);

        friend Point operator + (const Point& p1, const Point& p2);
        friend Point operator - (const Point& p1, const Point& p2);
        friend Point operator / (const Point& p, float num);
        friend Point operator * (const Point& p, float num);

        Point& operator += (Point p);
        Point& operator -= (Point p);
        Point& operator *= (float num);
        Point& operator /= (float num);
    };

    Point operator + (const Point& p1, const Point& p2);
    Point operator - (const Point& p1, const Point& p2);
    Point operator / (const Point& p, float num);
    Point operator * (const Point& p, float num);
}

