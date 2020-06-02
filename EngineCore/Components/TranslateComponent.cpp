//
// Created by gleb on 02.06.2020.
//

#include "TranslateComponent.h"

TranslateComponent::TranslateComponent(float x, float y, float angle)
{
    _x = x;
    _y = y;
    _angle = angle;
    _isNeedTranslate = false;
}

std::string TranslateComponent::GetName() const { return "TranslateComponent"; }

float TranslateComponent::GetX() const { return _x; }
void TranslateComponent::SetX(float x) { _x = x; }

float TranslateComponent::GetY() const { return _y; }
void TranslateComponent::SetY(float y) { _y = y; }

float TranslateComponent::GetAngle() const { return _angle; }
void TranslateComponent::SetAngle(float angle) { _angle = angle; }

bool TranslateComponent::GetIsNeedTranslate() const { return _isNeedTranslate; }
void TranslateComponent::SetIsNeedTranslate(bool isNeedTranslate) { _isNeedTranslate = isNeedTranslate; }
