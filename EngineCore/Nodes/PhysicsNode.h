//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_PHYSICSNODE_H
#define GAMEENGINE_PHYSICSNODE_H

#include "NodeBase.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityComponent.h"
#include "../Components/VelocityChangeComponent.h"
#include "../Components/BodyComponent.h"
#include "../Components/ShapeComponent.h"

class PhysicsNode : NodeBase
{
public:
    PhysicsNode(PositionComponent& position,
                VelocityComponent& velocity,
                BodyComponent& body,
                ShapeComponent& shape,
                VelocityChangeComponent* velocityChange = nullptr);

    PositionComponent& GetPosition() const;
    VelocityComponent& GetVelocity() const;
    BodyComponent& GetBody() const;
    ShapeComponent& GetShape() const;
    VelocityChangeComponent* GetVelocityChange() const;

private:
    PositionComponent* _position;
    VelocityComponent* _velocity;
    BodyComponent* _body;
    ShapeComponent* _shape;
    VelocityChangeComponent* _velocityChange;
};


#endif //GAMEENGINE_PHYSICSNODE_H
