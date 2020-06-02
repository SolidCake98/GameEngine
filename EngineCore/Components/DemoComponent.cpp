//
// Created by gleb on 02.06.2020.
//

#include "DemoComponent.h"

DemoComponent::DemoComponent(
        float startX,
        float startY,
        float startAngle,
        float startVx,
        float startVy,
        float startW,
        float distance)
{
    _startX = startX;
    _startY = startY;
    _startAngle = startAngle;
    _startVx = startVx;
    _startVy = startVy;
    _startW = startW;
    _distance = distance;
}

std::string DemoComponent::GetName() const { return "DemoComponent"; }
