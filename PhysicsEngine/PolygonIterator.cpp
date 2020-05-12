#include "PolygonIterator.h"

bool PolygonIterator::operator!= (const PolygonIterator& other) const
{
	return _current != other._current;
}

bool PolygonIterator::operator== (const PolygonIterator& other) const
{
	return _current == other._current;
}

Point PolygonIterator::operator* () const
{
	return _current->position;
}

PolygonIterator& PolygonIterator::operator++ ()
{
	if (_current->next == _start)
	{
		_current = nullptr;
	}
	else
	{
		_current = _current->next;
	}

	return *this;
}

PolygonIterator::PolygonIterator(Vertex* start)
{
	_start = start;
	_current = start;
}