#include "Vertex.h"

using namespace PEngine;

Vertex::Vertex()
{
	position = Point(0, 0);
}

Vertex::Vertex(Point position)
{
	this->position = position;
}

Vertex::Vertex(Point position, Vertex* next)
{
	this->position = position;
	this->next = next;
}

Vertex::Vertex(float x, float y)
{
	position = Point(x, y);
}

Vertex::Vertex(float x, float y, Vertex* next)
{
	position = Point(x, y);
	this->next = next;
}
