//
// Created by gleb on 21.05.2020.
//

#ifndef GAMEENGINE_CORE_H
#define GAMEENGINE_CORE_H

#include <set>
#include <map>
#include <stdexcept>
#include "Systems/SystemBase.h"

// Описание:
// Ядро движка. Оно объединяет в себе работу всех систем.
class Core
{
public:
    void Start();
    void Stop();
    void AddSystem(SystemBase& system, int priority);
    void RemoveSystem(int priority);
    void RemoveSystem(SystemBase& system);
    void RemoveSystem(std::string systemName);
    SystemBase* GetSystem(int priority);
    SystemBase* GetSystem(std::string systemName);
    void AddEntity(Entity& entity);
    void RemoveEntity(Entity& entity);
    void RegisterEntity(Entity& entity, SystemBase& system);
    void RegisterEntity(Entity& entity, std::string systemName);

private:
    std::set<Entity*> _entitys;
    std::map<int, SystemBase*> _systems;

    void Work();
};


#endif //GAMEENGINE_CORE_H
