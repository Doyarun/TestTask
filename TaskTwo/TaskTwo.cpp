#include <iostream>
#include <fstream>
#include <vector>
#include "Point.h"
#include "Triangle.h"

using namespace std;

int main()
{
	int n = 4;								//по условию задачи у нас четырехугольник
	double buffer = 0;
	Point point;
	vector <Point> quadrilateral;
	ifstream input("input.txt");
	if(input){
		for (int i = 0; i < n; ++i) {		//считываем  из файла координаты вершин четырехугольник
			Point add;
			input >> buffer;
			add.SetX(buffer);
			input >> buffer;
			add.SetY(buffer);
			quadrilateral.push_back(add);
		}
	}
	cin >> buffer;							//считываем из консоли координаты точки для проверки
	point.SetX(buffer);
	cin >> buffer;
	point.SetY(buffer);
	/*Проверять принадлежность точки нашему четырехугольнику будем следующим образом:
	Делим четырехугольник на 2 треугольника и проверяем принадлежность точки этим треугольникам*/
	Triangle first(quadrilateral[0], quadrilateral[1], quadrilateral[2]);
	Triangle second(quadrilateral[0], quadrilateral[2], quadrilateral[3]);

	if (first.isPointInTriangle(point) == "PointIsNode" || second.isPointInTriangle(point) == "PointIsNode")
		cout << "Your point is the node" << endl;				//Если координаты точки равны координатам одной из вершин, то они совпадают
	else if ((first.isPointInTriangle(point) == "Inside" || second.isPointInTriangle(point) == "Inside") ||
		(first.isPointInTriangle(point) == "PointOnCA" && second.isPointInTriangle(point) == "PointOnAB"))
		cout << "Your point inside of the quadrilateral";		//Если точка принадлежит хотя бы одному из треугольников 
																//или лежит на их общей стороне, то точка принадлежит 4х-угольнику
	else if (first.isPointInTriangle(point) == "Outside" && second.isPointInTriangle(point) == "Outside")
		cout << "Your point outside of the quadrilateral";		//Если не ринадлежит ни одному треугольнику, то точка снаружи
	else
		cout << "Your point is on the side";					//Иначе лежит на одной из сторон
	system("pause");
	return 0;
}