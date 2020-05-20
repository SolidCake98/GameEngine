#include "Polygon.h"

using namespace PEngine;

Polygon::Polygon(Vertex* vertex)
{
	_start = vertex;
	_power = 1;

	for (Vertex* v = _start->next; v != _start; v = v->next)
	{
		_power++;
	}
}

Polygon::~Polygon()
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

std::string Polygon::GetName() const
{
	return "Polygon";
}

Shape* Polygon::Paralax(const Point& p, float angle)
{
	Vertex* newStart = new Vertex(Rotate(_start->position, angle) + p);
	Vertex* nv = newStart;

	for (Vertex* v = _start->next; v != _start; v = v->next)
	{
		nv->next = new Vertex(Rotate(v->position, angle) + p);
	}

	nv->next = newStart;
	return new Polygon(newStart);
}

int Polygon::GetPower() const { return _power; }

Polygon::const_iterator Polygon::begin() const
{
	return const_iterator(_start);
}

Polygon::const_iterator Polygon::end() const
{
	return const_iterator(nullptr);
}

Vertex* Polygon::GetStart() const
{
	return _start;
}

Point Polygon::Rotate(const Point& p, float angle)
{
	float sinA = sin(angle);
	float cosA = cos(angle);
	float x = p.x * cosA - p.y * sinA;
	float y = p.y * cosA + p.x * sinA;
	return Point(x, y);
}
