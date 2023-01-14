#include<iostream>

using namespace std;

struct Circle {

	double radius;
	double area;

};

int main() {

	Circle* newCir = nullptr;

	newCir = new Circle[5];

	newCir = nullptr;
	delete newCir;

}