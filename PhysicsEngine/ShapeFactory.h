#pragma once

#include <stdexcept>
#include "Circle.h"
#include "ConvexPolygon.h"

class ShapeFactory
{
public:
	static Circle* CreateCircle(Point center, float R);
	static Circle* CreateCircle(float x, float y, float R);
	static Polygon* CreatePolygon(Point points[], int len);
	static ConvexPolygon* CreateConvexPolygon(Point points[], int len);

private:
	static Vertex* ArrToVertexes(Point* points, int len);
};