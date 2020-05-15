//
// Created by gleb on 15.05.2020.
//

#ifndef GAMEENGINE_POINT_H
#define GAMEENGINE_POINT_H

class Point
{
public:
    Point(float x, float y);

    float GetX();
    float GetY();

private:
    float _x;
    float _y;
};

#endif //GAMEENGINE_POINT_H
