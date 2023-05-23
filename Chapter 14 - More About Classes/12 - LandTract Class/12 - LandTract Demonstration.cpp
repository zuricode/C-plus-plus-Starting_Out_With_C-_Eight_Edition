#include "LandTract.h"
#include <iomanip>

using namespace std;

void enterLandData(LandTract &);

int main() {

	LandTract land_1;
	LandTract land_2;

	cout << "-------------------------------------\n";
	cout << "14-12 LANDTRACK PROGRAM DEMONSTRATION\n";
	cout << "-------------------------------------\n";

	cout << "\n";

	cout << "LAND #1\n";
	cout << "--------\n";

	enterLandData(land_1);

	cout << "LAND #2\n";
	cout << "--------\n";

	enterLandData(land_2);

	cout << fixed << setprecision(2);

	cout << "Land #1 Area: " << land_1.getArea() << " sq ft.\n";
	cout << "Land #2 Area: " << land_2.getArea() << " sq ft.\n";

	if (land_1.getArea() == land_2.getArea()) {
		cout << "Both plots of land are the same size.\n";
	}
	else {
		cout << "The plots of land are not equal in size.\n";
	}

}

void enterLandData(LandTract& l) {

	cout << "Enter the length of your piece of land...\n";
	l.setLength();

	cout << "\n";

	cout << "Enter the width of your piece of land...\n";
	l.setWidth();

	cout << "\n";


}