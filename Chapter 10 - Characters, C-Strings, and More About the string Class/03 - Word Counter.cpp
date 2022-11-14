#include <iostream>
#include <string>

using namespace std;

int wordCounter(char*);
//int wordCounter(string);

int main() {

	const int		SIZE = 1510;
	int				words;
	char			text[SIZE];

	cout << "Enter a string (no more than " << SIZE << " characters): ";
	cin.getline(text, SIZE);

	words = wordCounter(text);

	cout << "Your string has " << words << " words." << endl;
	cout << endl;

}

int wordCounter(char* ptr) {

	int length = strlen(ptr), number_of_words = 0;
	bool ischar = false, space = false;

	for (int i = 0; i < length; i++) {

		if (isalnum(*(ptr + 0)) && i == 0) {
			number_of_words++;
		}

		if (*(ptr + i) == ' ') {
			space = true;
		}

		if (isalnum(*(ptr + i))) {
			ischar = true;
		}

		if (ischar && space) {
			number_of_words++;
			ischar = false;
			space = false;
		}
	}

	return number_of_words;

}

//int wordCounter(string text) {

	int number_of_words = 0;
	bool ischar = false, space = false;

	for (int i = 0; i < text.length(); i++) {

		if (isalnum(text[i]) && i == 0) {
			number_of_words++;
		}

		if (text[i] == ' ') {
			space = true;
		}

		if (isalnum(text[i])) {
			ischar = true;
		}

		if (ischar && space) {
			number_of_words++;
			ischar = false;
			space = false;
		}
	}

	return number_of_words;

}