#include <iostream>
#include "InputSystem/CKeyboard.h"
#include "CTimer/CTimer.h"

int main(void)
{
    const double FPS = 100;
    const double DT = 1/FPS;

    CKeyboard kb;
    CTimer t;

    double accumulator = 0;

    while (true)
    {
        accumulator += t.Elapsed(true);

//        if(accumulator > 0.2)
//        {
//            accumulator = 0.2;
//        }
//
//        while (accumulator > DT)
//        {
//            accumulator -= DT;
//        }

        if (kb.GetKeyState(KEY_UP))
        {
            std::cout << "up" << std::endl;
        }
        if (kb.GetKeyState(KEY_DOWN))
        {
            std::cout << "down" << std::endl;
        }
        if (kb.GetKeyState(KEY_LEFT))
        {
            std::cout << "left" << std::endl;
        }
        if (kb.GetKeyState(KEY_RIGHT))
        {
            std::cout << "right" << std::endl;
        }
    }


}


