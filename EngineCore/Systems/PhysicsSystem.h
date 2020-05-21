//
// Created by gleb on 19.05.2020.
//

#ifndef GAMEENGINE_PHYSICSSYSTEM_H
#define GAMEENGINE_PHYSICSSYSTEM_H

#include <map>
#include <list>
#include <stdexcept>
#include "SystemBase.h"
#include "../Nodes/PhysicsNode.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Polygon.h"
#include "../../PhysicsEngine/PhysicsEngine.h"
#include "../../PhysicsEngine/Shapes/ShapeFactory.h"

// Описание:
// Система, ответственная за обработку физических взаимодействий.
class PhysicsSystem : public SystemBase
{
public:
    PhysicsSystem();
    ~PhysicsSystem();

    void Update() override;
    void Register(Entity& entity) override;

private:
    struct NodeBodyPair
    {
        PhysicsNode* node;
        PEngine::Rigidbody* body;

        NodeBodyPair(PhysicsNode* node, PEngine::Rigidbody* body);
    };

    std::map<Entity*, PhysicsNode*> _registeredEntitys;
    std::list<NodeBodyPair> _nodeBodyPairs;
    PEngine::PhysicsEngine _pEnginde;

    PEngine::Rigidbody* CreateRigidbody(PhysicsNode& node);
};


#endif //GAMEENGINE_PHYSICSSYSTEM_H
