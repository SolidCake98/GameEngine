//
// Created by danil on 04.05.2020.
//

#ifndef GAMEENGINE_FAKEWINDOW_H
#define GAMEENGINE_FAKEWINDOW_H


#include "InputSystem/InputListener.h"

class FakeWindow
{
public:
    void OnCreate();
    void OnUpdate();
    void KeyDown();
    void KeyUp();
};


#endif //GAMEENGINE_FAKEWINDOW_H
