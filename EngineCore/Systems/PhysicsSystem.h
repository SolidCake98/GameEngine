//
// Created by gleb on 19.05.2020.
//

#ifndef GAMEENGINE_PHYSICSSYSTEM_H
#define GAMEENGINE_PHYSICSSYSTEM_H

#include <map>
#include "SystemBase.h"
#include "../../PhysicsEngine/PhysicsEngine.h"

class PhysicsSystem : public SystemBase
{
public:
    void Update() override;
    void Register(Entity entity) override;

private:

};


#endif //GAMEENGINE_PHYSICSSYSTEM_H
