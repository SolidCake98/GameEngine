#include "PhysicsEngine.h"

using namespace PEngine;

PhysicsEngine::PhysicsEngine()
{
	_isWork = false;
}

PhysicsEngine::~PhysicsEngine()
{
    _isWork = false;

    if(physicsThread->joinable())
    {
        physicsThread->join();
        delete physicsThread;
    }
    else
    {
        delete physicsThread;
    }
}

void PhysicsEngine::Start()
{
	_isWork = true;
	physicsThread = new std::thread(&PhysicsEngine::Work, this);
}

void PhysicsEngine::Stop()
{
	_isWork = false;
    physicsThread->join();
}

PhysicsEngine::const_iterator PhysicsEngine::begin()
{
	return body.begin();
}

PhysicsEngine::const_iterator PhysicsEngine::end()
{
	return body.end();
}

void PhysicsEngine::Remove(Rigidbody& rb)
{
	const std::lock_guard<std::mutex> guard(bodyMutex);
	body.erase(&rb);
}

void PhysicsEngine::Add(Rigidbody& rb)
{
	const std::lock_guard<std::mutex> guard(bodyMutex);
	if (!Contain(rb)) { body.insert(&rb); }
}

void PhysicsEngine::Clear()
{
    const std::lock_guard<std::mutex> guard(bodyMutex);
    body.clear();
}

inline bool PhysicsEngine::Contain(Rigidbody& rb)
{
	return std::find(begin(), end(), &rb) != end();
}

void PhysicsEngine::Work()
{
    const double FPS = 100;
    const double DT = 1/FPS;
    CTimer t;
    double accumulator = 0;

	while (_isWork)
	{
		const std::lock_guard<std::mutex> guard(bodyMutex);;

        accumulator += t.Elapsed(true);

        if (accumulator > 3 * DT)
        {
            accumulator = 3 * DT;
        }

		while (accumulator > DT)
		{
		    if (!body.empty())
		        int i = 0;

			NarrowPhase(WidePhase());

			for (auto b : body)
			{
				Physics::UpdatePosition(*b, DT);
			}

			accumulator -= DT;
		}
	}
}

std::set<BodyPair> PhysicsEngine::WidePhase()
{
	std::set<BodyPair> potentials;

	for (auto first : body)
	{
		for (auto second : body)
		{
			if (first != second && CanCollided(*first, *second))
			{
				potentials.insert(BodyPair(first, second));
			}
		}
	}

	return potentials;
}

bool PhysicsEngine::CanCollided(Rigidbody& rb1, Rigidbody& rb2)
{
	return Mathematics::Distance(rb1.GetActualRc(), rb2.GetActualRc()) < rb1.GetBound()->GetR() + rb2.GetBound()->GetR();
}

void PhysicsEngine::NarrowPhase(std::set<BodyPair> potentials)
{
	for (auto pair : potentials)
	{
		auto poly = _interFunc[pair.first->GetShape()->GetName()][pair.second->GetShape()->GetName()](*pair.first, *pair.second);

		if (poly != nullptr)
		{
			Point cp = Physics::CenterOfMass(*poly);
			Point n = Mathematics::UnitVector(pair.first->GetActualRc() - pair.second->GetActualRc());
			float P = Physics::CalculateImpulse(*pair.first, *pair.second, cp, n);
			if (!pair.first->GetIsStatic()) { Physics::ApplyImpulse(*pair.first, cp, n, P); }
			if (!pair.second->GetIsStatic()) { Physics::ApplyImpulse(*pair.second, cp, n, -P); }
		}
	}
}

Polygon* PhysicsEngine::ConvPolyConvPoly(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::ConvPolyConvPolyIntersection(*((ConvexPolygon*)rb1.GetActualShape()), *((ConvexPolygon*)rb2.GetActualShape()));
}

Polygon* PhysicsEngine::ConvPolyCircle(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::ConvPolyCircleIntersection(*((ConvexPolygon*)rb1.GetActualShape()), *((Circle*)rb2.GetActualShape()));
}

Polygon* PhysicsEngine::CircleCircle(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::CircleCircleIntersection(*((Circle*)rb1.GetActualShape()), *((Circle*)rb2.GetActualShape()));
}

Polygon* PhysicsEngine::CircleConvPoly(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::CircleConvPolyIntersection(*((Circle*)rb1.GetActualShape()), *((ConvexPolygon*)rb2.GetActualShape()));
}
