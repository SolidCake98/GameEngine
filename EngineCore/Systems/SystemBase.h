//
// Created by gleb on 19.05.2020.
//

#ifndef GAMEENGINE_SYSTEMBASE_H
#define GAMEENGINE_SYSTEMBASE_H

#include "../Entity.h"

// Описание:
// Базовый класс для систем. Система отвечает за тот или иной аспект игровой логики.
class SystemBase
{
public:
    // Описание:
    // Метод, который должен приводить сущности в актуальное состояние.
    virtual void Update() = 0;
    // Описание:
    // Метод, регестрирующий сущности в системе (как правило, это подразумевает регистрацию необходимых системе узлов)
    virtual void Register(Entity& entity) = 0;
};


#endif //GAMEENGINE_SYSTEMBASE_H
