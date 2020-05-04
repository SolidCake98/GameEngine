//
// Created by danil on 30.03.2020.
//

#ifndef GAMEENGINE_CKEYBOARD_H
#define GAMEENGINE_CKEYBOARD_H
#include <iostream>
#include <fcntl.h>
#include <pthread.h>
#include <linux/input.h>

#define KEYBOARD_DEV "/dev/input/event4"
struct KeyBoardState
{
    signed short keys[KEY_CNT];
};

class CKeyboard
{
public:
    CKeyboard();
    ~CKeyboard();
    static void* Loop(void* obj);
    void ReadEv();
    short GetKeyState(short key);
    void GetKeyboardState(short* key_map);

private:
    pthread_t thread;
    bool active;
    int keyboard_fd;
    input_event *keyboard_ev;
    KeyBoardState *keyboard_st;
    char name[256];
};

#endif //GAMEENGINE_CKEYBOARD_H

