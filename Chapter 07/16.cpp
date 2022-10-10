#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void	getInfoFromFile(string, vector<string>&);
void	outputVector(vector<string>);
string	inputTeamValidation(vector<string>);
int		amountOfTitles(vector<string>, string);

int main() {

	const int		FIRST_YEAR{ 1903 },
					LAST_YEAR{ 2012 };

	const string	TEAMS{ "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\Teams.txt" },
					WORLD_SERIES_WINNERS{"C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\WorldSeriesWinners.txt"};

	vector<string>	list_of_champions,
					list_of_teams;

	int				amount_of_titles;

	string			user_team;

	getInfoFromFile(WORLD_SERIES_WINNERS, list_of_champions);
	getInfoFromFile(TEAMS, list_of_teams);

	const int		NUMBER_OF_YEARS = list_of_champions.size(),
					NUMBER_OF_TEAMS = list_of_teams.size();
		

	cout << "LIST OF TEAMS: " << endl << endl;
	outputVector(list_of_teams);
	cout << NUMBER_OF_TEAMS << " teams in total." << endl << endl;

	user_team = inputTeamValidation(list_of_teams);

	amount_of_titles = amountOfTitles(list_of_champions, user_team);

	cout << user_team << " have won " << amount_of_titles << " from " << FIRST_YEAR << " to " << LAST_YEAR << endl << endl;

}

void getInfoFromFile(string filename, vector<string>& vector) {

	string name;
	ifstream inputFile;
	inputFile.open(filename);

	if (inputFile.fail()) {
		cout << "ERROR: Could not open " << filename << "." << endl;
	}

	while (getline(inputFile, name)) {
		vector.push_back(name);
	}

	inputFile.close();

}

void outputVector(vector<string> vector) {

	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << endl;
	}

	cout << endl;

}

string inputTeamValidation(vector<string> vector) {

	cout << "Enter the name of your chosen team: ";

	string line;
	
	while (getline(cin, line)) {

		for (int i = 0; i < vector.size(); i++) {
			if (line == vector[i]) {
				return line;
			}
		}

		cout << "ERROR: Value must be one of the teams listed above. Re-enter your team: ";
		cin.clear();
		cin.ignore(1200, '\n');

	}

}

int amountOfTitles(vector<string> vector, string name) {

	int counter{ 0 };

	for (int i = 0; i < vector.size(); i++) {
		if (name == vector[i]) {
			counter++;
		}
	}

	return counter;

}

