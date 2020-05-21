//
// Created by gleb on 21.05.2020.
//

#include "Core.h"

void Core::Start()
{

}

void Core::Stop()
{

}

void Core::AddSystem(SystemBase &system, int priority)
{
    if (_systems.find(priority) != _systems.end())
    {
        throw std::invalid_argument("Priority is already taken!");
    }

    for (auto pair : _systems)
    {
        if (pair.second->GetName() == system.GetName())
        {
            throw std::invalid_argument("System is already registered!");
        }
    }

    _systems[priority] = &system;
}

void Core::RemoveSystem(int priority)
{
    _systems.erase(priority);
}

void Core::RemoveSystem(SystemBase &system)
{
    for (auto it = _systems.begin(); it != _systems.end(); it++)
    {
        if (it->second == &system)
        {
            _systems.erase(it);
            break;
        }
    }
}

void Core::RemoveSystem(std::string systemName)
{
    for (auto it = _systems.begin(); it != _systems.end(); it++)
    {
        if (it->second->GetName() == systemName)
        {
            _systems.erase(it);
            break;
        }
    }
}

void Core::AddEntity(Entity &entity)
{
    if (!_entitys.insert(&entity).second)
    {
        throw std::invalid_argument("Entity is already added!");
    }
}

void Core::RemoveEntity(Entity &entity)
{

}

void Core::RegisterEntity(Entity &entity, SystemBase &system)
{

}

void Core::RegisterEntity(Entity &entity, std::string systemName)
{

}
