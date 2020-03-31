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

    virtual void OnKeyDown() = 0;
    virtual void OnKeyUp() = 0;

};
#endif //GAMEENGINE_INPUTLISTENER_H
