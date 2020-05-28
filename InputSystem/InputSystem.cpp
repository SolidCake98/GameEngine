//
// Created by root on 30.03.2020.
//
#include <algorithm>
#include <cstring>
#include "InputSystem.h"

InputSystem::InputSystem() {}

InputSystem::~InputSystem() {}

void InputSystem::AddListener(InputListener *listener)
{
    _listeners.push_back(listener);
}

void InputSystem::RemoveListener(InputListener *listener)
{
    auto position = std::find(_listeners.begin(), _listeners.end(), listener);
    if (position != _listeners.end()) // == myVector.end() means the element was not found
        _listeners.erase(position);
}

void InputSystem::Update()
{
    _cKeyboard.GetKeyboardState(_keyMap);
    for(short i = 0; i < KEY_CNT; i++)
    {
        //KEY IS DOWN
        if(_keyMap[i])
        {
            auto it = _listeners.begin();
            while(it != _listeners.end())
            {
                InputListener* listener = *it;
                listener->OnKeyDown(i);
                ++it;
            }
        }
        else
        {
            if(_keyMap[i] != _oldKeyMap[i])
            {
                auto it = _listeners.begin();
                while(it != _listeners.end())
                {
                    InputListener* listener = *it;
                    listener->OnKeyUp(i);
                    ++it;
                }
            }
            else
            {
                auto it = _listeners.begin();
                while(it != _listeners.end()) {
                    InputListener *listener = *it;
                    listener->OnKeyNothing(i);
                    ++it;
                }
            }
        }
    }
    ::memcpy(_oldKeyMap, _keyMap, sizeof(short) * KEY_CNT);
}

InputSystem *InputSystem::get() {
    static InputSystem system;
    return &system;
}

std::string InputSystem::GetName() const {
    return "InputSystem";
}

void InputSystem::Register(Entity &entity) {

}

void InputSystem::Unregister(Entity &entity) {

}
