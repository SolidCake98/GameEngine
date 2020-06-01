#include "Mathematics.h"

using namespace PEngine;

inline float Mathematics::SQR(float num)
{
	return num * num;
}

inline bool Mathematics::EQU(float a, float b)
{
	return fabs(a - b) < EPS;
}

Point Mathematics::UnitVector(const Point& vec)
{
	float l = sqrt(SQR(vec.x) + SQR(vec.y));
	return {vec.x / l, vec.y / l};
}

float Mathematics::Distance(const Point& p1, const Point& p2)
{
	Point p = p2 - p1;
	return sqrt(SQR(p.x) + SQR(p.y));
}

float Mathematics::AimTo(Point& a1, Point& a2, Point& b1, Point& b2)
{
	return (a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}

float Mathematics::HalfPlain(Point& a, Point& b, Point& c)
{
	return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

float Mathematics::D2(float a11, float a12, float a21, float a22)
{
	return a11 * a22 - a12 * a21;
}

bool Mathematics::LinesIntersection(Point& a1, Point& a2, Point& b1, Point& b2, Point& c)
{
	float A1 = a1.y - a2.y;
	float B1 = a2.x - a1.x;
	float A2 = b1.y - b2.y;
	float B2 = b2.x - b1.x;

	float D = D2(A1, B1, A2, B2);

	if (fabs(D) < EPS) return false;

	float C1 = a2.x * a1.y - a1.x * a2.y;
	float C2 = b2.x * b1.y - b1.x * b2.y;

	c.x = D2(C1, B1, C2, B2) / D;
	c.y = D2(A1, C1, A2, C2) / D;

	return true;
}

bool Mathematics::IsPointInLineAABB(Point& a, Point& b, Point& c)
{
	float minX = a.x - EPS;
	float minY = a.y - EPS;
	float maxX = b.x + EPS;
	float maxY = b.y + EPS;

	if (a.x > b.x) { minX = b.x - EPS; maxX = a.x + EPS; }
	if (a.y > b.y) { minY = b.y - EPS; maxY = a.y + EPS; }

	return c.x >= minX && c.x <= maxX && c.y >= minY && c.y <= maxY;
}

bool Mathematics::SegmentIntersection(Point& a1, Point& a2, Point& b1, Point& b2, Point& c)
{
	return LinesIntersection(a1, a2, b1, b2, c)
		&& IsPointInLineAABB(a1, a2, c)
		&& IsPointInLineAABB(b1, b2, c);
}

void Mathematics::AddVertex(Vertex*& current, Point& p)
{
	//if (!EQU(current->position.x, p.x) || !EQU(current->position.y, p.y))
	//{
	current->next = new Vertex(p.x, p.y);
	current = current->next;
	//}
}

void Mathematics::Advance(Vertex*& v, Vertex*& current, bool needAdd)
{
	if (needAdd) { AddVertex(current, v->next->position); }
	v = v->next;
}

bool Mathematics::IsDotInConvexPolygon(ConvexPolygon& P, Point& p)
{
	Vertex* v = P.GetStart();

	for (int i = P.GetPower(); i > 0; i--, v = v->next)
	{
		if (HalfPlain(v->position, v->next->position, p) < 0)
		{
			return false;
		}
	}

	return true;
}

Polygon* Mathematics::ConvPolyConvPolyIntersection(ConvexPolygon& P, ConvexPolygon& Q)
{
	enum { Undefined, InsideQ, InsideP, };

	Vertex* p = P.GetStart();
	Vertex* q = Q.GetStart();
	
	Vertex* first = nullptr; // первая точка результирующего полигона
	Vertex* current = nullptr; // текущая точка результирующего полигона

	Point c;

	int inflag = Undefined;
	int iterations = 2 * (P.GetPower() + Q.GetPower());

	for (int i = 0; i < iterations; i++)
	{
		if (SegmentIntersection(p->position, p->next->position, q->position, q->next->position, c))
		{
			inflag = (HalfPlain(q->position, q->next->position, p->next->position) > 0)
				? InsideP : (HalfPlain(p->position, p->next->position, q->next->position) > 0)
				? InsideQ : inflag;

			if (first == nullptr)
			{
				current = first = new Vertex();
				current->position = Point(c.x, c.y);
			}
			else if (fabs(first->position.x - c.x) < EPS && fabs(first->position.y - c.y) < EPS)
			{
				current->next = first;
				return new Polygon(current);
			}
			else
			{
				AddVertex(current, c);
			}
		}

        if (AimTo(p->position, p->next->position, q->position, q->next->position) >= 0)
		{
            float hp = HalfPlain(p->position, p->next->position, q->next->position);
			if (hp > 0)
			{
				Advance(p, current, inflag == InsideP);
			}
			else
			{
				Advance(q, current, inflag == InsideQ);
			}
		}
		else
		{
            float hp = HalfPlain(q->position, q->next->position, p->next->position);
			if (hp > 0)
			{
				Advance(q, current, inflag == InsideQ);
			}
			else
			{
				Advance(p, current, inflag == InsideP);
			}
		}
	}

	if (IsDotInConvexPolygon(Q, p->position)) { return &P; }
	else if (IsDotInConvexPolygon(P, q->position)) { return &Q; }
	else { return nullptr; }
}

bool Mathematics::IsDotInCircle(Circle& circle, Point& p)
{
	return Distance(circle.GetCenter(), p) <= circle.GetR();
}

Vertex* Mathematics::CircleLineIntersection(Circle& circle, Point& a, Point& b)
{
    // переход в начало координат
	Point na = a - circle.GetCenter();
	Point nb = b - circle.GetCenter();

	float A = na.y - nb.y;
	float B = nb.x - na.x;
	float C = nb.x * na.y - na.x * nb.y;

	float x0 = A * C / (SQR(A) + SQR(B));
	float y0 = B * C / (SQR(A) + SQR(B));

	float r = C / sqrt(SQR(A) + SQR(B));

	if (r > circle.GetR())
	{
		return nullptr;
	}
	else if (EQU(r, circle.GetR()))
	{
		Vertex* v = new Vertex(x0 + circle.GetCenter().x, y0 + circle.GetCenter().y);
		return v;
	}
	else
	{
		float mult = sqrt((SQR(circle.GetR()) - SQR(r)) / (SQR(A) + SQR(B)));

		float x1 = x0 + B * mult;
		float y1 = y0 - A * mult;
		float x2 = x0 - B * mult;
		float y2 = y0 + A * mult;

        // возврат к исходным координатам
		Vertex* v1 = new Vertex(x1 + circle.GetCenter().x, y1 + circle.GetCenter().y);
		Vertex* v2 = new Vertex(x2 + circle.GetCenter().x, y2 + circle.GetCenter().y);
		v1->next = v2;
		return v1;
	}
}

Vertex* Mathematics::CircleSegmentIntersection(Circle& circle, Point& a, Point& b)
{
	Vertex* segment = CircleLineIntersection(circle, a, b);

	if (segment == nullptr)
	{
		return nullptr;
	}
	else
	{
		Vertex* first = new Vertex();
		Vertex* current = first;
		Vertex* prev;

		while (segment != nullptr)
		{
			if (IsPointInLineAABB(a, b, segment->position)) { AddVertex(current, segment->position); }

			prev = segment;
			segment = segment->next;
			delete prev;
		}

		current = first->next;
		delete first;
		return current;
	}
}

Point Mathematics::SearchSectorHPoint(Circle& circle, Point& p1, Point& p2)
{
	Point p = (p1 + p2) / 2;
	Point r = p - circle.GetCenter();
	r = UnitVector(r);
	return p + r * (circle.GetR() - Distance(circle.GetCenter(), p));
}

Polygon* Mathematics::CircleConvPolyIntersection(Circle& circle, ConvexPolygon& convPoly)
{
	Vertex* v = convPoly.GetStart();
	Vertex* first = new Vertex();
	Vertex* current = first;
	Vertex* prev;
	int vertexes = 0;

	for (int i = 0; i < convPoly.GetPower(); i++, v = v->next)
	{
		if (IsDotInCircle(circle, v->position)) { AddVertex(current, v->position); }
		current->next = CircleSegmentIntersection(circle, v->position, v->next->position);
		for (; current->next != nullptr; current = current->next, vertexes++);
	}

	current->next = first->next;
	delete first;

	if (vertexes == 0) { return nullptr; }
	else { return new Polygon(current); }
}

Polygon* Mathematics::ConvPolyCircleIntersection(ConvexPolygon& convPoly, Circle& circle)
{
	return CircleConvPolyIntersection(circle, convPoly);
}

Polygon* Mathematics::CircleCircleIntersection(Circle& c1, Circle& c2)
{
	Circle nc1 = Circle(Point(0, 0), c1.GetR()); // первая окружность, перенесенная в начало координат
	Circle nc2 = Circle(c2.GetCenter() - c1.GetCenter(), c2.GetR()); // перенесенная соответственно вторая окружность�

	float A = -2 * nc2.GetCenter().x;
	float B = -2 * nc2.GetCenter().y;
	float C = SQR(nc2.GetCenter().x) + SQR(nc2.GetCenter().y) + SQR(nc1.GetR()) - SQR(nc2.GetR());

	Point p1(0, -C / B);
	Point p2(-C / A, 0);

	if (B == 0)
	{
	    Vertex* v = new Vertex(p2 + c1.GetCenter());
	    v->next = v;
	    return new Polygon(v);
	}
	if (A == 0)
	{
        Vertex* v = new Vertex(p1 + c1.GetCenter());
        v->next = v;
        return new Polygon(v);
    }

	Vertex* inters = CircleLineIntersection(nc1, p1, p2);

	if (inters == nullptr) // нет пересечений
	{
		return nullptr;
	}
	else if (inters->next == nullptr) // 1 точка пересечения
	{
		inters->next = inters;
		inters->position += c1.GetCenter();
		return new Polygon(inters);
	}
	else // 2 точки пересечения
	{
        Vertex* first;
        Vertex* current;

		current = first = new Vertex(SearchSectorHPoint(nc1, inters->position, inters->next->position) + c1.GetCenter());
		current->next = new Vertex(inters->position + c1.GetCenter());
		current = current->next;
		current->next = new Vertex(SearchSectorHPoint(nc2, inters->position, inters->next->position) + c1.GetCenter());
		current = current->next;
		current->next = new Vertex(inters->next->position + c1.GetCenter());
		current = current->next;
		current->next = first;
		return new Polygon(first);
	}
}

Point Mathematics::Rotate(const Point &p, float angle)
{
    float sinA = sin(angle);
    float cosA = cos(angle);
    float x = p.x * cosA - p.y * sinA;
    float y = p.y * cosA + p.x * sinA;
    return {x, y};
}
