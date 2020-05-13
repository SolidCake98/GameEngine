//
// Created by gleb on 13.05.2020.
//

#include "BodyComponent.h"

BodyComponent::BodyComponent(float M, float I)
{
    _M = M;
    _I = I;
}

std::string BodyComponent::GetName() { return "BodyComponent"; }

float BodyComponent::GetM() { return _M; }

float BodyComponent::GetI() { return _I; }


