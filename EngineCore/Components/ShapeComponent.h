//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_SHAPECOMPONENT_H
#define GAMEENGINE_SHAPECOMPONENT_H

#include "ComponentBase.h"
#include "../Shapes/Shape.h"

class ShapeComponent : ComponentBase
{
public:
    ShapeComponent(Shape shape);

    std::string GetName() override;
    const Shape& GetShape();

private:
    Shape _shape;
};


#endif //GAMEENGINE_SHAPECOMPONENT_H
