#include "FeetInches.h"
#include <iostream>

using namespace std;

int main() {

	FeetInches person_height(5, 4);
	FeetInches person_clone(person_height);
	FeetInches new_person;

	cout << "-----------------------------\n";
	cout << "14-11 FeetInches Copy Constructor and Multiply Function Demonstration\n";
	cout << "-----------------------------\n";
	cout << "\n";

	cout << "Original Person: " << person_height << "\n";
	cout << "Clone Person: " << person_clone << "\n";

	new_person = person_height.multiply(person_clone);

	cout << "\n";

	cout << "The height of NEW PERSON will be (ORIGINAL PERSON * CLONE PERSON)...\n";
	cout << "New person: " << new_person << "\n";



}