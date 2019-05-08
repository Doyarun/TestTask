#pragma once
class Point
{
private:
	double _x, _y;

public:
	Point();
	Point(const Point &point);
	Point(int x, int y);

	void SetX(int x);
	void SetY(int y);
	double GetX() const;
	double GetY() const;
	virtual ~Point();

	void operator =(Point newPoint);
	bool operator== (const Point& point);
};

