//
// Created by gleb on 27.05.2020.
//

#include "TestSystem.h"

std::string TestSystem::GetName() const { return "TestSystem"; }

void TestSystem::Update()
{
    for (auto pair : _testPairs)
    {
        PositionComponent& start = pair.second->GetStartPosition();
        PositionComponent& position = pair.second->GetPosition();

        position.SetX(start.GetX() + 20.f * sin(_timer.Elapsed(false)));
        position.SetY(start.GetY() + 20.f * sin(_timer.Elapsed(false)));
        position.SetAngle(20.f * sin(_timer.Elapsed(false)));
    }
}

void TestSystem::Register(Entity &entity)
{
    if (_testPairs.find(&entity) == _testPairs.end())
    {
        _testPairs[&entity] = new TestNode(*(PositionComponent*)entity.Get("PositionComponent"));
    }
}

void TestSystem::Unregister(Entity &entity)
{
    auto it = _testPairs.find(&entity);

    if (it != _testPairs.end())
    {
        delete it->second;
        _testPairs.erase(it);
    }
}


