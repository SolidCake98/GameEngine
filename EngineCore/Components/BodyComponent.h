//
// Created by gleb on 13.05.2020.
//

#ifndef GAMEENGINE_BODYCOMPONENT_H
#define GAMEENGINE_BODYCOMPONENT_H

#include "ComponentBase.h"

class BodyComponent : public ComponentBase
{
public:
    BodyComponent(float M, float I, bool isStatic = false);

    std::string GetName() const override;
    float GetM() const;
    float GetI() const;
    bool GetIsStatic() const;

private:
    float _M; // масса тела
    float _I; // момент инерции
    bool _isStatic; // статическое ли тело
};


#endif //GAMEENGINE_BODYCOMPONENT_H
