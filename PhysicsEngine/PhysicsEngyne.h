#pragma once

#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>
#include "Physics.h"
#include "BodyPair.h"

class PhysicsEngyne
{
public:
	typedef std::set<Rigidbody*>::iterator iterator;

	std::set<Rigidbody*> body;

	PhysicsEngyne();
	~PhysicsEngyne();

	void Start();
	void Stop();
	
	iterator begin();
	iterator end();

	void Remove(Rigidbody& rb);
	void Add(Rigidbody& rb);
	bool Contain(Rigidbody& rb);

private:
	typedef Polygon* (*pfunc)(const Rigidbody&, const Rigidbody&);

	const float FPS = 30;
	const unsigned int DT = 1000 / FPS;
	bool _isWork;	
	std::mutex bodyMutex;

	std::map<std::string, std::map<std::string, pfunc>> _interFunc =
	{
		{"ConvexPolygon",
			{
				{"ConvexPolygon", ConvPolyConvPoly},
				{"Circle", ConvPolyCircle},
			}
		},
		{"Circle",
			{
				{"ConvexPolygon", CircleConvPoly},
				{"Circle", CircleCircle},
			}
		},
	};

	void Work();
	std::set<BodyPair> WidePhase();
	bool CanCollided(Rigidbody& rb1, Rigidbody& rb2);
	void NarrowPhase(std::set<BodyPair> potentials);

	static Polygon* ConvPolyConvPoly(const Rigidbody& rb1, const Rigidbody& rb2);
	static Polygon* ConvPolyCircle(const Rigidbody& rb1, const Rigidbody& rb2);
	static Polygon* CircleCircle(const Rigidbody& rb1, const Rigidbody& rb2);
	static Polygon* CircleConvPoly(const Rigidbody& rb1, const Rigidbody& rb2);
};