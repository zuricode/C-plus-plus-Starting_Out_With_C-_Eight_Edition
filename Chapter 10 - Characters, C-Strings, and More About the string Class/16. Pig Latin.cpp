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
void stringCharSwap(char&, char&);

int main() {

	string original, converted;

	original = inputSentence();
	cout << "English:\t" << original << endl;

	converted = pigLatinConversion(original);
	cout << "Pig Latin:\t" << converted << endl;

	cout << endl;

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

	while (sentence[i] != '\0') {

		if (isalpha(sentence[i])) {
			char_counter++;
		}

		if (isspace(sentence[i])) {

			if (char_counter > 1) {
				stringCharSwap(sentence[i], sentence[i - char_counter]);
				sentence.erase(i - char_counter, 1);
			}

				char_counter = 0;
				sentence.insert(i, PIG_AY);
				i++;
				i++;
				sentence.insert(i, 1, ' ');

		}	

		i++;

	}

	return sentence;

}

void stringCharSwap(char& a, char& b) {

	char temp;
	temp = a;
	a = b;
	b = temp;

}