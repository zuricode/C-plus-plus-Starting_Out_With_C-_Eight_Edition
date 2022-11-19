#include <iostream>

using namespace std;

int vowelCount(char*);
int consonantCount(char*);
void enterAnotherString(char*, int);
void showMenu();
char menuInput();

int main() {

	const int		SIZE = 201;
	char			text[SIZE], menu_choice;

	cout << "Enter your string (no more than " << SIZE - 1 << " characters): ";
	cin.getline(text, SIZE);
	cout << endl;


	do {

		showMenu();
		menu_choice = menuInput();
		cout << endl;

		switch (menu_choice) {

			case 'A':
				cout << "There are " << vowelCount(text) << " vowels in the string." << endl << endl;
				break;
			case 'B':
				cout << "There are " << consonantCount(text) << " consonants in the string." << endl << endl;
				break;
			case 'C':
				cout << "There are " << vowelCount(text) + consonantCount(text) << " vowels and consontants in the string." << endl << endl;
				break;
			case 'D':
				enterAnotherString(text, SIZE);
				break;
			case 'E':
				cout << "Qutting the program..." << endl;
				break;

		} 

	} while (menu_choice != 'E');

}

void enterAnotherString(char* text, int SIZE) {

	cout << "Enter another string (no more than " << SIZE - 1 << " characters): ";
	cin.getline(text, SIZE);

}

int vowelCount(char* ptr) {

	int length = 0, vowel_count = 0;

	while (*(ptr + length) != '\0') {

		if (toupper(*(ptr + length)) == 'A' || toupper(*(ptr + length)) == 'E' ||
			toupper(*(ptr + length)) == 'I' || toupper(*(ptr + length)) == 'O' ||
			toupper(*(ptr + length)) == 'U') {
			vowel_count++;
		}

		length++;

	}

	return vowel_count;

}

int consonantCount(char* ptr) {

	int length = 0, consonant_count = 0;

	while (*(ptr + length) != '\0') {

		if (isalpha(*(ptr + length))) {

			if (toupper(*(ptr + length)) != 'A' || toupper(*(ptr + length)) != 'E' ||
				toupper(*(ptr + length)) != 'I' || toupper(*(ptr + length)) != 'O' ||
				toupper(*(ptr + length)) != 'U') {
				consonant_count++;
			}

		}

		length++;
	}

	return consonant_count;

}

void showMenu() {

	cout << "A) Count the number of vowels in the string" << endl;
	cout << "B) Count the number of consonants in the string" << endl;
	cout << "C) Count both the number of vowels and consonants in the string" << endl;
	cout << "D) Enter another string" << endl;
	cout << "E) Exit the program" << endl;
	cout << endl;
	cout << "Enter your choice: ";


}

char menuInput() {

	char answer;

	while (!(cin >> answer) && (toupper(answer) != 'A' || toupper(answer) != 'B' || toupper(answer) != 'C' ||
		toupper(answer) != 'D' || toupper(answer) != 'E')) {
		cout << "ERROR: Please enter either A, B, C, D or E. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}


	return toupper(answer);

}