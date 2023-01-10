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
	
void newSpeaker(Speaker[], const int, bool&);
void editSpeaker(Speaker[], const int, bool);
void showAllSpeakerData(Speaker[], const int, bool);

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
		cout << "3. Display all speaker data" << endl;
		cout << "4. Quit program" << endl;
		cout << endl;

		cout << "Enter your menu selction (1-4): ";
		choice = inputTwoLimits(1, 4);

		cout << endl;

		switch (choice) {

		case 1:
			newSpeaker(bureau, AMOUNT, isData);
			break;
		case 2:
			editSpeaker(bureau, AMOUNT, isData);
			break;
		case 3:
			showAllSpeakerData(bureau, AMOUNT, isData);
			break;
		case 4:
			quit = true;
			break;

		}

	} while (!quit);

	cout << "Quitting the program......" << endl;

}

string	inputString(string request) {

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

double	inputDouble(string request) {

	double num;

	cout << request;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Value must be a number greater than 0." << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

int		inputTwoLimits(int min, int max) {

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
		double old_double, quit;
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

			cout << "1. Edit another speaker in the bureau" << endl;
			cout << "2. Return to the main menu" << endl;
			cout << endl;
			cout << "Enter your selection: ";

			quit = inputTwoLimits(1, 2);

			cout << endl;

		} while (quit != 2);

		cout << "Returning to the main menu......" << endl;

	}

	else {
		cout << "ERROR: There is no speaker data in the bureau to edit!" << endl;
	}

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
	
	cout << endl;

}
