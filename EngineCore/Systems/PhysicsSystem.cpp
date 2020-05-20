//
// Created by gleb on 19.05.2020.
//

#include "PhysicsSystem.h"

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
    _nodeBodyPairs[node] = CreateRigidbody(*node);
}

PEngine::Rigidbody* PhysicsSystem::CreateRigidbody(PhysicsNode &node)
{
    if (node.GetShape().GetName() == "Polygon")
    {
        auto poly = (const Polygon&)node.GetShape();
        auto points = new PEngine::Point[poly.GetLength()];

        for (int i = 0; i < poly.GetLength(); i++)
        {
            points[i] = PEngine::Point(poly[i].x, poly[i].y);
        }

        return new PEngine::Rigidbody(
                *PEngine::ShapeFactory::CreateConvexPolygon(points, poly.GetLength()),
                node.GetBody().GetM(),
                node.GetBody().GetI());
    }
    else
    {
        auto circle = (const Circle&)node.GetShape();

        return new PEngine::Rigidbody(
                *PEngine::ShapeFactory::CreateCircle(circle.GetCenter().x, circle.GetCenter().y, circle.GetR()),
                node.GetBody().GetM(),
                node.GetBody().GetI());
    }
}
