#include <iostream>

using namespace std;

int charCount(char*);

int main() {

	const int	LENGTH = 51;
	char		line[LENGTH];
	int			string_length = 0;

	cout << "Enter a string (no more than " << LENGTH - 1 << " characters): ";
	cin.getline(line, LENGTH);

	string_length = charCount(line);

	cout << "Your string contains " << string_length << " characters." << endl;

	cout << endl;

}

int charCount(char* ptr) {

	return strlen(ptr);

}