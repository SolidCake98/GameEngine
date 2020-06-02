//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_DEMOSYSTEM_H
#define GAMEENGINE_DEMOSYSTEM_H

#include <map>
#include <math.h>
#include "SystemBase.h"
#include "../Nodes/DemoNode.h"

class DemoSystem : public SystemBase
{
public:
    std::string GetName() const override;
    void Update() override;
    void Register(Entity& entity) override;
    void Unregister(Entity& entity) override;

private:
    std::map<Entity*, DemoNode*> _registered;

    float CalculateDistance(float x1, float y1, float x2, float y2);
    float sqr(float n);
};


#endif //GAMEENGINE_DEMOSYSTEM_H
