#include <iostream>
#include "InputSystem/CKeyboard.h"
#include "CTimer/CTimer.h"
#include "FakeWindow.h"
#include "EngineCore/Core.h"
#include "EngineCore/Systems/GraphicsSystem.h"
#include "EngineCore/Systems/TestSystem.h"
#include "EngineCore/Systems/PhysicsSystem.h"
#include "EngineCore/Systems/ControlSystem.h"
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


// Треугольник
//    Entity entity1;
//
//    Point points1[] = {Point(-10, -10), Point(10, -10), Point(0, 10)};
//    Polygon poly1(points1, 3);
//
//    PositionComponent pc1(100, 100, 0);
//    ShapeComponent sc1(poly1);
//    VelocityComponent vc1(10, 0, 0);
//    BodyComponent bc1(30, 300);
//
//    entity1.Add(pc1);
//    entity1.Add(sc1);
//    entity1.Add(vc1);
//    entity1.Add(bc1);
//
//    physics.Register(entity1);
//    graphics.Register(entity1);


// Треугольник
//    Entity entity2;
//
//    Point points2[] = {Point(-10, -10), Point(10, -10), Point(0, 10)};
//    Polygon poly2(points2, 3);
//
//    PositionComponent pc2(200, 100, 0);
//    ShapeComponent sc2(poly2);
//    VelocityComponent vc2(-10, 0, 0);
//    BodyComponent bc2(30, 300);
//
//    entity2.Add(pc2);
//    entity2.Add(sc2);
//    entity2.Add(vc2);
//    entity2.Add(bc2);
//
//    physics.Register(entity2);
//    graphics.Register(entity2);


// Окружность
    Entity entity3;

    Circle circle1(Point(0, 0), 10);

    PositionComponent pc3(100, 100, 0);
    ShapeComponent sc3(circle1);
    VelocityComponent vc3(10, 0, 0);
    BodyComponent bc3(2, 3);

    entity3.Add(pc3);
    entity3.Add(sc3);
    entity3.Add(vc3);
    entity3.Add(bc3);

    physics.Register(entity3);
    graphics.Register(entity3);


// Окружность
//    Entity entity4;
//
//    Circle circle2(Point(0, 0), 10);
//
//    PositionComponent pc4(300, 110, 0);
//    ShapeComponent sc4(circle2);
//    VelocityComponent vc4(-10, 0, 0);
//    BodyComponent bc4(100, 5000);
//
//    entity4.Add(pc4);
//    entity4.Add(sc4);
//    entity4.Add(vc4);
//    entity4.Add(bc4);
//
//    physics.Register(entity4);
//    graphics.Register(entity4);


// Квадрат
    Entity entity5;

    Point points5[] = {Point(-20, -10), Point(20, -10), Point(20, 10), Point(-20, 10)};
    Polygon poly5(points5, 4);

    PositionComponent pc5(220, 215, 0);
    ShapeComponent sc5(poly5);
    VelocityComponent vc5(2, -10, 0);
    BodyComponent bc5(300, 800);

    entity5.Add(pc5);
    entity5.Add(sc5);
    entity5.Add(vc5);
    entity5.Add(bc5);

    physics.Register(entity5);
    graphics.Register(entity5);


// Квадрат
//    Entity entity6;
//
//    Point points6[] = {Point(-10, -10), Point(10, -10), Point(10, 10), Point(-10, 10)};
//    Polygon poly6(points6, 4);
//
//    PositionComponent pc6(210, 100, 0);
//    ShapeComponent sc6(poly6);
//    VelocityComponent vc6(0, 10, 0);
//    BodyComponent bc6(100, 400);
//
//    entity6.Add(pc6);
//    entity6.Add(sc6);
//    entity6.Add(vc6);
//    entity6.Add(bc6);
//
//    physics.Register(entity6);
//    graphics.Register(entity6);


    core.Start();
}

void TestControl()
{
    Core core;

    InputSystem* input = InputSystem::get();
    core.AddSystem(*input, 0);

    PhysicsSystem physics;
    core.AddSystem(physics, 1);

    GraphicsSystem graphics;
    core.AddSystem(graphics, 2);

    ControlSystem control;
    core.AddSystem(control, 3);

    // Окружность
    Entity entity;

    Circle circle(Point(0, 0), 10);

    PositionComponent pc(300, 110, 0);
    ShapeComponent sc(circle);
    VelocityComponent vc(-10, 0, 0);
    BodyComponent bc(100, 5000);
    VelocityChangeComponent vcc;

    entity.Add(pc);
    entity.Add(sc);
    entity.Add(vc);
    entity.Add(bc);
    entity.Add(vcc);

    physics.Register(entity);
    graphics.Register(entity);
    control.Register(entity);

    core.Start();
}

int main()
{
    //TestInput();
    //TestGraphics();
    //TestPhysics();
    TestControl();
}


