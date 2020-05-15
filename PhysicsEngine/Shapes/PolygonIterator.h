#pragma once

#include <iterator>
#include "Vertex.h"

namespace PEngine
{
    class Polygon;

    // Описание:
    // итератор для полигона (возможность просматривать вершины полигона без опаски что-нибудь сломать)
    class PolygonIterator : public std::iterator<std::input_iterator_tag, int>
    {
        friend class Polygon;

    public:
        bool operator!= (const PolygonIterator& other) const;
        bool operator== (const PolygonIterator& other) const;
        Point operator* () const;
        PolygonIterator& operator++ ();

    private:
        const Vertex* _start;
        Vertex* _current;

        PolygonIterator(Vertex* start);
    };
}
