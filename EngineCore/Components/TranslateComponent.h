//
// Created by gleb on 02.06.2020.
//

#ifndef GAMEENGINE_TRANSLATECOMPONENT_H
#define GAMEENGINE_TRANSLATECOMPONENT_H

#include "ComponentBase.h"

class TranslateComponent : public ComponentBase
{
public:
    TranslateComponent(float x = 0, float y = 0, float angle = 0);

    std::string GetName() const override;
    float GetX() const;
    void SetX(float x);
    float GetY() const;
    void SetY(float y);
    float GetAngle() const;
    void SetAngle(float angle);
    bool GetIsNeedTranslate() const;
    void SetIsNeedTranslate(bool isNeedTranslate);

private:
    float _x; // позиция тела по оси абсцисс
    float _y; // позиция тела по оси ординат
    float _angle; // поворот тела
    bool _isNeedTranslate;
};


#endif //GAMEENGINE_TRANSLATECOMPONENT_H
