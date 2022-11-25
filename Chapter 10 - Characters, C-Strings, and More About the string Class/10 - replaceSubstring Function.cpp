//10. replaceSubstring Function
//Write a function named replaceSubstring.The function should accept three C - string
//or string object arguments.Let’s call them string1, string2, and string3.It
//should search string1 for all occurrences of string2.When it finds an occurrence of
//string2, it should replace it with string3.For example, suppose the three arguments
//have the following values :
//
//string1: “the dog jumped over the fence”
//string2 : “the”
//string3 : “that”
//
//With these three arguments, the function would return a string object with the value
//“that dog jumped over that fence.” Demonstrate the function in a complete program.

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