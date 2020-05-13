//
// Created by gleb on 13.05.2020.
//

#include "PositionComponent.h"

PositionComponent::PositionComponent(float x, float y, float angle)
{
    _x = x;
    _y = y;
    _angle = angle;
}

std::string PositionComponent::GetName() { return "PositionComponent"; }

float PositionComponent::GetX() { return _x; }

float PositionComponent::GetY() { return _y; }

float PositionComponent::GetAngle() { return _angle; }
