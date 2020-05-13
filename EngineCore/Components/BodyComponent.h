//
// Created by gleb on 13.05.2020.
//

#ifndef GAMEENGINE_BODYCOMPONENT_H
#define GAMEENGINE_BODYCOMPONENT_H

#include "ComponentBase.h"

class BodyComponent : public ComponentBase
{
public:
    BodyComponent(float M, float I);

    std::string GetName() override;

    float GetM();
    float GetI();

private:
    float _M;
    float _I;
};


#endif //GAMEENGINE_BODYCOMPONENT_H
