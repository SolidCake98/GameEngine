//
// Created by danil on 19.05.2020.
//

#include "Input.h"
#include "InputSystem.h"

void Input::OnKeyDown(int key)
{
    _keyStates[key] = 1;
}

void Input::OnKeyUp(int key)
{
    _keyStates[key] = 2;
}

void Input::OnKeyNothing(int key)
{
    _keyStates[key] = 0;
}

bool Input::GetKeyDown(int key)
{
    return Input::Get()->_keyStates[key] == 1;
}

bool Input::GetKeyUp(int key)
{
    return Input::Get()->_keyStates[key] == 2;
}

Input::Input()
{
    InputSystem::get()->AddListener(this);
}

Input *Input::Get()
{
    static Input input;
    return &input;
}


