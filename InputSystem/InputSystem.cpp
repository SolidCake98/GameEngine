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
    listeners.push_back(listener);
}

void InputSystem::RemoveListener(InputListener *listener)
{
    auto position = std::find(listeners.begin(), listeners.end(), listener);
    if (position != listeners.end()) // == myVector.end() means the element was not found
        listeners.erase(position);
}

void InputSystem::Update()
{
    cKeyboard.GetKeyboardState(keyMap);
    for(short i = 0; i < KEY_CNT; i++)
    {
        //KEY IS DOWN
        if(keyMap[i])
        {
            auto it = listeners.begin();
            while(it != listeners.end())
            {
                InputListener* listener = *it;
                listener->OnKeyDown(i);
                ++it;
            }
        }
        else
        {
            if(keyMap[i] != oldKeyMap[i])
            {
                auto it = listeners.begin();
                while(it != listeners.end())
                {
                    InputListener* listener = *it;
                    listener->OnKeyUp(i);
                    ++it;
                }
            }
            else
            {
                auto it = listeners.begin();
                while(it != listeners.end()) {
                    InputListener *listener = *it;
                    listener->OnKeyNothing(i);
                    ++it;
                }
            }
        }
    }
    ::memcpy(oldKeyMap, keyMap, sizeof(short) * KEY_CNT);
}

InputSystem *InputSystem::get() {
    static InputSystem system;
    return &system;
}
