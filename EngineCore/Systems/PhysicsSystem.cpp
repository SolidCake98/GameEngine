//
// Created by gleb on 19.05.2020.
//

#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
{
    _pEnginde.Start();
}

PhysicsSystem::~PhysicsSystem()
{
    _registeredEntitys.clear();

    for (auto pair : _nodeBodyPairs)
    {
        _pEnginde.Remove(*pair.second);
        delete pair.second;
    }

    _nodeBodyPairs.clear();

    for (auto pair : _registeredEntitys)
    {
        delete pair.second;
    }

    _registeredEntitys.clear();
}

void PhysicsSystem::Update()
{

}

void PhysicsSystem::Register(Entity& entity)
{
    if (_registeredEntitys.find(&entity) != _registeredEntitys.end())
    {
        throw std::invalid_argument("Entity already registered!");
    }

    auto node = new PhysicsNode(
            *((PositionComponent*)entity.Get("PositionComponent")),
            *((VelocityComponent*)entity.Get("VelocityComponent")),
            *((BodyComponent*)entity.Get("BodyComponent")),
            *((ShapeComponent*)entity.Get("ShapeComponent")));

    _registeredEntitys[&entity] = node;
    auto rb = CreateRigidbody(*node);
    _nodeBodyPairs[node] = rb;
    _pEnginde.Add(*rb);
}

PEngine::Rigidbody* PhysicsSystem::CreateRigidbody(PhysicsNode &node)
{
    PEngine::Rigidbody* rb;

    if (node.GetShape().GetName() == "Polygon")
    {
        auto poly = (const Polygon&)node.GetShape();
        auto points = new PEngine::Point[poly.GetLength()];

        for (int i = 0; i < poly.GetLength(); i++)
        {
            points[i] = PEngine::Point(poly[i].x, poly[i].y);
        }

        rb = new PEngine::Rigidbody(
                *PEngine::ShapeFactory::CreateConvexPolygon(points, poly.GetLength()),
                node.GetBody().GetM(),
                node.GetBody().GetI());
    }
    else
    {
        auto circle = (const Circle&)node.GetShape();

        rb = new PEngine::Rigidbody(
                *PEngine::ShapeFactory::CreateCircle(circle.GetCenter().x, circle.GetCenter().y, circle.GetR()),
                node.GetBody().GetM(),
                node.GetBody().GetI());
    }

    rb->SetPosition(PEngine::Point(node.GetPosition().GetX(), node.GetPosition().GetY()));
    rb->SetAngle(node.GetPosition().GetAngle());
    rb->SetV(PEngine::Point(node.GetVelocity().GetX(), node.GetVelocity().GetY()));
    rb->SetW(node.GetVelocity().GetW());

    return rb;
}
