//
// Created by danil on 19.05.2020.
//

#include "Input.h"
#include "InputSystem.h"

void Input::OnKeyDown(int key)
{
    keyStates[key] = 1;
}

void Input::OnKeyUp(int key)
{
    keyStates[key] = 2;
}

void Input::OnKeyNothing(int key)
{
    keyStates[key] = 0;
}

bool Input::GetKeyDown(int key)
{
    return Input::get()->keyStates[key] == 1;
}

bool Input::GetKeyUp(int key)
{
    return Input::get()->keyStates[key] == 2;
}

Input::Input()
{
    InputSystem::get()->AddListener(this);
}

Input *Input::get()
{
    static Input input;
    return &input;
}


