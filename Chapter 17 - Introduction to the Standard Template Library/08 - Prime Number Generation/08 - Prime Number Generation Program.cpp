//8. Prime Number Generation
//
//A positive integer greater than 1 is said to be prime if it has no divisors other than 1 and itself.
//A positive integer greater than 1 is composite if it is not prime. Write a program that asks the
//user to enter an integer greater than 1, then display all of the prime numbers that are less than 
//or equal to the number entered. The program should work as follows:
//
//*Once the user has entered a number, the program should populate a vector with all of the integers
//from 2, up through the value entered.
//
//* The program should then use the STL's for_each function to step through the vector. The for_each
//function should pass each element to a function object that display the element if it is a prime
//number.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

void isPrime(const int&);
void primeOrComposite(const vector<int>&);

int main() {

	const int MAX_NUMBER = 100;
	const int MIN_NUMBER = 2;
	int num;

	cout << "===============================\n";
	cout << "17-08 - PRIME NUMBER GENERATION\n";
	cout << "===============================\n";
	cout << "\n";

	cout << "Enter your chosen number: ";

	while (cin >> num && (num < MIN_NUMBER || num > MAX_NUMBER)) {
		cout << "ERROR: Your chosen number must be greater than " << MIN_NUMBER + 1 << " and less than " << MAX_NUMBER << ".\n";
		cin.ignore();
		cout << "\n";
		cout << "Enter your chosen number: ";
	}

	cout << "\n";

	vector<int> numbers;
	vector<int>::iterator it;

	for (int i = num; i > 1; i--) {
		numbers.push_back(i);
	}

	primeOrComposite(numbers);
	
	cout << "Ending the program...\n";
	cout << "\n";

}

void isPrime(const int& NUM) {

	bool isNumPrime = true;

	cout << left << setw(20) << NUM;

	for (int i = NUM - 1; isNumPrime && i > 1; i--) {

		if (NUM % i == 0) {
			isNumPrime = false;
		}

	}

	if (!isNumPrime) {
		cout << "Composite";
	}
	else {
		cout << "Prime";
	}

	cout << "\n";

}

void primeOrComposite(const vector<int>& VECTOR) {

	vector<int>::const_iterator cit;

	cout << left;

	cout << setw(20) << "NUMBERS" << "RESULT" << "\n";
	cout << setfill('-') << setw(40) << "";
	cout << setfill(' ') << "\n";

	for_each(VECTOR.begin(), VECTOR.end(), isPrime);
	cout << setfill('-') << setw(40) << "";
	cout << setfill(' ') << "\n";

	cout << "\n";
	
}