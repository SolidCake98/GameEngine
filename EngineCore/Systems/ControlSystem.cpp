//
// Created by gleb on 02.06.2020.
//

#include "ControlSystem.h"

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
        VelocityChangeComponent& vc = pair.second->GetVelocityChange();
        vc.SetY(top ? -SPEED : bottom ? SPEED : 0);
        vc.SetX(left ? -SPEED : right ? SPEED : 0);
        vc.SetW(0);
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


