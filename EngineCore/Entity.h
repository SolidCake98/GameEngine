//
// Created by gleb on 19.05.2020.
//

#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

#include <map>
#include "Components/ComponentBase.h"

class Entity
{
public:
    void Add(ComponentBase& component);
    void Remove(std::string componentName);
    void Remove(ComponentBase& component);
    ComponentBase* Get(std::string componentName);
    void Clear();

private:
    std::map<std::string, ComponentBase*> _components;

    void Remove(std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, ComponentBase *>> iterator);
};


#endif //GAMEENGINE_ENTITY_H
