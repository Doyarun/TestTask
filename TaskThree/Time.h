#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	int _hour, _minute, _second;
public:
	Time();
	Time(int h, int m, int s) ;
	void optimize();
	int hour() const; 
	int minute() const;
	int second() const;
	void SetH(int h);
	void SetM(int m);
	void SetS(int s);
	friend ostream& operator<< (ostream& o, const Time& t);

	Time(Time& other);

	const Time operator+(const Time& other) const;
	const Time operator-(const Time& other) const;
	const Time operator*(int n) const;

	const signed int compare(const Time& other) const;

	const bool operator<(const Time& other) const;
	const bool operator>(const Time& other) const;

	const bool operator==(const Time& other) const;
	~Time();
};
