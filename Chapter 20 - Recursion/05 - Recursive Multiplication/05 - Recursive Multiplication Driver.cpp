//5. Recursive Multiplication
//
//Write a recursive function that aceepts two arguments into the parameters x and y. The function
//should retun the value of x times y. Remember, multiplication can be performed as repeated 
//addition:
//
//7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

int recursiveMultiplication(int, int);

int main() {

	cout << "=====================================\n";
	cout << "20-05 RECURSIVE MULTIPLICATION DRIVER\n";
	cout << "=====================================\n";
	cout << "\n";

	int value_1, value_2;

	cout << "First number: ";
	cin >> value_1;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Second number: ";
	cin >> value_2;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n";

	cout << value_1 << " times " << value_2 << " via recursive multiplication = " << recursiveMultiplication(value_1, value_2) << ".\n";

	cout << "\n";

	cout << "Ending the program...\n";

}

int recursiveMultiplication(int x, int y) {

	if (x < 0) {
		x *= -1;
		y *= -1;
	}
	
	if (x > 0) {
		return y + recursiveMultiplication(x - 1, y);
	}

	else {
		return 0;
	}


}