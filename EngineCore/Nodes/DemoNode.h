//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_DEMONODE_H
#define GAMEENGINE_DEMONODE_H

#include "NodeBase.h"
#include "../Components/DemoComponent.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityChangeComponent.h"

class DemoNode : public NodeBase
{
public:
    DemoNode(DemoComponent& demo, PositionComponent& position, VelocityChangeComponent& velocityChange);

    DemoComponent& GetDemo() const;
    PositionComponent& GetPosition() const;
    VelocityChangeComponent& GetVelocityChange() const;

private:
    DemoComponent* _demo;
    PositionComponent* _position;
    VelocityChangeComponent* _velocityChange;
};


#endif //GAMEENGINE_DEMONODE_H
