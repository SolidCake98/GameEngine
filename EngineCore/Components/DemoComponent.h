//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_DEMOCOMPONENT_H
#define GAMEENGINE_DEMOCOMPONENT_H

#include "ComponentBase.h"

class DemoComponent : public ComponentBase
{
public:
    DemoComponent(
            float startX,
            float startY,
            float startAngle,
            float startVx,
            float startVy,
            float startW,
            float distance);

    std::string GetName() const override;

private:
    float _startX;
    float _startY;
    float _startAngle;
    float _startVx;
    float _startVy;
    float _startW;
    float _distance;
};


#endif //GAMEENGINE_DEMOCOMPONENT_H
