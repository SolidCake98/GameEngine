#pragma once

#include "Rigidbody.h"

namespace PEngine
{
    class Physics
    {
    public:
        // Описание:
        // метод ищет центр масс многоугольника (как центр масс системы точек (среднее арифметическое))
        // Возвращает:
        // точку, в которой находится центр масс
        static Point CenterOfMass(const Polygon& P);

        // Описание:
        // метод перемещает тела
        // Параметры:
        // rb - тело
        // dt - интервал времени с последнего фрейма
        static void UpdatePosition(Rigidbody& rb, float dt);

        // Описание:
        // метод вычисляет импульс упругого соударения
        static float CalculateImpulse(const Rigidbody& rb1, const Rigidbody& rb2, Point& cp, Point& n);

        // Описание:
        // метод применяет импульс к телу
        // Параметры:
        // rb - тело, к которому применяется импульс
        // cp - точка коллизии
        // n - нормаль коллизии
        // P - величина импульса (скаляр)
        static void ApplyImpulse(Rigidbody& rb, Point& cp, Point& n, float P);

    private:
        static constexpr float E = 0.5;
        static constexpr float MIN_V = 50;
    };
}
