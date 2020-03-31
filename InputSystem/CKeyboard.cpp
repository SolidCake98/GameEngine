//
// Created by danil on 30.03.2020.
//

#include <zconf.h>
#include "CKeyboard.h"

CKeyboard::CKeyboard()
{
    active = false;
    keyboard_fd = 0;
    keyboard_ev = new input_event();
    keyboard_st = new KeyBoardState();
    keyboard_fd = open(KEYBOARD_DEV, O_RDONLY);
    if (keyboard_fd > 0)
    {
        ioctl(keyboard_fd, EVIOCGNAME(256), name);
        std::cout << "   Name: " << name << std::endl;
        active = true;
        pthread_create(&thread, 0, &CKeyboard::Loop, this);
    }
    else
    {
        std::cout << "Can not access file input " << KEYBOARD_DEV << std::endl;
    }
}

void *CKeyboard::Loop(void *obj)
{
    while (reinterpret_cast<CKeyboard *>(obj)->active) reinterpret_cast<CKeyboard *>(obj)->ReadEv();
}

void CKeyboard::ReadEv()
{
    int bytes = read(keyboard_fd, keyboard_ev, sizeof(*keyboard_ev));
    if (bytes > 0)
    {

        if (keyboard_ev->type & EV_KEY)
        {
            keyboard_st->keys[keyboard_ev->code] = keyboard_ev->value;
        }
    }
}

short CKeyboard::GetKeyState(short key)
{
    auto state = keyboard_st->keys[key];
    if(state != 0)
    {
        keyboard_st->keys[key] = 0;
    }
    return state;
}

CKeyboard::~CKeyboard()
{
    if (keyboard_fd > 0)
    {
        active = false;
        pthread_join(thread, 0);
        close(keyboard_fd);
    }
    delete keyboard_st;
    delete keyboard_ev;
    keyboard_fd = 0;
}


