//
// Created by gleb on 19.05.2020.
//

#ifndef GAMEENGINE_SYSTEMBASE_H
#define GAMEENGINE_SYSTEMBASE_H


#include "../Entity.h"

class SystemBase
{
public:
    virtual void Update() = 0;
    virtual void Register(Entity& entity) = 0;
};


#endif //GAMEENGINE_SYSTEMBASE_H
