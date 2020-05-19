//
// Created by danil on 19.05.2020.
//

#ifndef GAMEENGINE_INPUT_H
#define GAMEENGINE_INPUT_H


#include "InputListener.h"
#include <linux/input.h>

class Input : public InputListener
{
public:
    static bool GetKeyDown(int key);
    static bool GetKeyUp(int key);

public:
    static Input* get();

private:
    short keyStates[KEY_CNT];

private:
    Input();
    void OnKeyDown(int key) override;
    void OnKeyUp(int key) override;
    void OnKeyNothing(int key) override;
};


#endif //GAMEENGINE_INPUT_H
