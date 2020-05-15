#include "Circle.h"

using namespace PEngine;

Circle::Circle(Point center, float R)
{
	_center = center;
	_R = R;
}

Circle::Circle(float x, float y, float R)
{
	if (R <= 0) throw std::invalid_argument("R is less or equal then zero");
	_center = Point(x, y);
	_R = R;
}

std::string Circle::GetName() const
{
	return "Circle";
}

Shape* Circle::Paralax(const Point& p, float angle)
{
	return new Circle(_center + p, _R);
}

Point Circle::GetCenter() const { return _center; }

float Circle::GetR() const { return _R; }
