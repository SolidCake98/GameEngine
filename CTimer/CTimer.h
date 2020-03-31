//
// Created by root on 30.03.2020.
//

#include <ctime>

#ifndef GAMEENGINE_CTIMER_H
#define GAMEENGINE_CTIMER_H
class CTimer
{
public:
    CTimer();
    ~CTimer();
    double Elapsed(bool frame);
private:
    timespec process_start, frame_start, current;
};
#endif //GAMEENGINE_CTIMER_H
