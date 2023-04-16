#include "Patient.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Patient::getAllOperations() {

	for (int i = 0; i < list_of_operations.size(); i++) {

		if (i != 0) {
			cout << ", ";
		}
		
		cout << list_of_operations[i];

	}

}