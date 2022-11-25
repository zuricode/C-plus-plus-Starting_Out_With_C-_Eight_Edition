#include <iostream>
#include <string>

using namespace std;

int main() {

	int position;

	string string1 = "the cat sat on the cat mat";
	string string2 = "cat";
	string string3 = "dobvnjgfhfdhgfg";

	cout << "Original phrase: " << string1 << endl;

	position = string1.find(string2);

	string1.replace(position, string2.size(), string3);

	cout << "Replacement phrase: " << string1 << endl;

}