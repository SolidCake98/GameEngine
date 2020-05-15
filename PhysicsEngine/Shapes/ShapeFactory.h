#pragma once

#include <stdexcept>
#include "Circle.h"
#include "ConvexPolygon.h"

namespace PEngine
{
    // Описание:
// класс, определяющий фабрику для создания фигур
    class ShapeFactory
    {
    public:
        // Описание:
        // Метод создает окружность
        // Параметры:
        // center - позиция центра окружности в локальных координатах фигуры
        // R - радиус фигуры
        // окружность
        static Circle* CreateCircle(Point center, float R);

        // Описание:
        // Метод создает окружность
        // Параметры:
        // x - позиция по оси абсцисс в локальных координатах фигуры
        // y - позиция по оси ординат в локальных координатах фигуры
        // окружность
        static Circle* CreateCircle(float x, float y, float R);

        // Описание:
        // Метод создает полигон
        // Параметры:
        // points - массив точек полигона в локальных координатах фигуры
        // len - длина массива точек
        // произвольный полигон
        static Polygon* CreatePolygon(Point points[], int len);

        // Описание:
        // Метод создает выпуклый полигон
        // Параметры:
        // points - массив точек полигона в локальных координатах фигуры
        // len - длина массива точек
        // Возвращает:
        // выпуклый полигон
        static ConvexPolygon* CreateConvexPolygon(Point points[], int len);

    private:
        // Описание:
        // метод преобразует массив точек в список вершин
        // Возвращает:
        // указатель на первую вершину
        static Vertex* ArrToVertexes(Point* points, int len);
    };
}