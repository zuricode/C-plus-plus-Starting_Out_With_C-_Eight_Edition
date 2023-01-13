/10. Search Function for the Speakers’ Bureau Program
//
//Add a function to Programming Challenge 9 that allows the user to search for a speaker
//on a particular topic.It should accept a key word as an argumentand then search the
//array for a structure with that key word in the Speaking Topic field.All structures
//that match should be displayed.If no structure matches, a message saying so should
//be displayed.
//
//9. Speakers’ Bureau
//
//Write a program that keeps track of a speakers’ bureau.The program should use a
//structure to store the following data about a speaker :
//
//Name
//Telephone Number
//Speaking Topic
//Fee Required
//
//The program should use an array of at least 10 structures.It should let the user enter
//data into the array, change the contents of any element, and display all the data stored
//in the array.The program should have a menu - driven user interface.
//Input Validation : When the data for a new speaker is entered, be sure the user enters
//data for all the fields.No negative amounts should be entered for a speaker’s fee.

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

struct Speaker {

	string name;
	string tel;
	string topic;
	double fee {};

};

string	inputString(string);
double	inputDouble(string);
int		inputTwoLimits(int, int);
bool	yesOrNo(string);
string	makeUppercase(string);
	
void newSpeaker(Speaker[], const int, bool&);
void editSpeaker(Speaker[], const int, bool);
void showAllSpeakerData(Speaker[], const int, bool);

void searchSpeakerByTopic(Speaker[], const int, bool);

int main() {

	const int		AMOUNT = 3;

	Speaker bureau[AMOUNT];

	int choice;
	bool isData = false, quit = false;

	cout << fixed << setprecision(2);

	do {

		cout << "==================================" << endl;
		cout << "*********    MAIN MENU    ********" << endl;
		cout << "==================================" << endl;
		cout << endl;
		cout << "1. Enter speaker(s)" << endl;
		cout << "2. Edit speaker" << endl;
		cout << "3. Search for speaker by topic" << endl;
		cout << "4. Display all speaker data" << endl;
		cout << "5. Quit program" << endl;
		cout << endl;

		cout << "Enter your menu selction (1-5): ";
		choice = inputTwoLimits(1, 5);

		cout << endl;

		switch (choice) {

		case 1:
			newSpeaker(bureau, AMOUNT, isData);
			break;
		case 2:
			editSpeaker(bureau, AMOUNT, isData);
			break;
		case 3:
			searchSpeakerByTopic(bureau, AMOUNT, isData);
			break;
		case 4:
			showAllSpeakerData(bureau, AMOUNT, isData);
			break;
		case 5:
			quit = true;
			break;

		}

	} while (!quit);

	cout << "Quitting the program......" << endl;

}

string inputString(string request) {

	string input;
	int i = 0;
	bool alnum_check = false;
	bool punct_check = false;

	do {

		cout << request;
		getline(cin, input);

		while ((!alnum_check && !punct_check) && i < input.length()) {

			if (isalnum(input[i])) {
				alnum_check = true;
			}
			else if (ispunct(input[i])) {
				punct_check = true;
			}

			i++;

		}

		if (!alnum_check && !punct_check) {
			cout << "ERROR: String is still empty." << endl;
			cout << endl;
		}

	} while (!alnum_check && !punct_check);

	return input;
	
}

double inputDouble(string request) {

	double num;

	cout << request;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Value must be a number greater than 0." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

int	inputTwoLimits(int min, int max) {

	int num;

	while (!(cin >> num) || num < min || num > max) {
		cout << "ERROR: Value must be an integer greater than " << min << " and less than " << max << ". Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

bool yesOrNo(string request) {

	bool answer;
	char letter;

	cout << request;

	while (!(cin >> letter) || (letter != 'y' && letter != 'Y' && letter != 'n' && letter != 'N')) {
		cout << "ERROR: Value must be either \"y\", \"Y\", \"n\" or \"N\"." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	letter = toupper(letter);

	if (letter == 'Y') {
		answer = true;
	}
	else {
		answer = false;
	}

	return answer;

}

string makeUppercase(string text) {

	string upper {""};

	for (int i = 0; i < text.length(); i++) {
		upper += toupper(text[i]);
	}

	return upper;

}

void newSpeaker(Speaker s[], const int AMOUNT, bool &isData) {

	cout << "SPEAKER DATA ENTRY" << endl;
	cout << "-------------------------" << endl;
	cout << endl;

	for (int i = 0; i < AMOUNT; i++) {

		cout << "SPEAKER #" << i + 1 << endl;
		cout << "---------------" << endl;
		s[i].name = inputString("Name: ");
		s[i].tel = inputString("Telephone Number: ");
		s[i].topic = inputString("Speaker Topic: ");
		s[i].fee = inputDouble("Fee Required: $");

		cout << endl;

	}

	isData = true;

	cout << AMOUNT << " speaker(s) were successfully entered." << endl;

	cout << endl;

}

void editSpeaker(Speaker s[], const int AMOUNT, bool isData) {

	if (isData) {

		int speaker_choice, att_choice;
		double old_double;
		bool again;
		string old_string;

		do {			

			cout << "Which speaker would you like to edit: " << endl;
			cout << endl;

			for (int i = 0; i < AMOUNT; i++) {

				cout << "#" << i + 1 << ". " << s[i].name << endl;

			}

			cout << endl;

			cout << "Enter your selection (1-" << AMOUNT << "): ";
			speaker_choice = inputTwoLimits(1, AMOUNT);
			speaker_choice -= 1;

			cout << "Which attribute of \"" << s[speaker_choice].name << "\" would you like to edit: " << endl;
			cout << endl;
			cout << "1. Name (" << s[speaker_choice].name << ")" << endl;
			cout << "2. Telephone number (" << s[speaker_choice].tel << ")" << endl;
			cout << "3. Speaking topic (" << s[speaker_choice].topic << ")" << endl;
			cout << "4. Fee required ($" << s[speaker_choice].fee << ")" << endl;
			cout << endl;

			cout << "Enter your selection (1-4): ";
			att_choice = inputTwoLimits(1, 4);

			switch (att_choice) {

			case 1:
				old_string = s[speaker_choice].name;
				cout << "Previous name: " << old_string << endl;
				s[speaker_choice].name = inputString("New name: ");
				cout << endl;
				cout << "Speaker name was successfully changed from \"" << old_string << "\" to \"" << s[speaker_choice].name << "\"." << endl;
				break;
			case 2:
				old_string = s[speaker_choice].tel;
				cout << "Previous telephone number: " << old_string << endl;
				s[speaker_choice].tel = inputString("New telephone number: ");
				cout << endl;
				cout << s[speaker_choice].name << "'s telephone number was successfully changed from " << old_string << " to " << s[speaker_choice].tel << "." << endl;
				break;
			case 3:
				old_string = s[speaker_choice].topic;
				cout << "Previous speaking topic: " << old_string << endl;
				s[speaker_choice].topic = inputString("New speaking topic: ");
				cout << endl;
				cout << s[speaker_choice].name << "'s speaking topic was successfully changed from " << old_string << " to " << s[speaker_choice].topic << "." << endl;
				break;
			case 4:
				old_double = s[speaker_choice].fee;
				cout << "Previous speaking fee: $" << old_double << endl;
				s[speaker_choice].fee = inputDouble("New speaking fee: $");
				cout << endl;
				cout << s[speaker_choice].name << "'s speaking fee was successfully changed from $" << old_double << " to $" << s[speaker_choice].fee << "." << endl;
				break;

			}

			cout << endl;

			again = yesOrNo("Would you like to edit another speaker in the bureau? (Enter Y/N): ");
			
			cout << endl;

		} while (again);

		cout << endl;

	}

	else {
		cout << "ERROR: There is no speaker data in the bureau to edit!" << endl;
	}

	cout << "Returning to the main menu......." << endl;
	cout << endl;

}

void showAllSpeakerData(Speaker s[], const int AMOUNT, bool isData) {

	if(isData) {

		cout << "SPEAKER DATA" << endl;
		cout << "---------------------" << endl;
		cout << endl;

		for (int i = 0; i < AMOUNT; i++) {

			cout << "SPEAKER #" << i + 1 << endl;
			cout << "Name: " << s[i].name << endl;
			cout << "Telephone number: " << s[i].tel << endl;
			cout << "Speaker topic: " << s[i].topic << endl;
			cout << "Fee Required: $" << s[i].fee << endl;

			cout << endl;

		}

	}

	else {
		cout << "ERROR: There is no speaker data in the bureau!" << endl;
	}
	
	cout << "Returning to the main menu......." << endl;
	cout << endl;

}

void searchSpeakerByTopic(Speaker s[], const int AMOUNT, bool isData) {
		
	if (isData) {

		bool again;

		do {

			string topic_keyword, upper_topic_keyword, upper_speaker_topic;
			vector<int> matches;

			cout << "SPEAKER SEARCH (BY TOPIC)" << endl;
			cout << "----------------------------------" << endl;
			cout << endl;
			topic_keyword = inputString("Enter the topic for your speaker: ");

			upper_topic_keyword = makeUppercase(topic_keyword);

			for (int i = 0; i < AMOUNT; i++) {

				upper_speaker_topic = makeUppercase(s[i].topic);

				if (upper_speaker_topic.find(upper_topic_keyword, 0) < s[i].topic.length()) {
					matches.push_back(i);
				}

			}

			if (matches.size() != 0) {

				cout << "Speakers found on the topic of \"" << topic_keyword << "\": " << endl;
				cout << endl;

				for (int i = 0; i < matches.size(); i++) {
					cout << "* Name: " << s[matches[i]].name << "\tTopic: " << s[matches[i]].topic << endl;
				}

			}

			else {
				cout << "No speakers were found with the topic of \"" << topic_keyword << "\"." << endl;
			}

			cout << endl;

			again = yesOrNo("Would you like to search for another topic: (Answer Y/N) ");

			cout << endl;

		} while (again);

	}

	else {
		cout << "There is no data in the speaker bureau to search!" << endl;
		
	}
	
	cout << "Returning to the main menu......." << endl;
	cout << endl;

}

