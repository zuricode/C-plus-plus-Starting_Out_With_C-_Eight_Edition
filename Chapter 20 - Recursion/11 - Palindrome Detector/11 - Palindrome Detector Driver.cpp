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

bool palindromeDetector(const string&, int, int);
void isPalindrome(string);

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

bool palindromeDetector(const string& STR, int s, int e) {

	while (s < STR.length() && !isalpha(STR[s])) {
		s++;
	}
	while (e >= 0 && !isalpha(STR[e])) {
		e--;
	}
	if (s > e) {
		return true;
	}
	else {
		return ((toupper(STR[s]) == toupper(STR[e])) &&
			palindromeDetector(STR, s + 1, e - 1));
	}

}

void isPalindrome(string text) {

	cout << "\"" << text << "\"";

	if (palindromeDetector(text, 0, text.length())) {
		cout << " IS"; 
	}
	else {
		cout << " IS NOT";
	}

	cout << " a palindrome.\n";

	cout << "\n";

}