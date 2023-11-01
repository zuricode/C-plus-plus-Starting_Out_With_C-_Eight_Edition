//11. Palindrome Detector
//
//A palindrome is any word, phrase, or sentence that reads the same forward and backward. Here are 
//some well-known palindromes:
//
//Able was I, ere I saw Elba
//A man, a plan, a canal, Panama
//Desserts, I stressed
//Kayak
//
//Write a bool function that uses recursion to determine if a string argument is a palindrome. The 
//function should return true if the argument reads the same forward and backward. Demonstrate the 
//function in a program.

#include <iostream>
#include <string>
#include <limits>

using std::string;
using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;

bool palindromeDetector(string);
void isPalindrome(string);
string onlyLettersAndNumbers(string);

int main() {

	cout << "================================\n";
	cout << "20-11 PALINDROME DETECTOR DRIVER\n";
	cout << "================================\n";
	cout << "\n";

	string text;

	cout << "Enter text to check if its a palindrome: ";
	getline(cin, text);

	cout << "\n";
	
	isPalindrome(text);

	cout << "Ending the program...\n";

}

bool palindromeDetector(string text) {

	if (text.length() == 0) {
		return true;
	}

	else if (toupper(text.front()) != toupper(text.back())) {
		return false;
	}
	
	else {

		text.erase(0, 1);

		if (text.length() > 1) {
			text.erase(text.length()-1, 1);
		}

		palindromeDetector(text);

	}	

}

void isPalindrome(string text) {

	string new_text;

	new_text = onlyLettersAndNumbers(text);

	cout << "\"" << text << "\"";

	if (palindromeDetector(new_text)) {
		cout << " IS"; 
	}
	else {
		cout << " IS NOT";
	}

	cout << " a palindrome.\n";

	cout << "\n";

}

string onlyLettersAndNumbers(string text) {

	for (int i = 0; i < text.length(); i++) {

		if (!isalnum(text[i])) {
			text.erase(i, 1);
			i--;
		}

	}

	return text;

}