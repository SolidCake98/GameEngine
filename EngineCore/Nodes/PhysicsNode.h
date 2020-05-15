//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_PHYSICSNODE_H
#define GAMEENGINE_PHYSICSNODE_H

#include "NodeBase.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityComponent.h"
#include "../Components/BodyComponent.h"
#include "../Components/ShapeComponent.h"

class PhysicsNode : NodeBase
{
public:
    PhysicsNode(PositionComponent position,
                VelocityComponent velocity,
                BodyComponent body,
                ShapeComponent shape);

    const PositionComponent& GetPosition();
    const VelocityComponent& GetVelocity();
    const BodyComponent& GetBody();
    const ShapeComponent& GetShape();

private:
    PositionComponent _position;
    VelocityComponent _velocity;
    BodyComponent _body;
    ShapeComponent _shape;
};


#endif //GAMEENGINE_PHYSICSNODE_H
