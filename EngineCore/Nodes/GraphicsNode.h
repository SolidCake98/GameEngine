//
// Created by kiku on 26.05.2020.
//

#ifndef GAMEENGINE_GRAPHICSNODE_H
#define GAMEENGINE_GRAPHICSNODE_H

#include "NodeBase.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityComponent.h"
#include "../Components/BodyComponent.h"
#include "../Components/ShapeComponent.h"

class GraphicsNode : NodeBase
{
public:
    GraphicsNode(GraphicsNode&);

    GraphicsNode(PositionComponent& position,
                ShapeComponent& shape);

    PositionComponent& GetPosition() const;
    ShapeComponent& GetShape() const;

private:
    PositionComponent* _position;
    ShapeComponent* _shape;
};


#endif //GAMEENGINE_GRAPHICSNODE_H
