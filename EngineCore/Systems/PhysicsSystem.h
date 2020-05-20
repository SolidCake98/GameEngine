//
// Created by gleb on 19.05.2020.
//

#ifndef GAMEENGINE_PHYSICSSYSTEM_H
#define GAMEENGINE_PHYSICSSYSTEM_H

#include <map>
#include <stdexcept>
#include "SystemBase.h"
#include "../Nodes/PhysicsNode.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Polygon.h"
#include "../../PhysicsEngine/PhysicsEngine.h"
#include "../../PhysicsEngine/Shapes/ShapeFactory.h"

class PhysicsSystem : public SystemBase
{
public:
    void Update() override;
    void Register(Entity& entity) override;

private:
    std::map<Entity*, PhysicsNode*> _registeredEntitys;
    std::map<PhysicsNode*, PEngine::Rigidbody*> _nodeBodyPairs;
    PEngine::PhysicsEngine _pEnginde;

    PEngine::Rigidbody* CreateRigidbody(PhysicsNode& node);
};


#endif //GAMEENGINE_PHYSICSSYSTEM_H
