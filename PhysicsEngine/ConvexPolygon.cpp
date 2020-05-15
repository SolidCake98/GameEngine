#include "ConvexPolygon.h"

using namespace PEngine;

ConvexPolygon::ConvexPolygon(Vertex* start) : Polygon(start)
{
	if (_power > 2)
	{
		for (Vertex* v = _start; v != _start; v = v->next)
		{
			if (!CheckVertex(v))
			{
				throw std::invalid_argument("Polygon not convex");
			}
		}
	}
}

std::string ConvexPolygon::GetName() const
{
	return "ConvexPolygon";
}

bool ConvexPolygon::CheckVertex(Vertex* v)
{
	return (v->next->position.x - v->position.x) * (v->next->next->position.y - v->position.y)
		- (v->next->position.y - v->position.y) * (v->next->next->position.x - v->position.x) >= 0;
}
