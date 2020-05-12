#pragma once

#include <stdexcept>
#include "Polygon.h"

class ConvexPolygon : public Polygon
{
	friend class ShapeFactory;

public:	
	std::string GetName() const override;

private:
	ConvexPolygon(Vertex* start);
	bool CheckVertex(Vertex* v);
};