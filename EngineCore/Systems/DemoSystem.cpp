//
// Created by gleb on 02.06.2020.
//

#include "DemoSystem.h"

std::string DemoSystem::GetName() const { return "DemoSystem"; }

void DemoSystem::Update()
{
    for (auto pair : _registered)
    {
        DemoComponent& demo = pair.second->GetDemo();
        PositionComponent& position = pair.second->GetPosition();

        if (CalculateDistance(demo.GetStartX(), demo.GetStartY(), position.GetX(), position.GetY()) > demo.GetDistance())
        {
            VelocityChangeComponent& velocityChange = pair.second->GetVelocityChange();

            velocityChange.SetX(demo.GetStartVx());
            velocityChange.SetY(demo.GetStartVy());
            velocityChange.SetW(demo.GetStartW());
            velocityChange.SetIsNeedChange(true);

            TranslateComponent& translateComponent = pair.second->GetTranslate();

            translateComponent.SetX(demo.GetStartX());
            translateComponent.SetY(demo.GetStartY());
            translateComponent.SetAngle(demo.GetStartAngle());
            translateComponent.SetIsNeedTranslate(true);
        }
    }
}

void DemoSystem::Register(Entity &entity)
{
    if (_registered.find(&entity) == _registered.end())
    {
        _registered[&entity] = new DemoNode(
                *(DemoComponent*)entity.Get("DemoComponent"),
                *(PositionComponent*)entity.Get("PositionComponent"),
                *(VelocityChangeComponent*)entity.Get("VelocityChangeComponent"),
                *(TranslateComponent*)entity.Get("TranslateComponent"));
    }
}

void DemoSystem::Unregister(Entity &entity)
{
    auto it = _registered.find(&entity);

    if (it != _registered.end())
    {
        delete it->second;
        _registered.erase(it);
    }
}

float DemoSystem::CalculateDistance(float x1, float y1, float x2, float y2)
{
    return sqrt(sqr(x2 - x1) + sqr(y2 - y1));
}

float DemoSystem::sqr(float n)
{
    return n * n;
}
