//
// Created by kiku on 26.05.2020.
//

#include "GraphicsNode.h"

GraphicsNode::GraphicsNode(GraphicsNode & gn) {
    this->_position = gn._position;
    this->_shape = gn._shape;
}

GraphicsNode::GraphicsNode(PositionComponent& position, ShapeComponent& shape)
{
    _position  = &position;
    _shape = &shape;
}

const PositionComponent& GraphicsNode::GetPosition() const { return *_position; }
const ShapeComponent& GraphicsNode::GetShape() const { return *_shape; }

