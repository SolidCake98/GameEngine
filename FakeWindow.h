//
// Created by danil on 04.05.2020.
//

#ifndef GAMEENGINE_FAKEWINDOW_H
#define GAMEENGINE_FAKEWINDOW_H


#include "InputSystem/InputListener.h"

class FakeWindow: public InputListener
{
public:
    void OnCreate();
    void OnUpdate();
    void OnKeyDown(int key) override;
    void OnKeyUp(int key) override;
};


#endif //GAMEENGINE_FAKEWINDOW_H
