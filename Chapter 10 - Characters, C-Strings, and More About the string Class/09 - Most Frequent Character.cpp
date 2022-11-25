//9. Most Frequent Character
//Write a function that accepts either a pointer to a C - string, or a string object, as its
//argument.The function should return the character that appears most frequently in the
//string.Demonstrate the function in a complete program.

#include <iostream>

using namespace std;

void enterText(char*, const int);
char findMostFrequentCharacter(char*);

int main() {

	const int		SIZE = 251;
	char			text[SIZE], most_common;

	enterText(text, SIZE);
	most_common = findMostFrequentCharacter(text);
	cout << endl;

	cout << "The most common character in your text is the \'" << most_common << "\' character." << endl;

}

void enterText(char* text, const int SIZE) {

	cout << "Enter your text (no more than " << SIZE - 1 << " characters): ";
	cin.getline(text, SIZE);

}

char findMostFrequentCharacter(char* text) {

	char most_common = tolower(*(text + 0));
	int count = 0, highest_count;

	for (int i = 1; i < strlen(text); i++) {
		if (tolower(*(text + i))  == most_common) {
			count++;
		}
	}

	highest_count = count;

	for (int start = 1; start < strlen(text); start++) {

		count = 1;

		if (!isspace(*(text + start)) && tolower(*(text + start)) != most_common) {

			for (int index = start + 1; index < strlen(text); index++) {

				if (tolower(*(text + start)) == tolower(*(text + index))) {

					count++;

				}
					 
			}

			if (count > highest_count) {
				highest_count = count;
				most_common = tolower(*(text + start));
			}

		}		

	}

	return most_common;

}