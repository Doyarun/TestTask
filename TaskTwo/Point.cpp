#include "Point.h"


Point::Point() {
	SetX(0);
	SetY(0);
}

Point::Point(const Point& point) {
	SetX(point.GetX());
	SetY(point.GetY());
}
Point::Point(int x, int y) {
	SetX(x);
	SetY(y);
}

void Point:: SetX(int x) {
	_x = x;
}
void Point::SetY(int y) {
	_y = y;
}
double Point:: GetX() const {
	return _x;
	}
double Point:: GetY() const {
	return _y;
}

Point::~Point()
{
}

void Point::operator =(Point point) {
	SetX(point.GetX());
	SetY(point.GetY());
}

bool Point::operator==(const Point& point)
{
	if (_x == point.GetX() && _y == point.GetY())
		return true;
	else
		return false;
}
