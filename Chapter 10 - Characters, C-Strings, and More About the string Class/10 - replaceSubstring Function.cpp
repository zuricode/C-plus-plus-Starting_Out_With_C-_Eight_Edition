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
#include <string>

using namespace std;

string replaceSubstring(string, string, string);

int main() {

	const int		SIZE = 101;
	string			string1 = "Everywhere I'll ever be. I'll be there.", string2 = "I'll", string3 = "you'll", final_string;

	final_string = replaceSubstring(string1, string2, string3);

	cout << "Original string: " << string1 << endl;
	cout << "Replacement string: " << final_string << endl;

}

string replaceSubstring(string string1, string string2, string string3) {

	int position;

		while (string1.find(string2) != -1) {

			position = string1.find(string2);
			string1.replace(position, string2.size(), string3);

		}

	return string1;

}