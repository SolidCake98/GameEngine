//
// Created by root on 30.03.2020.
//

#ifndef GAMEENGINE_INPUTLISTENER_H
#define GAMEENGINE_INPUTLISTENER_H
class InputListener
{
public:
    InputListener()
    {
    }

    ~InputListener()
    {
    }

    virtual void OnKeyDown(int key) = 0;
    virtual void OnKeyUp(int key) = 0;

};
#endif //GAMEENGINE_INPUTLISTENER_H
