//
// Created by gleb on 27.05.2020.
//

#include "TestSystem.h"

std::string TestSystem::GetName() const { return "TestSystem"; }

void TestSystem::Update()
{
    _position->SetY(20.0f * sin(_timer.Elapsed(false)) + 100);
}

void TestSystem::Register(Entity &entity)
{
    _position = (PositionComponent*)entity.Get("PositionComponent");
}

void TestSystem::Unregister(Entity &entity)
{
    _position = nullptr;
}


