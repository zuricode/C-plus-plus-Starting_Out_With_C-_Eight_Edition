#include <iostream>
#include <fstream>

using namespace std;

double getArea(double, double);

int main() {

	double area;

	ofstream outputFile;
	outputFile.open("C:/Users/Admin/Desktop/test.txt");

	area = getArea(5.0, 4.0);

	cout << area << endl;

	outputFile << area << endl;


	outputFile.close();
}

double getArea(double length, double width) {

	return length * width;

}