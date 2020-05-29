//
// Created by gleb on 13.05.2020.
//

#include "BodyComponent.h"

BodyComponent::BodyComponent(float M, float I, bool isStatic)
{
    _M = M;
    _I = I;
    _isStatic = isStatic;
}

std::string BodyComponent::GetName() const { return "BodyComponent"; }

float BodyComponent::GetM() const { return _M; }

float BodyComponent::GetI() const { return _I; }

bool BodyComponent::GetIsStatic() const { return _isStatic; }


