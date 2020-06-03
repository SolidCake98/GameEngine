//
// Created by gleb on 02.06.2020.
//

#include "ControlSystem.h"

ControlSystem::ControlSystem(int width, int height)
{
    _width = width;
    _height = height;
}

ControlSystem::~ControlSystem()
{
    for (auto pair : _registered)
    {
        delete pair.second;
    }

    _registered.clear();
}

std::string ControlSystem::GetName() const { return "ControlSystem"; }

void ControlSystem::Update()
{
    bool top = Input::GetKeyDown(KEY_W);
    bool right = Input::GetKeyDown(KEY_D);
    bool bottom = Input::GetKeyDown(KEY_S);
    bool left = Input::GetKeyDown(KEY_A);

    for (auto pair : _registered)
    {
        PositionComponent& pc = pair.second->GetPosition();
        VelocityChangeComponent& vc = pair.second->GetVelocityChange();
        vc.SetX(0);
        vc.SetY(0);
        vc.SetW(0);

        if (pc.GetY() > 0 && top && !bottom) vc.SetY(-SPEED);
        if (pc.GetY() < _height && bottom && !top) vc.SetY(SPEED);
        if (pc.GetX() > 0 && left && !right) vc.SetX(-SPEED);
        if (pc.GetX() < _width && right && !left) vc.SetX(SPEED);

        vc.SetIsNeedChange(true);
    }
}

void ControlSystem::Register(Entity &entity)
{
    if (_registered.find(&entity) == _registered.end())
    {
        _registered[&entity] = new ControlNode(
                *(VelocityChangeComponent*)entity.Get("VelocityChangeComponent"),
                *(PositionComponent*)entity.Get("PositionComponent"));
    }
}

void ControlSystem::Unregister(Entity &entity)
{
    auto it = _registered.find(&entity);

    if (it != _registered.end())
    {
        delete it->second;
        _registered.erase(it);
    }
}




