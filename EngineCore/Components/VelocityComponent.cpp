//
// Created by gleb on 13.05.2020.
//

#include "VelocityComponent.h"

VelocityComponent::VelocityComponent(float x, float y, float w)
{
    _x = x;
    _y = y;
    _w = w;
}

std::string VelocityComponent::GetName() { return "VelocityComponent"; }

float VelocityComponent::GetX() { return _x; }

float VelocityComponent::GetY() { return _y; }

float VelocityComponent::GetW() { return _w; }
