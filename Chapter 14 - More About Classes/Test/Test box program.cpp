#include "box.h"
#include <iostream>

using namespace std;

int main() {

	Box parcel(256, 80);

	cout << "Your parcel has an area of " << parcel.getArea() << " square millimetres (" << parcel.getArea() / 100 << " square cm).\n";
	cout << "\n";

}