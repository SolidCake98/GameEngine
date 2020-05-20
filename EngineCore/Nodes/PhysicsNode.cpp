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


const PositionComponent& PhysicsNode::GetPosition() const { return *_position; }
const VelocityComponent& PhysicsNode::GetVelocity() const { return *_velocity; }
const BodyComponent& PhysicsNode::GetBody() const { return *_body; }
const ShapeComponent& PhysicsNode::GetShape() const { return *_shape; }


