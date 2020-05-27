//
// Created by gleb on 27.05.2020.
//

#ifndef GAMEENGINE_TESTNODE_H
#define GAMEENGINE_TESTNODE_H

#include "NodeBase.h"
#include "../Components/PositionComponent.h"

class TestNode : public NodeBase
{
public:
    TestNode(PositionComponent& position);
    ~TestNode();

    PositionComponent& GetPosition() const;
    PositionComponent& GetStartPosition() const;

private:
    PositionComponent* _position;
    PositionComponent* _startPositon;
};


#endif //GAMEENGINE_TESTNODE_H
