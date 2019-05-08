#include "Time.h"

using namespace std;


Time::Time() : _hour(0), _minute(0), _second(0) {}
Time::Time(int h, int m, int s) : _hour(h), _minute(m), _second(s) { optimize(); }
void Time:: optimize(){
	_minute += _second / 60;
	_second = _second % 60;
	_minute += ((_second < 0) ? -1 : 0);
	_second += ((_second < 0) ? 60 : 0);
	_hour += _minute / 60;
	_minute = _minute % 60;
	_hour += ((_minute < 0) ? -1 : 0);
	_minute += ((_minute < 0) ? 60 : 0);
}
int Time::hour() const { 
	return _hour; 
}
int Time::minute() const { 
	return _minute; 
}
int Time::second() const { 
	return _second; 
}
void Time:: SetH(int h) {
	_hour = h;
}
void Time::SetM(int m) {
	_minute = m;
}
void Time::SetS(int s) {
	_second = s;
}
ostream&  operator<< (ostream & o, const Time & t)
{
	o << ((t.hour() < 10) ? "0" : "") << t.hour() << ":"
		<< ((t.minute() < 10) ? "0" : "") << t.minute() << ":"
		<< ((t.second() < 10) ? "0" : "") << t.second();
	return o;
}

Time::Time(Time & other)
{
	_hour = other._hour;
	_minute = other._minute;
	_second = other._second;
}
const Time Time::operator+(const Time & other) const
{
	Time result(other.hour() + _hour, other.minute() + _minute, other.second() + _second);
	return result;
}
const Time Time::operator-(const Time & other) const
{
	Time result(_hour - other.hour(), _minute - other.minute(), _second - other.second());
	return result;
}
const Time Time::operator *(int n) const
{
	Time result(_hour*n, _minute*n, _second*n);
	result.optimize();
	return result;
}
const signed int Time::compare(const Time & other) const
{
	if (_hour < other.hour())
		return -1;
	else
		if (_hour > other.hour())
			return +1;
		else
			if (_minute < other.minute())
				return -1;
			else
				if (_hour > other.hour())
					return +1;
				else
					if (_second < other.second())
						return -1;
					else
						if (_second > other.second())
							return +1;
	return 0;
}

const bool Time::operator<(const Time & other) const
{
	return (compare(other) < 0);
}
const bool Time::operator>(const Time & other) const
{
	return (compare(other) > 0);
}
const bool Time::operator==(const Time & other) const
{
	return (compare(other) == 0);
}




Time::~Time()
{
}
