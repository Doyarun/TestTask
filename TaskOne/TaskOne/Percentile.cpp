#include "Percentile.h"

using namespace std;


int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

double Percentile(double percNum, vector<int> & myVector) {

	if (percNum < 0 || percNum>100) {
		cout << "Percentiles value is out of boundary\n";
		exit(0);
	}

//	qsort(&myVector[0], myVector.size(), sizeof(int), compare);

	if (myVector.size() == 1) {
		return myVector[0];
	}


	double 	interval = 1.0 / (myVector.size() - 1); 	int leftBoundInd = static_cast<int>((percNum / 100.0) / interval);
	int rightBoundInd;
	if (leftBoundInd == myVector.size() - 1)
		rightBoundInd = leftBoundInd;
	else
		rightBoundInd = leftBoundInd + 1;



	double percentile = ((((percNum / 100.0) - interval * leftBoundInd) / interval)) * (myVector[rightBoundInd] - myVector[leftBoundInd]) + myVector[leftBoundInd];
	return percentile;
}