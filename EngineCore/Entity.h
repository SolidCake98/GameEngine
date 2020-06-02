//
// Created by gleb on 19.05.2020.
//

#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

#include <map>
#include "Components/ComponentBase.h"

// Описание:
// Класс, определяющий сущность. Данный класс является "контейнером" для компонентов. Компоненты, добавленные в сущность,
// полностью определяют свойства сущности.
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

};


#endif //GAMEENGINE_ENTITY_H
