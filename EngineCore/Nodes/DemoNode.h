//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_DEMONODE_H
#define GAMEENGINE_DEMONODE_H

#include "NodeBase.h"
#include "../Components/DemoComponent.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityChangeComponent.h"
#include "../Components/TranslateComponent.h"

class DemoNode : public NodeBase
{
public:
    DemoNode(
            DemoComponent& demo,
            PositionComponent& position,
            VelocityChangeComponent& velocityChange,
            TranslateComponent& translateComponent);

    DemoComponent& GetDemo() const;
    PositionComponent& GetPosition() const;
    VelocityChangeComponent& GetVelocityChange() const;
    TranslateComponent& GetTranslate() const;

private:
    DemoComponent* _demo;
    PositionComponent* _position;
    VelocityChangeComponent* _velocityChange;
    TranslateComponent* _translate;
};


#endif //GAMEENGINE_DEMONODE_H
