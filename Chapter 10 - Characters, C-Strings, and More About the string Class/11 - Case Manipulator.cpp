//11. Case Manipulator
// 
//Write a program with three functions : upper, lower, and reverse. The upper function
//should accept a pointer to a C - string as an argument.It should step through each character
//in the string, converting it to uppercase.The lower function, too, should accept a
//pointer to a C - string as an argument.It should step through each character in the string,
//converting it to lowercase.Like upperand lower, reverse should also accept a pointer
//to a string.As it steps through the string, it should test each character to determine
//whether it is upper - or lowercase.If a character is uppercase, it should be converted to
//lowercase.Likewise, if a character is lowercase, it should be converted to uppercase.
// 
//Test the functions by asking for a string in function main, then passing it to them in
//the following order : reverse, lower, and upper .

#include <iostream>

using namespace std;

void upper(char*);
void lower(char*);
void reverse(char*);

int main() {

	const int		SIZE = 51;
	char			upper_test[SIZE] = "lower to upper";
	char			lower_test[SIZE] = "UPPER TO LOWER";
	char			reverse_test[SIZE] = "rAnDoM sEleCTioN";


	cout << "Normal: " << upper_test << endl;
	upper(upper_test);
	cout << "Uppercase: " << upper_test << endl;

	cout << endl;

	cout << "Normal: " << lower_test << endl;
	lower(lower_test);
	cout << "Lowercase: " << lower_test << endl;

	cout << endl;

	cout << "Normal: " << reverse_test << endl;
	reverse(reverse_test);
	cout << "Reverse-cased: " << reverse_test << endl;

}

void upper(char* text) {

	while (*text != '\0') {		
		*text = toupper(*text);
		*text++;
	}

}

void lower(char* text) {

	while (*text != '\0') {
		*text = tolower(*text);
		*text++;
	}

}

void reverse(char* text) {

	while (*text != '\0') {
		
		if (isupper(*text)) {
			*text = tolower(*text);
		}

		else if (islower(*text)) {
			*text = toupper(*text);
		}

		*text++;

	}

}