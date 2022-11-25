#include <iostream>
#include <string>
using namespace std;

string enterName(string, char*, const int);
string formatFullName(char*, char*, char*);

int main() {
	 
	const int		ONE_LENGTH = 51, ALL_LENGTH = 151;
	char			first[ONE_LENGTH], middle[ONE_LENGTH], last[ONE_LENGTH];
	string			full_name;

	enterName("first", first, ONE_LENGTH);
	enterName("middle", middle, ONE_LENGTH);
	enterName("last", last, ONE_LENGTH);

	cout << endl;

	full_name = formatFullName(first, middle, last);

	cout << "FULL NAME: " << full_name << endl;

}

string enterName(string part, char* name_type, const int SIZE) {

	cout << "Enter your " << part << " name: ";
	cin.getline(name_type, SIZE);

	return name_type;

}

string formatFullName(char* first, char* middle, char* last) {

	string full_name = "";

	for (int i = 0; i < strlen(last); i++) {
		full_name += *(last + i);
	}
	
	full_name += ", ";

	for (int i = 0; i < strlen(first); i++) {
		full_name += *(first + i);
	}

	full_name += " ";

	for (int i = 0; i < strlen(middle); i++) {
		full_name += *(middle + i);
	}

	return full_name;

}