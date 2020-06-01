#include "Rigidbody.h"

using namespace PEngine;

Rigidbody::Rigidbody(ConvexPolygon& polygon, float M, float I, bool isStatic)
{
	Init(M, I, isStatic);
	_shape = &polygon;
	Vertex* v = polygon.GetStart();

    // находим центр масс
	for (int i = polygon.GetPower(); i > 0; i--, v = v->next)
	{
		_Rc += v->position;
	}

	_Rc /= polygon.GetPower();

	v = polygon.GetStart();
	Vertex* mv = v;

    // ищем ограничевающую окружность
	for (int i = polygon.GetPower(); i > 0; i--, v = v->next)
	{
		if (Mathematics::Distance(_Rc, v->position) > Mathematics::Distance(_Rc, mv->position))
		{
			mv = v;
		}
	}

	_bound = new Circle(_Rc, Mathematics::Distance(_Rc, mv->position));
}

Rigidbody::Rigidbody(Circle& circle, float M, float I, bool isStatic)
{
	Init(M, I, isStatic);
	_shape = &circle;
	_bound = &circle;
	_Rc = circle.GetCenter();
}

void Rigidbody::Init(float M, float I, bool isStatic)
{
	if (M <= 0) { throw std::invalid_argument("Mass must be positive"); }
	if (I <= 0) { throw std::invalid_argument("Moment of inertia must be positive"); }

	_M = M;
	_I = I;
	_isStatic = isStatic;
	_angle = 0;
	_W = 0;
}

Rigidbody::~Rigidbody()
{
	delete _shape;
	delete _bound;
}

const Shape* Rigidbody::GetShape() { return _shape; }

const Circle* Rigidbody::GetBound() { return _bound; }

float Rigidbody::GetM() const { return _M; }

void Rigidbody::SetM(float M) { _M = M; }

float Rigidbody::GetI() const { return _I; }

void Rigidbody::SetI(float I) { _I = I; }

float Rigidbody::GetAngle() const { return _angle; }

void Rigidbody::SetAngle(float angle) { _angle = angle; }

float Rigidbody::GetW() const { return _W; }

void Rigidbody::SetW(float W) { _W = W; }

Point Rigidbody::GetPosition() const { return _position; }

void Rigidbody::SetPosition(Point position) { _position = position; }

Point Rigidbody::GetRc() const { return _Rc; }

void Rigidbody::SetRc(Point Rc) { _Rc = Rc; }

Point Rigidbody::GetV() const { return _V; }

void Rigidbody::SetV(Point V) { _V = V; }

bool Rigidbody::GetIsStatic() const { return _isStatic; }

void Rigidbody::SetIsStatic(bool isStatic) { _isStatic = isStatic; }

Point Rigidbody::GetActualRc() const { return Mathematics::Rotate(_Rc, _angle) + _position; }

Shape* Rigidbody::GetActualShape() const { return _shape->Paralax(_position, _angle); }
