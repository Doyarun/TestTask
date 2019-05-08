#include <iostream>
#include <vector>
#include<fstream>
#include "Time.h"
#include "Interval.h"
#include "FindPeak.h"


int main(){
	Time startWork(8,0,0);
	Time interval(0, 30, 0);
	vector<double> averagePpl;
	vector<Interval> result;
	ifstream input1("input1.txt");
	ifstream input2("input2.txt");
	ifstream input3("input3.txt");
	ifstream input4("input4.txt");
	ifstream input5("input5.txt");

	for (int i = 0; i < 16; i++) {
		static double buffer = 0;
		static double allAverage = 0;
		input1 >> buffer;
		allAverage = buffer;
		input2 >> buffer;
		allAverage += buffer;
		input3 >> buffer;
		allAverage += buffer;
		input4 >> buffer;
		allAverage += buffer;
		input5 >> buffer;
		allAverage += buffer;
		averagePpl.push_back(allAverage);
	}
	cout << "Time interval you're looking for is" << endl;
	result = FindPeak(averagePpl, startWork, interval);
	for (auto item : result) {
		item.PrintInterval();
	}

	system("pause");
}

