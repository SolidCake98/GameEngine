//
// Created by gleb on 02.06.2020.
//

#include "DemoNode.h"

DemoNode::DemoNode(DemoComponent& demo, PositionComponent& position, VelocityChangeComponent& velocityChange)
{
    _demo = &demo;
    _position = &position;
    _velocityChange = &velocityChange;
}

DemoComponent &DemoNode::GetDemo() const { return *_demo; }
PositionComponent &DemoNode::GetPosition() const { return *_position; }
VelocityChangeComponent &DemoNode::GetVelocityChange() const { return *_velocityChange; }
