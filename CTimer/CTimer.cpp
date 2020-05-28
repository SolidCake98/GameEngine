//
// Created by danil on 31.03.2020.
//

#include "CTimer.h"

CTimer::CTimer()
{
    clock_gettime(CLOCK_REALTIME, &process_start);
    frame_start = process_start;
}

CTimer::~CTimer()
{

}

double CTimer::Elapsed(bool frame)
{
    clock_gettime(CLOCK_REALTIME, &current);
    double elapsed;

    if(frame)
    {
        elapsed = current.tv_sec + current.tv_nsec / 1000000000.0 -   frame_start.tv_sec -   frame_start.tv_nsec / 1000000000.0;
        delta_time = current.tv_sec + current.tv_nsec / 1000000000.0 -   frame_start.tv_sec -   frame_start.tv_nsec / 1000000000.0;
    }
    else
    {
        elapsed = current.tv_sec + current.tv_nsec / 1000000000.0 - process_start.tv_sec - process_start.tv_nsec / 1000000000.0;
    }

    frame_start = current;

    return elapsed;

}

double CTimer::GetDeltaTime()
{
    return delta_time;
}

