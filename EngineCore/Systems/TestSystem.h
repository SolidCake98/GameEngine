//
// Created by gleb on 27.05.2020.
//

#ifndef GAMEENGINE_TESTSYSTEM_H
#define GAMEENGINE_TESTSYSTEM_H

#include <cmath>
#include <map>
#include "SystemBase.h"
#include "../Components/PositionComponent.h"
#include "../Nodes/TestNode.h"
#include "../../CTimer/CTimer.h"

class TestSystem : public SystemBase
{
public:
    std::string GetName() const override;
    void Update() override;

private:
    void Register(Entity& entity) override;
    void Unregister(Entity& entity) override;

private:
    std::map<Entity*, TestNode*> _testPairs;
    CTimer _timer;
};


#endif //GAMEENGINE_TESTSYSTEM_H
