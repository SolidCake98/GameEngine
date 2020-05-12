#pragma once

#include <string>
#include "Point.h"

class Shape
{
public:	
	virtual std::string GetName() const = 0;
	virtual Shape* Paralax(const Point& p, float angle) = 0;
};