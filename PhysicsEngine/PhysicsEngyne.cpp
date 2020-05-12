#include "PhysicsEngyne.h"

PhysicsEngyne::PhysicsEngyne()
{
	_isWork = false;
}

PhysicsEngyne::~PhysicsEngyne()
{
	body.clear();
}

void PhysicsEngyne::Start()
{
	_isWork = true;
	std::thread t(&PhysicsEngyne::Work, this);
	t.join();
}

void PhysicsEngyne::Stop()
{
	_isWork = false;
}

PhysicsEngyne::iterator PhysicsEngyne::begin()
{
	return body.begin();
}

PhysicsEngyne::iterator PhysicsEngyne::end()
{
	return body.end();
}

void PhysicsEngyne::Remove(Rigidbody& rb)
{
	const std::lock_guard<std::mutex> guard(bodyMutex);
	body.erase(&rb);
}

void PhysicsEngyne::Add(Rigidbody& rb)
{
	const std::lock_guard<std::mutex> guard(bodyMutex);
	body.insert(&rb);
}

inline bool PhysicsEngyne::Contain(Rigidbody& rb)
{
	return std::find(begin(), end(), &rb) != end();
}

void PhysicsEngyne::Work()
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

		// Избавляемся от "спирали смерти"
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

std::set<BodyPair> PhysicsEngyne::WidePhase()
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

bool PhysicsEngyne::CanCollided(Rigidbody& rb1, Rigidbody& rb2)
{
	return Mathematics::Distance(rb1.GetActualRc(), rb2.GetActualRc()) < rb1.GetBound()->GetR() + rb2.GetBound()->GetR();
}

void PhysicsEngyne::NarrowPhase(std::set<BodyPair> potentials)
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

Polygon* PhysicsEngyne::ConvPolyConvPoly(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::ConvPolyConvPolyIntersection(*((ConvexPolygon*)rb1.GetActualShape()), *((ConvexPolygon*)rb2.GetActualShape()));
}

Polygon* PhysicsEngyne::ConvPolyCircle(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::ConvPolyCircleIntersection(*((ConvexPolygon*)rb1.GetActualShape()), *((Circle*)rb2.GetActualShape()));
}

Polygon* PhysicsEngyne::CircleCircle(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::CircleCircleIntersection(*((Circle*)rb1.GetActualShape()), *((Circle*)rb2.GetActualShape()));
}

Polygon* PhysicsEngyne::CircleConvPoly(const Rigidbody& rb1, const Rigidbody& rb2)
{
	return Mathematics::CircleConvPolyIntersection(*((Circle*)rb1.GetActualShape()), *((ConvexPolygon*)rb2.GetActualShape()));
}
