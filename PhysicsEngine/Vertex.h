#pragma once

#include "Point.h"

namespace PEngine
{
    // Описание:
    // класс, определяющий вершину полигона
    struct Vertex
    {
    public:
        Point position; // позиция вершины в локальных координатах фигуры
        Vertex* next = nullptr; // указатель на следующую вершину

        Vertex();
        Vertex(Point position);
        Vertex(Point position, Vertex* next);
        Vertex(float x, float y);
        Vertex(float x, float y, Vertex* next);
    };
}