//18. Phone Number List
// 
//Write a program that has an array of at least 10 string objects that hold people’s
//names and phone numbers.You may make up your own strings, or use the following :
// 
//"Alejandra Cruz, 555-1223"
//"Joe Looney, 555-0097"
//"Geri Palmer, 555-8787"
//"Li Chen, 555-1212"
//"Holly Gaddis, 555-8878"
//"Sam Wiggins, 555-0998"
//"Bob Kain, 555-8712"
//"Tim Haynes, 555-7676"
//"Warren Gaddis, 555-9037"
//"Jean James, 555-4939"
//"Ron Palmer, 555-2783"
//
//The program should ask the user to enter a name or partial name to search for in the
//array.Any entries in the array that match the string entered should be displayed.For
//example, if the user enters “ Palmer ” the program should display the following names
//from the list :
//
//Geri Palmer, 555 - 8787
//Ron Palmer, 555 - 2783

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void makeUppercase(const string[], string[], const int);
string searchInput();
void displayMatches(const string[], string[], const int, string);

int main() {

	const int		SIZE = 11;
	const string	NAMES_AND_NUMBERS[]{ "Alejandra Cruz, 555-1223", "Joe Looney, 555-0097", "Geri Palmer, 555-8787",
										"Li Chen, 555-1212", "Holly Gaddis, 555-8878", "Sam Wiggins, 555-0998",
										"Bob Kain, 555-8712", "Tim Haynes, 555-7676", "Warren Gaddis, 555-9037",
										"Jean James, 555-4939", "Ron Palmer, 555-2783" };

	string			search_text, uppercase_names_and_numbers[SIZE];

	search_text = searchInput();

	makeUppercase(NAMES_AND_NUMBERS, uppercase_names_and_numbers, SIZE);

	cout << endl;

	displayMatches(NAMES_AND_NUMBERS, uppercase_names_and_numbers, SIZE, search_text);

}

void makeUppercase(const string NAMES_AND_NUMBERS[], string uppercase_names_and_numbers[], const int SIZE) {

	for (int i = 0; i < SIZE; i++) {

		uppercase_names_and_numbers[i] = "";

		for (int j = 0; j < NAMES_AND_NUMBERS[i].size(); j++) {
			uppercase_names_and_numbers[i] += toupper(NAMES_AND_NUMBERS[i][j]);
		}

	}

}

string searchInput() {

	string search;

	cout << "Enter a name or partial name to find in the directory: ";
	getline(cin, search);

	for (int i = 0; i < search.size(); i++) {
		search[i] = toupper(search[i]);
	}

	return search;

}

void displayMatches(const string NAMES_AND_NUMBERS[], string uppercase_names_and_numbers[], const int SIZE, string search) {

	int match_counter = 0; vector<int> match_indices;

	for (int i = 0; i < SIZE; i++) {

		if (uppercase_names_and_numbers[i].find(search, 0) < uppercase_names_and_numbers[i].size()) {

			match_counter++;
			match_indices.push_back(i);

		}

	}

	if (match_counter > 0) {

		cout << match_counter << " matches found : " << endl;
		cout << endl;
		
		for (int i = 0; i < match_counter; i++) {
			cout << NAMES_AND_NUMBERS[match_indices[i]] << endl;
		}

	}
	else {

		cout << "No matches were found for \"" << search << "\" in the directory." << endl;

	}


}