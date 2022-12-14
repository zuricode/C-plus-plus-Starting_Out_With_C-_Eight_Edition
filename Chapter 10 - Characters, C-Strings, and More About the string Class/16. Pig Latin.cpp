//16. Pig Latin
// 
//Write a program that reads a sentence as input and converts each word to “Pig Latin.”
//In one version, to convert a word to Pig Latin you remove the first letter and place
//that letter at the end of the word. Then you append the string “ay” to the word. Here
//is an example :
// 
//English: I SLEPT MOST OF THE NIGHT
//Pig Latin : IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY

#include <iostream>
#include <string>

using namespace std;

const string	PIG_AY = "AY";

string inputSentence();
string pigLatinConversion(string&);

int main() {

	string original, converted;

	original = inputSentence();
	cout << "English:\t" << original << endl;

	converted = pigLatinConversion(original);
	cout << "Pig Latin:\t" << converted << endl;

}

string inputSentence() {

	string input;

	cout << "Enter your chosen sentence: ";
	getline(cin, input);

	for (int i = 0; i < input.length(); i++) {
		input[i] = toupper(input[i]);
	}

	return input;

}

string pigLatinConversion(string& sentence) {

	int char_counter = 0, i = 0;
	bool alnum_check;
	char first_letter;

	while (sentence[i] != '\0') {

		if (isalpha(sentence[i])) {
			char_counter++;
			alnum_check = true;

		}

		if (!isalnum(sentence[i]) && char_counter > 0) {

			alnum_check = false;

			//Insert "AY" at the end of a word.
			sentence.insert(i, PIG_AY);

			// Word shifter (if more than 1 characters is counted)

			if (char_counter > 1) {
				first_letter = sentence[i - char_counter];

				for (int j = i - char_counter; j < i; j++) {
					sentence[j] = sentence[j + 1];
				}

				sentence[i - 1] = first_letter;

			}

			i++;
			i++;

			//Reset of chacter counter.
			char_counter = 0;

		}

		i++;

	}

	if (alnum_check) {

		first_letter = sentence[i - char_counter];

		for (int j = i - char_counter; j < i - 1; j++) {
			sentence[j] = sentence[j + 1];
		}

		sentence[i - 1] = first_letter;

		int last_character = sentence.size() - 1;

		while (!isalnum(sentence[last_character])) {
			last_character--;
		}

		sentence.insert(last_character + 1, PIG_AY);

	}

	return sentence;

}