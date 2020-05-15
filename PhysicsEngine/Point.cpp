#include "Point.h"

using namespace PEngine;

Point::Point()
{
	x = y = 0;
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point& Point::operator += (Point p)
{
	x += p.x;
	y += p.y;
	return *this;
}

Point& Point::operator -= (Point p)
{
	x -= p.x;
	y -= p.y;
	return *this;
}

Point& Point::operator *= (float num)
{
	x *= num;
	y *= num;
	return *this;
}

Point& Point::operator /= (float num)
{
	x /= num;
	y /= num;
	return *this;
}

namespace PEngine
{
    Point operator + (const Point& p1, const Point& p2)
    {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

    Point operator - (const Point& p1, const Point& p2)
    {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }

    Point operator / (const Point& p, float num)
    {
        return Point(p.x / num, p.y / num);
    }

    Point operator * (const Point& p, float num)
    {
        return Point(p.x * num, p.y * num);
    }
}