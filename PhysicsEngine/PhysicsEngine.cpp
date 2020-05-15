#include "PhysicsEngine.h"

using namespace PEngine;

PhysicsEngine::PhysicsEngine()
{
	_isWork = false;
}

PhysicsEngine::~PhysicsEngine()
{
    _isWork = false;
    physicsThread->join();
    delete physicsThread;
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
    delete physicsThread;
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
	auto prev = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	std::chrono::microseconds accumulator;
	std::chrono::microseconds dt(DT);

	while (_isWork)
	{
		const std::lock_guard<std::mutex> guard(bodyMutex);

		auto now = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
		accumulator += now - prev;
		prev = now;

		// избавляемся от "петли смерти"
		if (accumulator > 3 * dt) { accumulator = 3 * dt; }

		while (accumulator > dt)
		{
			NarrowPhase(WidePhase());

			for (auto b : body)
			{
				Physics::UpdatePosition(*b, DT);
			}

			accumulator -= dt;
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
			if (&first != &second && CanCollided(*first, *second))
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
			Point n = pair.second->GetActualRc() - pair.first->GetActualRc();
			float P = Physics::CalculateImpulse(*pair.first, *pair.second, cp, n);

			if (!pair.first->GetIsStatic()) { Physics::ApplyImpulse(*pair.first, cp, n, P); }
			if (!pair.second->GetIsStatic()) { Physics::ApplyImpulse(*pair.first, cp, n, -P); }			
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
