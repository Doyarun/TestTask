#include "Triangle.h"



Triangle::Triangle()
{
}

Triangle::Triangle(Point a, Point b, Point c) {
	_a = a;
	_b = b;
	_c = c;
}

Triangle::~Triangle()
{
}

std::string Triangle::isPointInTriangle(Point& point)
{
	if (point == _a || point == _b || point == _c)
		return "PointIsNode";
	double con1, con2, con3;
	con1 = (_a.GetX() - point.GetX()) * (_b.GetY() - _a.GetY()) - (_b.GetX() - _a.GetX()) * (_a.GetY() - point.GetY());
	con2 = (_b.GetX() - point.GetX()) * (_c.GetY() - _b.GetY()) - (_c.GetX() - _b.GetX()) * (_b.GetY() - point.GetY());
	con3 = (_c.GetX() - point.GetX()) * (_a.GetY() - _c.GetY()) - (_a.GetX() - _c.GetX()) * (_c.GetY() - point.GetY());
	if (con1 > 0 || con2 > 0 || con3 > 0)
		return "Outside";
	else if (con1 == 0)
		return "PointOnAB";
	else if (con2 == 0)
		return "PointOnBC";
	else if (con3 == 0)
		return "PointOnCA";
	else if ((con1 < 0 && con2 < 0 && con3 < 0) || (con1 > 0 && con2 > 0 && con3 > 0))
		return "Inside";
	else
		return "Outside";
}
