//14. Word Separator
// 
//Write a program that accepts as input a sentence in which all of the words are run
//together, but the first character of each word is uppercase.Convert the sentence to a
//string in which the words are separated by spacesand only the first word starts with
//an uppercase letter.For example the string “StopAndSmellTheRoses.” would be converted
//to “Stop and smell the roses.”

#include <iostream>
#include <string>

using namespace std;

void inputSentence(string&);
void correctSentence(string&);

int main() {

	string			sentence;

	inputSentence(sentence);

	cout << "Original sentence: " << sentence << endl;

	correctSentence(sentence);

	cout << "Amended sentence: " << sentence << endl;
}

void inputSentence(string& sentence) {

	bool space_error, first_letter_error;
	int uppercase_letters = 0;

	do {

		space_error = false, first_letter_error = false;

		cout << "Enter a sentence with each word starting with a captial letter, but no spaces (e.g TheSkyIsBlue): ";

		getline(cin, sentence);

		cout << endl;

		for (int i = 0; i < sentence.length(); i++) {

			if (sentence[i] == ' ') {
				space_error = true;
			}

			if (isupper(sentence[i])) {
				uppercase_letters++;
			}

		}

		if (!isupper(sentence[0])) {
			first_letter_error = true;
			cout << "ERROR: The first letter of your sentence must be capitalised." << endl;
		}

		if (space_error) {
			cout << "ERROR: There is a space in your sentence." << endl;
			cin.clear();
		}

		if (uppercase_letters == 0) {
			cout << "ERROR: There is no uppercase character in your sentence." << endl;
			cin.clear();
		}

	} while (space_error || first_letter_error || uppercase_letters == 0);

	cout << "Your sentence have entered a compatabile sentence." << endl << endl;

}

void correctSentence(string& sentence) {

	for (int i = 0; i < sentence.length(); i++) {
		 
		if (i != 0 && isupper(sentence[i])) {
			sentence.insert(i, 1, ' ');
			i++;
			sentence[i] = tolower(sentence[i]);
		}

	}

}