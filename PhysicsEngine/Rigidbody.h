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
	Shape* _shape; // ����� ����
	Circle* _bound;
	float _M; // ����� ����
	float _I; // ������ �������
	float _angle; // ���� �������� ����
	float _W; // ������� ��������
	Point _position; // ������� ����
	Point _Rc; // ����� ����
	Point _V; // ��������	
	bool _isStatic; // ��������� �� ����

	void Init(float M, float I, bool isStatic);
};