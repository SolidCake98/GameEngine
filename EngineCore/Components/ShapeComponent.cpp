//
// Created by gleb on 15.05.2020.
//

#include "ShapeComponent.h"

ShapeComponent::ShapeComponent(Shape shape) :
    _shape(shape)
{

}

std::string ShapeComponent::GetName() { return "ShapeComponent"; }

const Shape& ShapeComponent::GetShape() { return _shape; }




