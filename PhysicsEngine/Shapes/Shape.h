#pragma once

#include <string>
#include "Point.h"

namespace PEngine
{
    // Опимание:
    // базовый класс для всех фигур
    class Shape
    {
    public:
        // Описание:
        // метод, возвращающий имя фигуры
        // Возвращает:
        // имя фигуры
        virtual std::string GetName() const = 0;

        // Описание:
        // метод возвращает копию фигуры, смещенную в указанную точку и повернутую на указанный угол
        // Параметры:
        // p - новая позиция фигуры
        // angle - новый поворот фигуры
        // Возвращает:
        // повернутую и смещенную фигуру
        virtual Shape* Paralax(const Point& p, float angle) = 0;
    };
}
