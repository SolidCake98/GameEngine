//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_SHAPE_H
#define GAMEENGINE_SHAPE_H

#include <string>

// Описание:
// Базовый класс для фигур.
class Shape
{
public:
    // Описание:
    // Метод возвращает имя фигуры. Имя должно соответсвовать имени класса.
    // Возвращает:
    // Имя фигуры.
    virtual std::string GetName() const = 0;
};


#endif //GAMEENGINE_SHAPE_H
