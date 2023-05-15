#include "Date.h"
#include <iostream>

using namespace std;

int main() {

	Date special_day(5,15,2023);
	Date special_day_2(11, 7, 1964);

	int difference;
	
	for (int i = 0; i < 365; i++) {
		cout << special_day++ << " - INCREMENTING...\n";
	}

	cout << "\n";
	cout << "=====================================================================================================\n";
	cout << "\n";

	for (int i = 0; i < 365; i++) {
		cout << special_day-- << " - DECREMENTING...\n";
	}

	cout << "\n";
	cout << "=====================================================================================================\n";
	cout << "\n";

	difference = special_day - special_day_2;

	cout << difference << "\n";

	cin >> special_day_2;

}