//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_SHAPE_H
#define GAMEENGINE_SHAPE_H

#include <string>

class Shape
{
public:
    virtual std::string GetName() const = 0;
};


#endif //GAMEENGINE_SHAPE_H
