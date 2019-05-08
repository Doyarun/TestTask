#pragma once
#include "Point.h"
#include <string>

class Triangle
{
private:
	Point _a, _b, _c;
public:
	Triangle();
	Triangle(Point one, Point two, Point three);
	virtual ~Triangle();
	std::string isPointInTriangle(Point& point);
};

