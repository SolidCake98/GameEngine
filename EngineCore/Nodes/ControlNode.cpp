//
// Created by gleb on 02.06.2020.
//

#include "ControlNode.h"

ControlNode::ControlNode(VelocityChangeComponent &velocityChange)
{
    _velocityChange = &velocityChange;
}

VelocityChangeComponent &ControlNode::GetVelocityChange()
{
    return *_velocityChange;
}
