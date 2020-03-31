//
// Created by root on 30.03.2020.
//

#ifndef GAMEENGINE_INPUTSYSTEM_H
#define GAMEENGINE_INPUTSYSTEM_H

#include <vector>
#include "InputListener.h"
#include "CKeyboard.h"

class InputSystem
{
public:
    InputSystem();

    ~InputSystem();

    void AddListener(InputListener* listener);

    void RemoveListener(InputListener* listener);

    void Update();

private:
    std::vector<InputListener*> listeners;
    CKeyboard cKeyboard;
};
#endif //GAMEENGINE_INPUTSYSTEM_H
