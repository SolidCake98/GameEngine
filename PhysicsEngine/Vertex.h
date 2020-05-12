#pragma once

#include "Point.h"

struct Vertex
{
public:
	Point position;
	Vertex* next = nullptr;

	Vertex();
	Vertex(Point position);
	Vertex(Point position, Vertex* next);
	Vertex(float x, float y);
	Vertex(float x, float y, Vertex* next);
};