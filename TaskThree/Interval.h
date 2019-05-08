#pragma once
#include "Time.h"

class Interval
{
private:
	Time intervalBeginTime;
	Time intervalEndTime;
public:
	Interval();
	Interval(const Time& begin,const Time& end);
	Interval(const Interval& newInterval);
	Time GetBeginTime()const;
	Time GetEndTime()const;
	void SetInterval(const Time& begin,const Time& end);
	void PrintInterval() const;
	virtual ~Interval();
};

