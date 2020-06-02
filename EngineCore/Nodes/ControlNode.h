//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_CONTROLNODE_H
#define GAMEENGINE_CONTROLNODE_H

#include "NodeBase.h"
#include "../Components/VelocityChangeComponent.h"

class ControlNode : NodeBase
{
public:
    ControlNode(VelocityChangeComponent& velocityChange);
    VelocityChangeComponent& GetVelocityChange();

private:
    VelocityChangeComponent* _velocityChange;
};


#endif //GAMEENGINE_CONTROLNODE_H
