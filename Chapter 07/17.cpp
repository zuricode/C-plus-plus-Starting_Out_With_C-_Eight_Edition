#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void		getNamesFromFile(string, vector<string>&),
			nameChoice(const int, const int, vector<string>, vector<string>),
			boysName(vector<string>),
			girlsName(vector<string>);

int			inputNumber(const int, const int);
string		inputName();

int main() {

	const int			NUMBER_OF_NAMES{ 200 },
						LOWEST_CHOICE{ 1 },
						HIGHEST_CHOICE{ 3 };

	const string		LIST_BOYS_NAMES{ "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\BoyNames.txt" },
						LIST_GIRLS_NAMES{ "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\GirlNames.txt" };
	
	vector<string>		boys_names,
						girls_names;

	getNamesFromFile(LIST_BOYS_NAMES, boys_names);
	getNamesFromFile(LIST_GIRLS_NAMES, girls_names);

	nameChoice(LOWEST_CHOICE, HIGHEST_CHOICE, boys_names, girls_names);

}

void	getNamesFromFile(string filename, vector<string>& names) {

	string line;

	ifstream file;
	file.open(filename);

	if (file.fail()) {
		cout << "Error opening " << filename << endl;
	}

	while (getline(file, line)) {
		names.push_back(line);
	}

	file.close();

}

string inputName() {

	string name;

	while (!(getline(cin, name))) {
		cout << "ERROR: Value must be a string. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return name;

}

int		inputNumber(const int LOWEST, const int HIGHEST) {

	int num;

	while (!(cin >> num) || (num < LOWEST || num > HIGHEST)) {
		cout << "ERROR: Value must be an integer lower than " << HIGHEST << " and greater than " << LOWEST << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

void	nameChoice(const int LOWEST, const int HIGHEST, vector<string> boys, vector<string> girls) {

	int num;

	cout << "Would you like to enter a boy's name, girl's name or both? " << endl << endl;

	cout << "1. Boy" << endl;
	cout << "2. Girl" << endl;
	cout << "3. Both" << endl << endl;

	num = inputNumber(LOWEST, HIGHEST); 
	
	cout << endl;

	switch (num) {

		case 1:
			boysName(boys);
			break;
		case 2:
			girlsName(girls);
			break;
		case 3:
			boysName(boys);
			girlsName(girls);
			break;
	}

}

void boysName(vector<string> vector) {

	bool match = false;
	string name;

	cout << "Enter your chosen boys name: ";
	name = inputName();		

	for (int i = 0; i < vector.size(); i++) {
		if (name == vector[i]) {
			match = true;		}
	}

	if (match) {
		cout << name << " was one of the top 200 most popular boys names in the US, from 2000 to 2009." << endl;
	}
	else {
		cout << name << " was NOT one of the top 200 most popular boys names in the US, from 2000 to 2009." << endl;
	}

	cout << endl;

}

void girlsName(vector<string> vector) {

	bool match = false;
	string name;

	cout << "Enter your chosen girls name: ";
	name = inputName();

	for (int i = 0; i < vector.size(); i++) {
		if (name == vector[i]) {
			match = true;
		}
	}

	if (match) {
		cout << name << " was one of the top 200 most popular girls names in the US, from 2000 to 2009." << endl;
	}
	else {
		cout << name << " was NOT one of the top 200 most popular girls names in the US, from 2000 to 2009." << endl;
	}

	cout << endl;

}