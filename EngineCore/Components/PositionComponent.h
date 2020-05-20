//
// Created by gleb on 13.05.2020.
//

#ifndef GAMEENGINE_POSITIONCOMPONENT_H
#define GAMEENGINE_POSITIONCOMPONENT_H

#include "ComponentBase.h"

// Описание:
// компонент, отвечающий за положение тела в пространстве
class PositionComponent : public ComponentBase
{
public:
    PositionComponent(float x, float y, float angle);

    std::string GetName() const override;
    float GetX() const;
    float GetY() const;
    float GetAngle() const;

private:
    float _x; // позиция тела по оси абсцисс
    float _y; // позиция тела по оси ординат
    float _angle; // поворот тела
};

#endif //GAMEENGINE_POSITIONCOMPONENT_H
