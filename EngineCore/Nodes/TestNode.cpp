//
// Created by gleb on 27.05.2020.
//

#include "TestNode.h"

TestNode::TestNode(PositionComponent &position)
{
    _position = &position;
    _startPositon = new PositionComponent(position.GetX(), position.GetY(), position.GetAngle());
}

TestNode::~TestNode()
{
    delete _startPositon;
}

PositionComponent &TestNode::GetPosition() const { return *_position; }

PositionComponent &TestNode::GetStartPosition() const { return *_startPositon; }


