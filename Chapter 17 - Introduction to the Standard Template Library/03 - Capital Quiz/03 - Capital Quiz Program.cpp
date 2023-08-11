//3. Capital Quiz
//
//Write a program that creates a map containing the U.S. states as keys, and their capitals as values.
//(Use the internet to get a list of the states and their capitals.)
//The program should then randomly quiz the user by displaying the name of a state and ask 
//the user to enter that state's capital.
//The program should keep a count of the number of correct and incorrect responses.
//(As an alternative to the U.S. states, the program can use the names of countries and their capitals.)

#include<string>
#include<iostream>
#include<map>
#include<unordered_map>
#include<fstream>
#include<iomanip>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

void importStateCapitalData(map<string, string>&, vector<string>&);
void displayMap(const map<string, string>);
string fixFilePath(const string);
void runQuiz(const map<string, string>, vector<string>, const int);

int main() {

	srand(time(NULL));

	const int NUM_OF_QUESTIONS = 10;
	map<string, string>states_and_capitals;
	vector<string> states;

	cout << "=========================\n";
	cout << "03 - CAPITAL QUIZ PROGRAM\n";
	cout << "=========================\n";
	cout << "\n";

	importStateCapitalData(states_and_capitals, states);

	displayMap(states_and_capitals);

	runQuiz(states_and_capitals, states, NUM_OF_QUESTIONS);

	cout << "Ending the program...\n";

}

void importStateCapitalData(map<string, string>& map, vector<string>& states) {

	ifstream file;
	string file_location;
	string current_line;
	int counter = 1;
	string key;
	string value;

	do {

		cout << "Enter the file location for the source file: ";
		getline(cin, file_location);
		cout << "\n";

		file_location = fixFilePath(file_location);

		file.open(file_location, ios::in);

		if (file.fail()) {
			cout << "Source file location is invalid. Try a different file location.\n";
		}
		else {
			cout << file_location << " was loaded successfully.\n";
			file.clear();
		}

		cout << "\n";

	} while (!file);

	cout << "Displaying the file contents...\n";
	cout << "\n";

	cout << left << setw(25) << "STATES" << "CAPITALS\n";
	cout << "--------------------------------------\n";

	while (getline(file, current_line)) {

		if (counter % 2 != 0) {
			key = current_line;
			states.push_back(current_line);
		}
		else {
			value = current_line;
			map.insert(make_pair(key, value));
		}

		counter++;

	}

	file.close();

}

void displayMap(const map<string, string> MAP) {

	for (pair<string, string> element : MAP) {
		cout << setw(25) << element.first << element.second << "\n";
	}

	cout << "\n";

}

string fixFilePath(const string PATH) {

	string new_path = "";

	cout << "Original file path: " << PATH << "\n";
	cout << "\n";

	for (int i = 0; i < PATH.size(); i++) {
		if (PATH[i] == '\\') {
			new_path += "\\\\";
		}
		else {
			new_path += PATH[i];
		}

	}

	cout << "Fixed file path: " << new_path << "\n";
	cout << "\n";

	return new_path;

}

void runQuiz(const map<string, string> MAP, vector<string> states, const int QUESTIONS) {

	int correct_answers = 0;
	int current_state_index;
	string current_state_string = "";
	string answer = "";	
	vector<string> used_states;
	unordered_map<string, string> recorded_answers;

	map<string, string>::const_iterator it;
	unordered_map<string, string>::const_iterator un_it;
	vector<string>::iterator vit;

	for (int i = 0; i < QUESTIONS; i++) {

		current_state_index = rand() % states.size() + 1;
		vit = states.begin() + current_state_index;
		current_state_string = states[current_state_index];

		cout << "Question #" << i + 1 << "\n";
		cout << "--------------------------------\n";
		cout << "What is the capital of ";

		cout << current_state_string << "?\n";
		cout << "Capital: ";

		getline(cin, answer);
		cout << "\n";

		if (MAP.at(current_state_string) == answer) {
			cout << "You are CORRECT!\n";
			answer += " - CORRECT";
			correct_answers++;
		}
		else {
			cout << "Unlucky, that is not the correct.\n";
			answer += " - WRONG";
		}

		cout << "Correct answer: " << MAP.at(current_state_string) << "\n";
		cout << "\n";

		recorded_answers.insert(make_pair(current_state_string, answer));

		states.erase(vit);

	}
		
	cout << "\n";


	cout << "QUIZ RESULTS\n";
	cout << "------------\n";
	cout << "\n";

	for (un_it = recorded_answers.begin(); un_it != recorded_answers.end(); un_it++) {
		cout << "\t" << "State: " << un_it->first << " - Your Answer: " << un_it->second << "\n";
	}

	cout << "\n";

	cout << "Total Questions: " << QUESTIONS << "\n";
	cout << "Correct Answers: " << correct_answers << "\n";
	cout << "Incorrect Answers: " << QUESTIONS - correct_answers << "\n";
	cout << "Correct Percentage: " << static_cast<double>(QUESTIONS / correct_answers) << "\n";
	cout << "\n";
	
}