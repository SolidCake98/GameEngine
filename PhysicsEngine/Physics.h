#pragma once

#include "Rigidbody.h"

class Physics
{
public:
	// ��������:
	// ����� ���� ����� ���� �������������� (��� ����� ���� ������� ����� (������� ��������������))
	// ����������:
	// �����, � ������� ��������� ����� ����
	static Point CenterOfMass(const Polygon& P);

	// ��������:
	// ����� ���������� ����
	// ���������:
	// rb - ����
	// dt - �������� ������� � ���������� ������
	static void UpdatePosition(Rigidbody& rb, float dt);

	// ��������:
	// ����� ��������� ������� �������� ����������
	static float CalculateImpulse(const Rigidbody& rb1, const Rigidbody& rb2, Point& cp, Point& n);

	// ��������:
	// ����� ��������� ������� � ����
	// ���������:
	// rb - ����, � �������� ����������� �������
	// cp - ����� ��������
	// n - ������� ��������
	// P - �������� �������� (������)
	static void ApplyImpulse(Rigidbody& rb, Point& cp, Point& n, float P);
};