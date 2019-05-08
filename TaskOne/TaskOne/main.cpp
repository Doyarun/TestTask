#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Percentile.h"

using namespace std;

double Average(vector <int>& numbers) {
	double average = 0;
	for (auto item : numbers) {
		average += item;
	}
	average = average / numbers.size();
	return average;
}

int main()
{
	ifstream input("input.txt");
	vector<int> numbers;
	 if(input) {
		while (!input.eof()) {
			int i;
			input >> i;
			numbers.push_back(i);
		}
	}
	sort(numbers.begin(), numbers.end());
	cout << "90 percentile " << Percentile(90, numbers) << endl;
	cout << "median " << Percentile(50, numbers) << endl;
	cout << "average " << Average(numbers) << endl;
	cout << "max " << numbers.at(numbers.size() - 1) << endl;
	cout << "min " << numbers[0] << endl;
	system("pause");
	return 0;
}

