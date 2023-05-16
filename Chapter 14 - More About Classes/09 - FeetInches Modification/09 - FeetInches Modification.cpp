#include "FeetInches.h"

using namespace std;

int main() {

	FeetInches size_1(6, 3);
	FeetInches size_2(6, 3);

	if (size_1 <= size_2) {
		cout << "Size 1 is less than or equal to Size 2.\n";
		cout << "\n";
	}
	else {
		cout << "Size 2 is less than Size 1.\n";
		cout << "\n";
	}

	if (size_1 >= size_2) {
		cout << "Size 1 is greater than or equal to Size 2.\n";
		cout << "\n";
	}
	else {
		cout << "Size 2 is less than Size 1.\n";
		cout << "\n";
	}

	if (size_1 != size_2) {
		cout << "Size 1 is not equal to Size 2.\n";
		cout << "\n";
	}
	else {
		cout << "Size 2 is equal to Size 1.\n";
		cout << "\n";
	}

}