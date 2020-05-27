#include <iostream>
#include "InputSystem/CKeyboard.h"
#include "CTimer/CTimer.h"
#include "FakeWindow.h"
#include "EngineCore/Core.h"
#include "EngineCore/Systems/GraphicsSystem.h"
#include "EngineCore/Systems/TestSystem.h"

int main()
{
//    const double FPS = 60;
//    const double DT = 1/FPS;
//
//    FakeWindow window;
//    CTimer t;
//
//    window.OnCreate();
//
//
//    double accumulator = 0;
//
//    while (true)
//    {
//        accumulator += t.Elapsed(true);
//        while(accumulator > DT)
//        {
//            window.OnUpdate();
//            accumulator -= DT;
//        }
//    }

    Core core;

    GraphicsSystem graphics;
    core.AddSystem(graphics, 1);

    Entity e;

    PositionComponent pc(100, 100, 0);
    e.Add(pc);

    //Circle c(Point(0, 0), 50);
    Point points[] = {Point(-10, -10), Point(10, -10), Point(0, 10)};
    Polygon p(points, 3);

    ShapeComponent sc(p);
    e.Add(sc);

    graphics.Register(e);

    TestSystem test;
    //core.AddSystem(test, 2);

    test.Register(e);

    core.Start();
}


