//9. String Reverser
//
//Write a recursive function that accepts a string object as its argument and prints the string in 
//reverse order. Demonstrate the function in a driver program.

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

void reverser(string);

int main() {

	cout << "============================\n";
	cout << "20-09 STRING REVERSER DRIVER\n";
	cout << "============================\n";
	cout << "\n";

	string original;

	cout << "Enter a string to reverse: ";

	getline(cin, original);

	cout << "\n";

	cout << "Original: " << original << "\n";
	cout << "Reversed: ";
	reverser(original);
	cout << "\n";

	cout << "\n";
	cout << "Ending the program...\n";

}

void reverser(string source) {

	if (source.length() != 0) {

		cout << source.back();
		source.erase(source.length() - 1, 1);
		return reverser(source);

	}

}