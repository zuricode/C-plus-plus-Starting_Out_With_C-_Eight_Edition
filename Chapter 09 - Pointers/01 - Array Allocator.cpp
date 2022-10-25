#include<iostream>

using namespace std;

int *createMemory(const int);

int main() {

	const int SIZE{ 5 };

	int *numbers = createMemory(SIZE);

	for (int i = 0; i < SIZE; i++) {
		
		cout << "Enter #" << i + 1 << ": ";
		cin >> *(numbers + i);		
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++) {

		cout << "Number #" << i + 1 << ": " << *(numbers + i) << endl;

	}

	cout << endl;
	
	delete [] numbers;
	numbers = nullptr;

}

int *createMemory(const int size) {

	return new int[size];

}