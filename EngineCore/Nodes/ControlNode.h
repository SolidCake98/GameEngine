//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_CONTROLNODE_H
#define GAMEENGINE_CONTROLNODE_H

#include "NodeBase.h"
#include "../Components/VelocityChangeComponent.h"
#include "../Components/PositionComponent.h"

class ControlNode : NodeBase
{
public:
    ControlNode(VelocityChangeComponent& velocityChange, PositionComponent& positionComponent);
    VelocityChangeComponent& GetVelocityChange() const;
    PositionComponent& GetPosition() const;

private:
    VelocityChangeComponent* _velocityChange;
    PositionComponent* _positionComponent;

};


#endif //GAMEENGINE_CONTROLNODE_H
