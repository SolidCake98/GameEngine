#pragma once

#include "Polygon.h"
#include "Circle.h"
#include "Mathematics.h"

class Rigidbody
{
public:	
	Rigidbody(ConvexPolygon& polygon, float M, float I, bool isStatic = false);
	Rigidbody(Circle& circle, float M, float I, bool isStatic = false);
	~Rigidbody();

	const Shape* GetShape();

	const Circle* GetBound();

	float GetM() const;
	void SetM(float M);

	float GetI() const;
	void SetI(float I);

	float GetAngle() const;
	void SetAngle(float angle);

	float GetW() const;
	void SetW(float W);

	Point GetPosition() const;
	void SetPosition(Point position);

	Point GetRc() const;
	void SetRc(Point Rc);

	Point GetV() const;
	void SetV(Point V);
	
	bool GetIsStatic() const;
	void SetIsStatic(bool isStatic);

	Point GetActualRc() const;

	Shape* GetActualShape() const;

private:
	Shape* _shape; // форма тела
	Circle* _bound; // ограничивающая окружность
	float _M; // масса тела
	float _I; // момент инерции
	float _angle; // угол поворота тела
	float _W; // угловая скорость тела
	Point _position; // позиция тела
	Point _Rc; // центр масс
	Point _V; // скорость тела
	bool _isStatic; // статично ли тело

	void Init(float M, float I, bool isStatic);
};