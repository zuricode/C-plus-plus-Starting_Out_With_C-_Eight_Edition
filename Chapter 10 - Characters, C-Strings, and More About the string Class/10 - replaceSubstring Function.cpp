//5. Sentence Capitalizer
//Write a function that accepts a pointer to a C - string as an argument and capitalizes
//the first character of each sentence in the string.For instance, if the string argument
//is “ hello.my name is Joe.what is your name ? ” the function should manipulate
//the string so it contains “ Hello.My name is Joe.What is your name ? ”
//Demonstrate the function in a program that asks the user to input a string and then
//passes it to the function.The modified string should be displayed on the screen.
//Optional Exercise : Write an overloaded version of this function that accepts a string
//class object as its argument.

#include <iostream>

using namespace std;

void replaceSubstring(char*, char*, char*);

int main() {

	const int		SIZE = 101;
	char			string1[SIZE] = "Everywhere I'll ever be.", string2[SIZE] = "I'll", string3[SIZE] = "you'll";

	replaceSubstring(string1, string2, string3);

}

void replaceSubstring(char* string1, char* string2, char* string3) {

	char* strptr = strstr(string1, string2);
	int i = 0;

	while (string1 < strptr) {

		cout << *string1;

		string1++;

	};

	while (*string3 != '\0') {

		cout << *string3;

		string3++;

	}

}