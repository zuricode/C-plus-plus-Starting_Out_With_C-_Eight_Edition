#include <iostream>

using namespace std;

void reverseString(char*);

int main() {

	const int		LENGTH = 51;
	char			line[LENGTH];

	cout << "Enter a string (no more than " << LENGTH - 1 << " characters): ";
	cin.getline(line, LENGTH);

	cout << endl;
	cout << line << endl;
	reverseString(line);

}

void reverseString(char* ptr) {

	int count = strlen(ptr);

	for (int i = count; i >= 0; i--) {
		cout << *(ptr + i);		
	}

	cout << endl;

}