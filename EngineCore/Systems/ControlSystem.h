//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_CONTROLSYSTEM_H
#define GAMEENGINE_CONTROLSYSTEM_H

#include <map>
#include "SystemBase.h"
#include "../Nodes/ControlNode.h"
#include "../../InputSystem/Input.h"

class ControlSystem : public SystemBase
{
public:
    ~ControlSystem();

    std::string GetName() const override;
    void Update() override;
    void Register(Entity& entity) override;
    void Unregister(Entity& entity) override;

private:
    const float SPEED = 100;
    std::map<Entity*, ControlNode*> _registered;

};


#endif //GAMEENGINE_CONTROLSYSTEM_H
