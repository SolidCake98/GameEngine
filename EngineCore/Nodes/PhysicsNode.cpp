//
// Created by gleb on 15.05.2020.
//

#include "PhysicsNode.h"

PhysicsNode::PhysicsNode(PositionComponent& position, VelocityComponent& velocity,
    BodyComponent& body, ShapeComponent& shape)
{
    Init(position, velocity, body, shape);
    _velocityChange = nullptr;
}

PhysicsNode::PhysicsNode(PositionComponent& position, VelocityComponent& velocity,
    BodyComponent& body, ShapeComponent& shape, VelocityChangeComponent& velocityChange)
{
    Init(position, velocity, body, shape);
   _velocityChange = &velocityChange;
}

PositionComponent& PhysicsNode::GetPosition() const { return *_position; }
VelocityComponent& PhysicsNode::GetVelocity() const { return *_velocity; }
BodyComponent& PhysicsNode::GetBody() const { return *_body; }
ShapeComponent& PhysicsNode::GetShape() const { return *_shape; }
VelocityChangeComponent *PhysicsNode::GetVelocityChange() const { return _velocityChange; }

void PhysicsNode::Init(PositionComponent &position, VelocityComponent &velocity,
        BodyComponent &body, ShapeComponent &shape)
{
    _position  = &position;
    _velocity = &velocity;
    _body = &body;
    _shape = &shape;
}


