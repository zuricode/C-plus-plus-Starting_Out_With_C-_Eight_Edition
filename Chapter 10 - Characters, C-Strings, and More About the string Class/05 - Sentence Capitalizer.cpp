#include <iostream>

using namespace std;

void capitalizeText(char*);

int main() {

	const int		SIZE = 101;
	char			text[SIZE];


	cout << "Enter your string (no more than " << SIZE << " characters): ";
	cin.getline(text, SIZE);

	cout << "Original: " << text << endl;

	capitalizeText(text);

	cout << "Capitalized: " << text << endl;

	cout << endl;



}

void capitalizeText(char* ptr) {

	int i = 0;
	
	while (*(ptr + i) != '\0') {

		if (i == 0) {
			*(ptr + i) = toupper(*(ptr + i));
		}

		if ((*(ptr + i) == '.' || *(ptr + i) == '!') && *(ptr + (i + 1)) != '\0') {
			*(ptr + (i + 2)) = toupper(*(ptr + (i + 2)));
		}

		i++;

	}

}