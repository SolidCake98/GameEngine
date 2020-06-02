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
    _pEnginde.Stop();

    for (auto pair : _nodeBodyPairs)
    {
        _pEnginde.Remove(*pair.body);
        delete pair.body;
    }

    _nodeBodyPairs.clear();

    for (auto pair : _registeredEntitys)
    {
        delete pair.second;
    }

    _registeredEntitys.clear();
}

std::string PhysicsSystem::GetName() const { return "PhysicsSystem"; }

void PhysicsSystem::Update()
{
    // TODO: применение импульсов
    for (auto pair : _nodeBodyPairs)
    {
        PositionComponent& position = pair.node->GetPosition();
        position.SetX(pair.body->GetPosition().x);
        position.SetY(pair.body->GetPosition().y);
        position.SetAngle(pair.body->GetAngle());

        VelocityComponent& velocity = pair.node->GetVelocity();
        velocity.SetX(pair.body->GetV().x);
        velocity.SetY(pair.body->GetV().y);
        velocity.SetW(pair.body->GetW());

        VelocityChangeComponent* velocityChange = pair.node->GetVelocityChange();

        if (velocityChange != nullptr)
        {
            pair.body->SetV(PEngine::Point(velocityChange->GetX(), velocityChange->GetY()));
            velocityChange->SetX(0);
            velocityChange->SetY(0);
        }

        TranslateComponent* translateComponent = pair.node->GetTranslate();

        if (translateComponent != nullptr && translateComponent->GetIsNeedTranslate())
        {
            pair.body->SetPosition(PEngine::Point(translateComponent->GetX(), translateComponent->GetY()));
            pair.body->SetAngle(translateComponent->GetAngle());
            translateComponent->SetIsNeedTranslate(false);
        }
    }
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
            *((ShapeComponent*)entity.Get("ShapeComponent")),
            ((VelocityChangeComponent*)entity.Get("VelocityChangeComponent")),
            ((TranslateComponent*)entity.Get("TranslateComponent")));

    _registeredEntitys[&entity] = node;
    auto rb = CreateRigidbody(*node);
    _nodeBodyPairs.emplace_back(node, rb);
    _pEnginde.Add(*rb);
}

void PhysicsSystem::Unregister(Entity &entity)
{
    for (auto it = _nodeBodyPairs.begin(); it != _nodeBodyPairs.end(); it++)
    {
        if (it->node == _registeredEntitys[&entity])
        {
            _pEnginde.Remove(*it->body);
            delete it->body;
            _nodeBodyPairs.erase(it);
            delete _registeredEntitys[&entity];
            _registeredEntitys.erase(&entity);
            break;
        }
    }
}

PEngine::Rigidbody* PhysicsSystem::CreateRigidbody(PhysicsNode &node)
{
    PEngine::Rigidbody* rb;

    if (node.GetShape().GetShape().GetName() == "Polygon")
    {
        auto poly = (Polygon&)node.GetShape().GetShape();
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
        auto circle = (Circle&)node.GetShape().GetShape();

        rb = new PEngine::Rigidbody(
                *PEngine::ShapeFactory::CreateCircle(circle.GetCenter().x, circle.GetCenter().y, circle.GetR()),
                node.GetBody().GetM(),
                node.GetBody().GetI());
    }

    rb->SetPosition(PEngine::Point(node.GetPosition().GetX(), node.GetPosition().GetY()));
    rb->SetAngle(node.GetPosition().GetAngle());
    rb->SetV(PEngine::Point(node.GetVelocity().GetX(), node.GetVelocity().GetY()));
    rb->SetW(node.GetVelocity().GetW());
    rb->SetIsStatic(node.GetBody().GetIsStatic());

    return rb;
}

PhysicsSystem::NodeBodyPair::NodeBodyPair(PhysicsNode* node, PEngine::Rigidbody* body)
{
    this->node = node;
    this->body = body;
}
