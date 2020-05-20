//
// Created by gleb on 13.05.2020.
//

#include "VelocityComponent.h"

VelocityComponent::VelocityComponent(float x, float y, float W)
{
    _x = x;
    _y = y;
    _W = W;
}

std::string VelocityComponent::GetName() const { return "VelocityComponent"; }

float VelocityComponent::GetX() const { return _x; }
void VelocityComponent::SetX(float x) { _x = x; }

float VelocityComponent::GetY() const { return _y; }
void VelocityComponent::SetY(float y) { _y = y; }

float VelocityComponent::GetW() const { return _W; }
void VelocityComponent::SetW(float W) { _W = W; }


