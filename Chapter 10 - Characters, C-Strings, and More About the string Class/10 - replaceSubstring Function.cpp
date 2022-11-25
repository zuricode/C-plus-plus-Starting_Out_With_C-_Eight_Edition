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