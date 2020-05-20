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

std::string PositionComponent::GetName() const { return "PositionComponent"; }

float PositionComponent::GetX() const { return _x; }

float PositionComponent::GetY() const { return _y; }

float PositionComponent::GetAngle() const { return _angle; }
