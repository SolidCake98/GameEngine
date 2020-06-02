#include "Physics.h"

using namespace PEngine;

Point Physics::CenterOfMass(const Polygon& P)
{
	Vertex* v = P.GetStart();
	Point p;

	for (int i = P.GetPower(); i > 0; i--, v = v->next)
	{
		p += v->position;
	}

	p /= P.GetPower();
	return p;
}

void Physics::UpdatePosition(Rigidbody& rb, float dt)
{
    rb.SetPosition(rb.GetPosition() + rb.GetV() * dt);
    rb.SetAngle(rb.GetAngle() + rb.GetW() * dt);
}

float Physics::CalculateImpulse(const Rigidbody& rb1, const Rigidbody& rb2, Point& cp, Point& n)
{
	Point R1 = cp - rb1.GetActualRc();
	Point R2 = cp - rb2.GetActualRc();

    // относительная скорость точек тел по контакту
	float V12 = n.x * (rb1.GetV().x - rb1.GetW() * R1.y - rb2.GetV().x + rb2.GetW() * R2.y) +
	        n.y * (rb1.GetV().y + rb1.GetW() * R1.x - rb2.GetV().y - rb2.GetW() * R2.x);

	// плечи
	float Z1 = (n.y * R1.x - n.x * R1.y) / rb1.GetI();
	float Z2 = (n.y * R2.x - n.x * R2.y) / rb2.GetI();

    // вспомагательная величина
	float J = n.x * (n.x / rb1.GetM() - R1.y * Z1 + n.x / rb2.GetM() + R2.y * Z2)
		+ n.y * (n.y / rb1.GetM() + R1.x * Z1 / rb1.GetI() + n.y / rb2.GetM() - R2.x * Z2 / rb2.GetI());

	return (MIN_V - (1 + E) * V12) / J;
}

void Physics::ApplyImpulse(Rigidbody& rb, Point& cp, Point& n, float P)
{
	rb.SetV(rb.GetV() + n * P / rb.GetM());
	Point Ra = cp - rb.GetActualRc();
    rb.SetW(rb.GetW() + P * (n.y * Ra.x - n.x * Ra.y) / rb.GetI());
}
