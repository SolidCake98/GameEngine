//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_SHAPECOMPONENT_H
#define GAMEENGINE_SHAPECOMPONENT_H

#include "ComponentBase.h"
#include "../Shapes/Shape.h"

class ShapeComponent : public ComponentBase
{
public:
    ShapeComponent(Shape& shape);

    std::string GetName() const override;
    const Shape& GetShape() const;

private:
    Shape* _shape;
};


#endif //GAMEENGINE_SHAPECOMPONENT_H
