#include "FindPeak.h"
#include <algorithm>
#include <cmath>
using namespace std;
vector<Interval> FindPeak(vector<double>& averagePpl, Time& startWork, Time& measureInt) {
	vector<int> numsOfPeakInt;
	vector<Interval> result;
	double maxAverage = 0;
	for (auto item : averagePpl) {
		if (item > maxAverage)
			maxAverage = item;
	}
	for (int i = 0; i < averagePpl.size();++i) {
		if (averagePpl.at(i) == maxAverage)
			numsOfPeakInt.push_back(i);
	}
	for (auto item : numsOfPeakInt) {
		Interval interval(startWork + measureInt * item, startWork + measureInt * (item + 1));
		result.push_back(interval);
	}
	return result;
}
