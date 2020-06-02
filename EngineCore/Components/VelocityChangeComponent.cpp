//
// Created by gleb on 02.06.2020.
//

#include "VelocityChangeComponent.h"

VelocityChangeComponent::VelocityChangeComponent(float x, float y, float W)
{
    _x = x;
    _y = y;
    _W = W;
    _isNeeChange = false;
}

std::string VelocityChangeComponent::GetName() const { return "VelocityChangeComponent"; }

float VelocityChangeComponent::GetX() const { return _x; }
void VelocityChangeComponent::SetX(float x) { _x = x; }

float VelocityChangeComponent::GetY() const { return _y; }
void VelocityChangeComponent::SetY(float y) { _y = y; }

float VelocityChangeComponent::GetW() const { return _W; }
void VelocityChangeComponent::SetW(float W) { _W = W; }

bool VelocityChangeComponent::GetIsNeedChange() const { return _isNeeChange; }
void VelocityChangeComponent::SetIsNeedChange(bool isNeedChange) { _isNeeChange = isNeedChange; }
