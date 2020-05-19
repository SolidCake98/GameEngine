//
// Created by gleb on 19.05.2020.
//

#include "Entity.h"

void Entity::Add(ComponentBase& component)
{
    auto it = _components.find(component.GetName());

    if (it != _components.end())
    {
        Remove(it);
    }

    _components[component.GetName()] = &component;
}

void Entity::Remove(std::string componentName)
{
    auto it = _components.find(componentName);

    if (it != _components.end())
    {
        Remove(it);
    }
}

void Entity::Remove(ComponentBase& component)
{
    for(auto it = _components.begin(); it != _components.end(); it++)
    {
        if (it->second == &component)
        {
            Remove(it);
            break;
        }
    }
}

ComponentBase* Entity::Get(std::string componentName)
{
    auto it = _components.find(componentName);

    if (it == _components.end())
    {
        return nullptr;
    }

    return it->second;
}

void Entity::Clear()
{
    for (auto c : _components)
    {
        delete c.second;
    }

    _components.clear();
}

void Entity::Remove(std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, ComponentBase *>> iterator)
{
    delete iterator->second;
    _components.erase(iterator);
}
