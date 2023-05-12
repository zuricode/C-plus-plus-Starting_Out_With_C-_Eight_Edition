#include "Date.h"
#include <iostream>

using namespace std;

int main() {

	Date special_day;

	cin >> special_day;
	
	for (int i = 0; i < 365; i++) {
		cout << special_day++ << " - INCREMENTING...\n";
	}

	cout << "\n";
	cout << "=====================================================================================================\n";
	cout << "\n";

	for (int i = 0; i < 365; i++) {
		cout << special_day-- << " - DECREMENTING...\n";
	}


}