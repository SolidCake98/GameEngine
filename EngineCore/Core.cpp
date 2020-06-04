//
// Created by gleb on 21.05.2020.
//

#include "Core.h"
#include "../InputSystem/Input.h"
#include "../InputSystem/InputSystem.h"

void Core::Start()
{
    _isWork = true;
    Work();
}

void Core::Stop()
{
    _isWork = false;
}

void Core::AddSystem(SystemBase &system, int priority)
{
    for (auto pair : _systems)
    {
        if (pair.first == priority)
        {
            throw std::invalid_argument("Priority is already taken!");
        }

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

SystemBase* Core::GetSystem(int priority)
{
    auto it = _systems.find(priority);
    return (it == _systems.end()) ? nullptr : it->second;
}

SystemBase* Core::GetSystem(std::string systemName)
{
    for (auto pair : _systems)
    {
        if (pair.second->GetName() == systemName)
        {
            return pair.second;
        }
    }

    return nullptr;
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
    if (_entitys.find(&entity) != _entitys.end())
    {
        for (auto pair : _systems)
        {
            pair.second->Unregister(entity);
        }
    }

    _entitys.erase(&entity);
}

void Core::RegisterEntity(Entity &entity, SystemBase &system)
{
    if (_entitys.find(&entity) != _entitys.end() && IsSystemAdded(system))
    {
        system.Register(entity);
    }
}

void Core::RegisterEntity(Entity &entity, std::string systemName)
{
    if (_entitys.find(&entity) != _entitys.end())
    {
        SystemBase* system;

        if ((system = IsSystemAdded(systemName)) != nullptr)
        {
            system->Register(entity);
        }
    }
}

void Core::UnregisterEntity(Entity &entity, SystemBase &system)
{
    if (_entitys.find(&entity) != _entitys.end() && IsSystemAdded(system))
    {
        system.Unregister(entity);
    }
}

void Core::UnregisterEntity(Entity &entity, std::string systemName)
{
    if (_entitys.find(&entity) != _entitys.end())
    {
        SystemBase* system;

        if ((system = IsSystemAdded(systemName)) != nullptr)
        {
            system->Unregister(entity);
        }
    }
}

bool Core::IsSystemAdded(SystemBase &system)
{
    for (auto pair : _systems)
    {
        if (pair.second == &system)
        {
            return true;
        }
    }

    return false;
}

SystemBase* Core::IsSystemAdded(std::string systemName)
{
    for (auto pair : _systems)
    {
        if (pair.second->GetName() == systemName)
        {
            return pair.second;
        }
    }

    return nullptr;
}

void Core::Work()
{
    const double FPS = 60;
    const double DT = 1/FPS;
    CTimer t;
    double accumulator = 0;

    while (_isWork)
    {
        accumulator += t.Elapsed(true);

        if (accumulator > 3 * DT)
        {
            accumulator = 3 * DT;
        }

        while(accumulator > DT)
        {
            accumulator -= DT;

            for (auto pair : _systems)
            {
                pair.second->Update();
            }
        }

        if(Input::GetKeyDown(KEY_ESC))
        {
            _isWork = false;
        }
    }
}
