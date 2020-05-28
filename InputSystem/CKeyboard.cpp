//
// Created by danil on 30.03.2020.
//

#include <zconf.h>
#include "CKeyboard.h"

CKeyboard::CKeyboard()
{
    _active = false;
    _keyboardFd = 0;
    _keyboardEv = new input_event();
    _keyboardSt = new KeyBoardState();
    _keyboardFd = open(KEYBOARD_DEV, O_RDONLY);
    if (_keyboardFd > 0)
    {
        ioctl(_keyboardFd, EVIOCGNAME(256), _name);
        std::cout << "   Name: " << _name << std::endl;
        _active = true;
        pthread_create(&_thread, 0, &CKeyboard::Loop, this);
    }
    else
    {
        std::cout << "Can not access file input " << KEYBOARD_DEV << std::endl;
    }
}

void *CKeyboard::Loop(void *obj)
{
    while (reinterpret_cast<CKeyboard *>(obj)->_active) reinterpret_cast<CKeyboard *>(obj)->ReadEv();
}

void CKeyboard::ReadEv()
{
    int bytes = read(_keyboardFd, _keyboardEv, sizeof(*_keyboardEv));
    if (bytes > 0)
    {

        if (_keyboardEv->type & EV_KEY)
        {
            _keyboardSt->keys[_keyboardEv->code] = _keyboardEv->value;
        }
    }
}

short CKeyboard::GetKeyState(short key)
{
    auto state = _keyboardSt->keys[key];
    if(state != 0)
    {
        _keyboardSt->keys[key] = 0;
    }
    return state;
}

CKeyboard::~CKeyboard()
{
    if (_keyboardFd > 0)
    {
        _active = false;
        pthread_join(_thread, 0);
        close(_keyboardFd);
    }
    delete _keyboardSt;
    delete _keyboardEv;
    _keyboardFd = 0;
}


void CKeyboard::GetKeyboardState(short* key_map)
{
    for(int i = 0; i < KEY_CNT; i++)
    {
        auto state = _keyboardSt->keys[i];
        key_map[i] = state;
    }

}


