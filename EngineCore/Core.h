//
// Created by gleb on 21.05.2020.
//

#ifndef GAMEENGINE_CORE_H
#define GAMEENGINE_CORE_H

#include <list>
#include "Systems/SystemBase.h"

class Core
{
public:
    void Start();
    void Stop();
    void AddSystem(SystemBase& system, int priority);
    void RemoveSystem(SystemBase& system);
    void RemoveSystem(std::string systemName);
    void AddEntity(Entity& entity);
    void RemoveEntity(Entity& entity);
    void RegisterEntity(Entity& entity, SystemBase& system);
    void RegisterEntity(Entity& entity, std::string systemName);

private:
    std::list<Entity*> _entitys;

};


#endif //GAMEENGINE_CORE_H
