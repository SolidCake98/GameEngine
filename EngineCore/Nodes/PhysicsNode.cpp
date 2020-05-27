//
// Created by gleb on 15.05.2020.
//

#include "PhysicsNode.h"

PhysicsNode::PhysicsNode(PositionComponent& position, VelocityComponent& velocity,
    BodyComponent& body, ShapeComponent& shape)
{
    _position  = &position;
    _velocity = &velocity;
    _body = &body;
    _shape = &shape;
}


PositionComponent& PhysicsNode::GetPosition() const { return *_position; }
VelocityComponent& PhysicsNode::GetVelocity() const { return *_velocity; }
BodyComponent& PhysicsNode::GetBody() const { return *_body; }
ShapeComponent& PhysicsNode::GetShape() const { return *_shape; }


