#include <iostream>

using namespace std;

// Variables

int iv(int);
void coinToss();

int main() {

	srand(time(NULL));

	coinToss();		

}

int iv(int num) {

	while (!(cin >> num) || num < 0) {
		cout << "Error: Value should be an integer greater than 0. Please try again: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;
}

void coinToss() {
	 
	int num{},
		result;

	cout << "\nToss Coin";
	cout << "\n-----------";
	cout << endl;
	cout << "\nHow many times would you like to toss the coin: ";

	num = iv(num);

	cout << endl;

	for (int i = 1; i <= num; i++) {

		result = rand() % 2 + 1;

		cout << (result == 1 ? "Heads" : "Tails") << endl;
	}	

}