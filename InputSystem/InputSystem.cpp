//
// Created by root on 30.03.2020.
//
#include <algorithm>
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

}
