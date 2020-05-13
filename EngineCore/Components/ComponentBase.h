//
// Created by gleb on 13.05.2020.
//

#ifndef GAMEENGINE_COMPONENTBASE_H
#define GAMEENGINE_COMPONENTBASE_H

#include <string>

// Описание:
// базовый компонент
class ComponentBase
{
public:
    virtual std::string GetName() = 0;
};

#endif //GAMEENGINE_COMPONENTBASE_H
