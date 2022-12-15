//17. Morse Code Converter
//
//Morse code is a code where each letter of the English alphabet, each digit, and various
//punctuation characters are represented by a series of dotsand dashes.Table 10 - 9
//shows part of the code.
//Write a program that asks the user to enter a string, and then converts that string to
//Morse code.

#include <iostream>
#include <string>

using namespace std;

string enterString();
void textToMorseCode(string);

int main() {

	string normal_text;
	normal_text = enterString();

	cout << endl;

	textToMorseCode(normal_text);

	cout << endl;

}

string enterString() {
	
	string text;

	cout << "Enter your text: ";
	getline(cin, text);

	for (int i = 0; i < text.size(); i++) {

		text[i] = toupper(text[i]);

	}

	return text;

}

void textToMorseCode(string text) {

	cout << "Original text: " << text << endl;
	cout << "Morse code: ";
	
	for (int i = 0; i < text.size(); i++) {

		switch (text[i]) {
			case ' ':
				cout << " space ";
				break;
			case ',':
				cout << "--..--";
				break;
			case '.':
				cout << ".-.-.-";
				break;
			case '?':
				cout << "..--..";
				break;
			case 0:
				cout << "-----";
				break;
			case 1:
				cout << ".----";
				break;
			case 2:
				cout << "..---";
				break;
			case 3:
				cout << "...--";
				break;
			case 4:
				cout << "....-";
				break;
			case 5:
				cout << ".....";
				break;
			case 6:
				cout << "-....";
				break;
			case 7:
				cout << "--...";
				break;
			case 8:
				cout << "---..";
				break;
			case 9:
				cout << "----.";
				break;
			case 'A':
				cout << ".-";
				break;
			case 'B':
				cout << "-...";
				break;
			case 'C':
				cout << "-.-.";
				break;
			case 'D':
				cout << "-..";
				break;
			case 'E':
				cout << ".";
				break;
			case 'F':
				cout << "..-.";
				break;
			case 'G':
				cout << "--.";
				break;
			case 'H':
				cout << "....";
				break;
			case 'I':
				cout << "..";
				break;
			case 'J':
				cout << ".---";
				break;
			case 'K':
				cout << "-.-";
				break;
			case 'L':
				cout << ".-..";
				break;
			case 'M':
				cout << "--";
				break;
			case 'N':
				cout << "-.";
				break;
			case 'O':
				cout << "---";
				break;
			case 'P':
				cout << ".--.";
				break;
			case 'Q':
				cout << "--.-";
				break;
			case 'R':
				cout << ".-.";
				break;
			case 'S':
				cout << "...";
				break;
			case 'T':
				cout << "-";
				break;
			case 'U':
				cout << "..-";
				break;
			case 'V':
				cout << "...-";
				break;
			case 'W':
				cout << ".--";
				break;
			case 'X':
				cout << "-..-";
				break;
			case 'Y':
				cout << "-.--";
				break;
			case 'Z':
				cout << "--..";
				break;
			default:
				break;

		}

		cout << " ";		

	}

}