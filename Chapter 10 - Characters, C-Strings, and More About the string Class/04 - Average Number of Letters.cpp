#include <iostream>
#include <string>
#include <vector>

using namespace std;

int wordCounter(char*);
int wordCounter(string);
double averageLetters(char*);
double averageLetters(string);
void displayVector(vector<int>);

int main() {

	const int		SIZE = 1510;
	int				words;
	double			average;
	char			text[SIZE];
	string			text_string;

	cout << "Enter a string (no more than " << SIZE << " characters): ";
	cin.getline(text, SIZE);

	words = wordCounter(text);
	average = averageLetters(text);

	cout << "Your string has " << words << " words and the average letters per word is " << average << "." << endl;
	cout << endl << endl;

	cout << "Enter a string (no more than " << SIZE << " characters): ";
	getline(cin, text_string);

	words = wordCounter(text_string);

	cout << "Your string has " << words << " words." << endl;
	cout << endl << endl;

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

int wordCounter(string text) {

	int length = text.length();
	int number_of_words = 0;
	bool ischar = false, space = false;

	for (int i = 0; i < length; i++) {

		if (isalnum(text[0]) && i == 0) {
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

double averageLetters(char* ptr) {

	int size = strlen(ptr), char_count = 0, total = 0;
	bool space = false;
	vector<int> letters;

	for (int i = 0; i < size; i++) {

		if (isalpha(*(ptr + i))) {
			char_count++;
		}

		if ((!isalnum(*(ptr + i)) && char_count > 0 && *(ptr + i) != '\'') || i == (size - 1)) {
			letters.push_back(char_count);
			char_count = 0;
		}

	}

	displayVector(letters);

	for (int i = 0; i < letters.size(); i++) {
		total += letters[i];
	}

	return static_cast<double>(total) / letters.size();

}

void displayVector(vector<int> vector) {

	cout << "List of words by letter count: ";

	for (int i = 0; i < vector.size(); i++) {
		if (i == vector.size() - 1) {
			cout << vector[i] << ".";
		}
		else {
			cout << vector[i] << ", ";

		}
	}

	cout << endl;

}
