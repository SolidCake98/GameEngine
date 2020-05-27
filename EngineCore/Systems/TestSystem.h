//
// Created by gleb on 27.05.2020.
//

#ifndef GAMEENGINE_TESTSYSTEM_H
#define GAMEENGINE_TESTSYSTEM_H

#include <cmath>
#include "SystemBase.h"
#include "../Components/PositionComponent.h"
#include "../../CTimer/CTimer.h"

class TestSystem : public SystemBase
{
public:
    std::string GetName() const override;
    void Update() override;
    void Register(Entity& entity) override;
    void Unregister(Entity& entity) override;

private:
    PositionComponent* _position;
    CTimer _timer;
};


#endif //GAMEENGINE_TESTSYSTEM_H
