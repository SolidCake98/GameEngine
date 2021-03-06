//
// Created by gleb on 13.05.2020.
//

#ifndef GAMEENGINE_VELOCITYCOMPONENT_H
#define GAMEENGINE_VELOCITYCOMPONENT_H

#include "ComponentBase.h"

class VelocityComponent : public ComponentBase
{
public:
    VelocityComponent(float x, float y, float W);

    std::string GetName() const override;
    float GetX() const;
    void SetX(float x);
    float GetY() const;
    void SetY(float y);
    float GetW() const;
    void SetW(float W);

private:
    float _x; // скорость по оси абсцисс
    float _y; // скорость по оси ординат
    float _W; // угловая скорость
};


#endif //GAMEENGINE_VELOCITYCOMPONENT_H
