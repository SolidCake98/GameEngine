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

float DemoComponent::GetStartX() const { return _startX; }
void DemoComponent::SetStartX(float startX) { _startX = _startX; }

float DemoComponent::GetStartY() const { return _startY; }
void DemoComponent::SetStartY(float startY) { _startY = _startY; }

float DemoComponent::GetStartAngle() const { return _startAngle; }
void DemoComponent::SetStartAngle(float startAngle) { _startAngle = startAngle; }

float DemoComponent::GetStartVx() const { return _startVx; }
void DemoComponent::SetStartVx(float startVx) { _startVx = startVx; }

float DemoComponent::GetStartVy() const { return _startVy; }
void DemoComponent::SetStartVy(float startVy) { _startVy = startVy; }

float DemoComponent::GetStartW() const { return _startW; }
void DemoComponent::SetStartW(float startW) { _startW = startW; }

float DemoComponent::GetDistance() const { return _distance; }
void DemoComponent::SetDistance(float distance) { _distance = distance; }
