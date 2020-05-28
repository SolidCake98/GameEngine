//
// Created by root on 30.03.2020.
//

#ifndef GAMEENGINE_INPUTSYSTEM_H
#define GAMEENGINE_INPUTSYSTEM_H

#include <vector>
#include "InputListener.h"
#include "CKeyboard.h"
#include "../EngineCore/Systems/SystemBase.h"

class InputSystem: public SystemBase
{
public:
    ~InputSystem();

    void AddListener(InputListener* listener);

    void RemoveListener(InputListener* listener);

    void Update() override;

    std::string GetName() const override;

    void Register(Entity& entity) override ;

    void Unregister(Entity& entity) override;

public:
    static InputSystem* get();

private:
    InputSystem();

private:
    std::vector<InputListener*> _listeners;
    CKeyboard _cKeyboard;
    short _keyMap[KEY_CNT];
    short _oldKeyMap[KEY_CNT];
};
#endif //GAMEENGINE_INPUTSYSTEM_H
