#include <iostream>
#include "InputSystem/CKeyboard.h"
#include "CTimer/CTimer.h"
#include "FakeWindow.h"
#include "EngineCore/Core.h"
#include "EngineCore/Systems/GraphicsSystem.h"
#include "EngineCore/Systems/TestSystem.h"
#include "EngineCore/Systems/PhysicsSystem.h"
#include "InputSystem/InputSystem.h"

void TestInput()
{
    const double FPS = 60;
    const double DT = 1/FPS;

    FakeWindow window;
    CTimer t;

    window.OnCreate();


    double accumulator = 0;

    while (true)
    {
        accumulator += t.Elapsed(true);
        while(accumulator > DT)
        {
            window.OnUpdate();
            accumulator -= DT;
        }
    }
}

void TestGraphics()
{
    Core core;

    InputSystem* input = InputSystem::get();
    core.AddSystem(*input, 0);

    GraphicsSystem graphics;
    core.AddSystem(graphics, 1);

    TestSystem test;
    core.AddSystem(test, 2);



    Entity e1;

    PositionComponent pc1(100, 100, 45);
    e1.Add(pc1);

    Point points1[] = {Point(-10, -10), Point(10, -10), Point(0, 10), Point(0, -5)};
    Polygon p1(points1, 4);

    ShapeComponent sc1(p1);
    e1.Add(sc1);

    graphics.Register(e1);
    test.Register(e1);


    Entity e2;

    PositionComponent pc2(200, 200, 0);
    e2.Add(pc2);

    Circle c(Point(100, 100), 50);
    ShapeComponent sc2(c);
    e2.Add(sc2);

    graphics.Register(e2);
    //test.Register(e2);


    Entity e3;

    PositionComponent pc3(400, 100, 45);
    e3.Add(pc3);

    Point points2[] = {Point(-10, -10), Point(10, -10), Point(0, 10)};
    Polygon p3(points2, 3);

    ShapeComponent sc3(p3);
    e3.Add(sc3);

    graphics.Register(e3);
    //test.Register(e3);

    core.Start();
}

void TestPhysics()
{
    Core core;

    PhysicsSystem physics;
    core.AddSystem(physics, 1);

    GraphicsSystem graphics;
    core.AddSystem(graphics, 2);

    Entity entity1;

    Point points1[] = {Point(-10, -10), Point(10, -10), Point(0, 10)};
    Polygon poly1(points1, 3);

    PositionComponent pc1(100, 100, 0);
    ShapeComponent sc1(poly1);
    VelocityComponent vc1(100, 0, 0);
    BodyComponent bc1(2, 1);

    entity1.Add(pc1);
    entity1.Add(sc1);
    entity1.Add(vc1);
    entity1.Add(bc1);

    physics.Register(entity1);
    graphics.Register(entity1);


    Entity entity2;

    Point points2[] = {Point(-10, -10), Point(10, -10), Point(0, 10)};
    Polygon poly2(points2, 3);

    PositionComponent pc2(200, 100, 0);
    ShapeComponent sc2(poly2);
    VelocityComponent vc2(-100, 0, 0);
    BodyComponent bc2(2, 1);

    entity2.Add(pc2);
    entity2.Add(sc2);
    entity2.Add(vc2);
    entity2.Add(bc2);

    physics.Register(entity2);
    graphics.Register(entity2);


    core.Start();
}

int main()
{
    //TestInput();
    //TestGraphics();
    TestPhysics();
}


