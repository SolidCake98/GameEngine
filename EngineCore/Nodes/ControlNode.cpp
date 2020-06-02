//
// Created by gleb on 02.06.2020.
//

#include "ControlNode.h"

ControlNode::ControlNode(VelocityChangeComponent& velocityChange, PositionComponent& positionComponent)
{
    _velocityChange = &velocityChange;
    _positionComponent = &positionComponent;
}

VelocityChangeComponent &ControlNode::GetVelocityChange() const { return *_velocityChange; }
PositionComponent &ControlNode::GetPosition() const { return *_positionComponent; }
