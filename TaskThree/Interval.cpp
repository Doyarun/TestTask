#include "Interval.h"

Interval::Interval()
{	
}

Interval::Interval(const Time& begin,const Time& end) {
	SetInterval(begin, end);
}
Interval::Interval(const Interval& newInterval) {
	intervalBeginTime = newInterval.GetBeginTime();
	intervalEndTime = newInterval.GetEndTime();
}

Time Interval::GetBeginTime() const{
	Time beginTime;
	beginTime.SetH(intervalBeginTime.hour());
	beginTime.SetM(intervalBeginTime.minute());
	beginTime.SetS(intervalBeginTime.second());
	return beginTime;
}
Time Interval::GetEndTime() const{
	Time endTime;
	endTime.SetH(intervalEndTime.hour());
	endTime.SetM(intervalEndTime.minute());
	endTime.SetS(intervalEndTime.second());
	return endTime;
}
void Interval::SetInterval(const Time& begin,const Time& end) {
	intervalBeginTime.SetH(begin.hour());
	intervalBeginTime.SetM(begin.minute());
	intervalBeginTime.SetS(begin.second());

	intervalEndTime.SetH(end.hour());
	intervalEndTime.SetM(end.minute());
	intervalEndTime.SetS(end.second());
}

void Interval::PrintInterval()const {
	cout << intervalBeginTime << " - " << intervalEndTime << endl;
}
Interval::~Interval()
{
}
