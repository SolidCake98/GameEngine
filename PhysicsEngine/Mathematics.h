#pragma once

#include <math.h>
#include "Shapes/ConvexPolygon.h"
#include "Shapes/Circle.h"

#define EPS 1E-6

namespace PEngine
{
    class Mathematics
    {
    public:
        // Описание:
        // метод ищет квадрат числа
        static float SQR(float num);

        // Описание:
        // метод проверяет числа на равенство с поправкой на погрешность
        static bool EQU(float a, float b);

        // Описание:
        // метод ищет единичный вектор
        // Возвращает:
        // единичный вектор
        static Point UnitVector(const Point& vec);

        // Описание:
        // метод ищет расстояние между 2-мя точками
        // Возвращает:
        // расстояние между двумя точками
        static float Distance(const Point& p1, const Point& p2);

        // Описание:
        // метод определяет, "смотрит" ли направленный отрезок (a1, a2) на прямую, образованную точками (b1, b2)
        // Возвращает:
        // 0, если векторы (a1, a2) и (b1, b2) коллинеарны,
        // число > 0, если прямая (a1, a2) смотрит на прямую, образованную точками (b1, b2)
        // число < 0, если прямая (a1, a2) не смотрит на прямую, образованную точками (b1, b2)
        // Примечание:
        // знак определяется по знаку z компоненты векторного произведения
        static float AimTo(Point& a1, Point& a2, Point& b1, Point& b2);

        // Описание:
        // возвращает знак полуплоскости точки "c" относительно прямой (a, b)
        // Возвращает:
        // 0, если точка "c" лежит на прямой (a, b),
        // число > 0, если точка "c" находится в полуплоскости прямой (a, b),
        // число < 0, если точка "c" находится не в полуплоскости прямой (a, b)
        // Примечание:
        // использовано псевдоскалярное произведение
        static float HalfPlain(Point& a, Point& b, Point& c);

        // Описание:
        // метод ищет определитель матрицы 2x2
        // Возвращает:
        // определитель матрицы 2x2
        static float D2(float a11, float a12, float a21, float a22);

        // Описание:
        // метод ищет точку пересечения прямых, заданых двумя точками
        // точка "c" принемает значение точки пересечения
        // Возвращает:
        // true, если прямые пересекаются, false в противном случае
        // Примечание:
        // использован метод Краммера
        static bool LinesIntersection(Point& a1, Point& a2, Point& b1, Point& b2, Point& c);

        // Описание:
        // метод определяет, находится ли точка "c" в AABB отрезка (a, b)
        // Возвращает:
        // true, если точка лежит в AABB отрезка, иначе false
        static bool IsPointInLineAABB(Point& a, Point& b, Point& c);

        // Описание:
        // метод ищет точку пересечения двух отрезков
        // точка "c" принимает значение точки пересечения
        // Возвращает:
        // true, если отрезки пересекаются, false в противном случае
        static bool SegmentIntersection(Point& a1, Point& a2, Point& b1, Point& b2, Point& c);

        // Описание:
        // метод добавляет новую вершину в список вершин
        static void AddVertex(Vertex*& current, Point& p);

        // Описание:
        // метод (при необходимости) инициирует добавление текущей вершины в результирующий полигон
        // и "продвигает" указатель на текущую вершину к следующей вершине
        // Параметры:
        // v - указатель на "продвигаемую" вершину
        // current - указатель на текущую вершину результирующего полигона
        // needAdd - флаг, определяющий необходимость добавления вершины v в результирующий полигон
        static void Advance(Vertex*& v, Vertex*& current, bool needAdd);

        // Описание:
        // метод определяет, находится ли точка внутри выпуклого полигона
        // Возвращает:
        // true, если точка находится внутри выпуклого полигона, false в противном случае
        static bool IsDotInConvexPolygon(ConvexPolygon& P, Point& p);

        // Описание:
        // метод ищет полигон-пересечение 2-ух выпуклых полигонов
        // Возвращает:
        // полигон-пересечение, если таковой имеется, nullptr в противном случае
        // Примечание:
        // использован алгоритм О'Рурка
        static Polygon* ConvPolyConvPolyIntersection(ConvexPolygon& P, ConvexPolygon& Q);

        // Описание:
        // метод определяет, находится ли точка внутри окружности
        // Возвращает:
        // true, если точка находится внутри окружности, false в противном случае
        static bool IsDotInCircle(Circle& circle, Point& p);

        // Описание:
        // метод ищет точки пересечения прямой и окружности
        // Возвращает:
        // список точек пересечения прямой и окружности, если таковые имеются, в противном случае nullptr
        static Vertex* CircleLineIntersection(Circle& circle, Point& a, Point& b);

        // Описание:
        // метод ищет точки пересечения отрезка и окружности
        // Возвращает:
        // список точек пересечения отрезка и окружности, если таковые имеются, в противном случае nullptr
        static Vertex* CircleSegmentIntersection(Circle& circle, Point& a, Point& b);

        // Описание:
        // метод ищет точку сегмента окружности, наиболее удаленную от хорды (p1, p2)
        // Параметры:
        // circle - окружность
        // p1, p2 - точки на окружности, задающие хорду
        // Возвращает:
        // наиболее удаленную точку сегмента
        static Point SearchSectorHPoint(Circle& circle, Point& p1, Point& p2);

        // Описание:
        // метод ищет "грубое" пересечение окружности и выпуклого полигона
        // Возвращает:
        // полигон-пересечение окружности и выпуклого полигона (не обязательно ориентированый)
        static Polygon* CircleConvPolyIntersection(Circle& circle, ConvexPolygon& convPoly);

        // Описание:
        // метод ищет "грубое" пересечение выпуклого полигона и окружности
        // Возвращает:
        // полигон-пересечение окружности и выпуклого полигона (не обязательно ориентированый)
        static Polygon* ConvPolyCircleIntersection(ConvexPolygon& convPoly, Circle& circle);

        // Описание:
        // метод ищет "грубое" пересечение 2-ух окружностей
        // Возвращает:
        // полигон-пересечение окружностей (не обязательно ориентированый)
        static Polygon* CircleCircleIntersection(Circle& c1, Circle& c2);
    };
}
