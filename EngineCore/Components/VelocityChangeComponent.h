//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_VELOCITYCHANGECOMPONENT_H
#define GAMEENGINE_VELOCITYCHANGECOMPONENT_H

#include "ComponentBase.h"

class VelocityChangeComponent : public ComponentBase
{
public:
    VelocityChangeComponent(float x = 0, float y = 0, float W = 0);

    std::string GetName() const override;
    float GetX() const;
    void SetX(float x);
    float GetY() const;
    void SetY(float y);
    float GetW() const;
    void SetW(float W);
    bool GetIsNeedChange() const;
    void SetIsNeedChange(bool isNeedChange);

private:
    float _x; // скорость по оси абсцисс
    float _y; // скорость по оси ординат
    float _W; // угловая скорость
    bool _isNeeChange;
};


#endif //GAMEENGINE_VELOCITYCHANGECOMPONENT_H
