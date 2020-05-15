#include "ShapeFactory.h"

using namespace PEngine;

Circle* ShapeFactory::CreateCircle(Point center, float R)
{
	return new Circle(center, R);
}

Circle* ShapeFactory::CreateCircle(float x, float y, float R)
{
	return new Circle(x, y, R);
}

Polygon* ShapeFactory::CreatePolygon(Point points[], int len)
{
	return new Polygon(ArrToVertexes(points, len));
}

ConvexPolygon* ShapeFactory::CreateConvexPolygon(Point points[], int len)
{
	return new ConvexPolygon(ArrToVertexes(points, len));
}

Vertex* ShapeFactory::ArrToVertexes(Point* points, int len)
{
	if (len < 1) throw std::invalid_argument("Array length must be more or equal then 1");

	Vertex* start = new Vertex(points[0]);
	Vertex* v = start;

	for (int i = 1; i < len; i++)
	{
		v->next = new Vertex(points[i]);
		v = v->next;
	}

	v->next = start;
	return start;
}
