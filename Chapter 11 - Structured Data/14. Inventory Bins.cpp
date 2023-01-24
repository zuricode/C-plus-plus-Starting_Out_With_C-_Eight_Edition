//14. Inventory Bins
//
//Write a program that simulates inventory bins in a warehouse.Each bin holds a
//number of the same type of parts.The program should use a structure that keeps the
//following data :
//
//Description of the part kept in the bin
//Number of parts in the bin
//
//The program should have an array of 10 bins, initialized with the following data :
//
//Part Description		Number of Parts in the Bin
//
//Valve					10
//Bearing				5
//Bushing				15
//Coupling				21
//Flange				7
//Gear					5
//Gear Housing			5
//Vacuum Gripper		25
//Cable					18
//Rod					12
//
//The program should have the following functions :
//
//AddParts: a function that increases a specific bin’s part count by a specified number.
//RemoveParts : a function that decreases a specific bin’s part count by a specified number.
//
//When the program runs, it should repeat a loop that performs the following steps : The
//user should see a list of what each bin holdsand how many parts are in each bin.
//The user can choose to either quit the program or select a bin.When a bin is selected, the
//user can either add parts to it or remove parts from it.The loop then repeats, showing
//the updated bin data on the screen.
//
//Input Validation : No bin can hold more than 30 parts, so don’t let the user add more
//than a bin can hold.Also, don’t accept negative values for the number of parts being
//added or removed.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Part {

	string description;
	int number_in_bin{};

};

int intTwoLimits(int, int, string);

void initBins(Part []);
void addParts(Part &, const int);
void removeParts(Part &, const int);

void editPart(Part &, const int);

void showInventory(Part [], const int);
int chooseBinOrQuit(Part [], const int);


int main() {

	const int		AMOUNT = 10;
	const int		MAX_EDIT = 30;

	int menu_choice;

	Part parts[AMOUNT];

	initBins(parts);
	
	do {

		showInventory(parts, AMOUNT);

		menu_choice = chooseBinOrQuit(parts, AMOUNT);

		if (menu_choice == 0) {
			cout << "Quiting the program......" << endl;
			exit(EXIT_SUCCESS);
		}

		menu_choice--;
		editPart(parts[menu_choice], MAX_EDIT);

	} while (menu_choice != 0);	

}

int intTwoLimits(int min, int max, string request) {

	int num;

	cout << request;

	while (!(cin >> num) || num < min || num > max) {
		cout << "ERROR: Value must be an integer in between (and including) " << min << " and " << max << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	} 

	cin.clear();
	cin.ignore(1200, '\n');

	cout << endl;

	return num;

}

void initBins(Part parts[]) {

	parts[0] = { "Valve", 10 };
	parts[1] = { "Bearing", 5 };
	parts[2] = { "Bushing", 15 };
	parts[3] = { "Coupling", 21 };
	parts[4] = { "Flange", 7 };
	parts[5] = { "Gear", 5 };
	parts[6] = { "Gear Housing", 5 };
	parts[7] = { "Vacuum Gripper", 25 };
	parts[8] = { "Cable", 18 };
	parts[9] = { "Rod", 12 };
		
}

void addParts(Part &part, const int MAX_EDIT, string request) {

	int num;

	bool isAllowed = false;

	do {

		num = intTwoLimits(0, MAX_EDIT, request);

		if (part.number_in_bin + num > MAX_EDIT) {
			cout << "ERROR: Bins cannot hold more than " << MAX_EDIT << " items. " << endl;
			cout << "Adding " << num << " would bring the total to " << part.number_in_bin + num << " items." << endl;
			cout << endl;
		}

		else {
			part.number_in_bin += num;
			isAllowed = true;
		}

	} while (!isAllowed);	
}

void removeParts(Part &part, const int MAX_EDIT, string request) {

	int num;
	
	bool isAllowed = false;

	do {

		num = intTwoLimits(0, MAX_EDIT, request);

		if (part.number_in_bin - num < 0) {
			cout << "ERROR: Bins cannot hold less than " << 0 << " items. " << endl;
			cout << "Removing " << num << " would leave " << part.number_in_bin - num << " items." << endl;
			cout << endl;
		}
		else {
			part.number_in_bin -= num;
			isAllowed = true;
		}

	} while (!isAllowed);

	cout << endl;

}

void showInventory(Part parts[], const int AMOUNT) {

	cout << left;

	cout << "=========================" << endl;
	cout << "=  WAREHOUSE INVENTORY  =" << endl;
	cout << "=========================" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;
	cout << setw(10) << "No." << setw(25) << "Part Description" << setw(30) << "Number of Parts in the Bin" << "\n";
	cout << endl;

	for (int i = 0; i < AMOUNT; i++) {
		cout << setw(10) << to_string(i + 1) + ")" << setw(25) << parts[i].description << setw(30) << parts[i].number_in_bin << "\n";
	}

	cout << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;

}

int chooseBinOrQuit(Part part[], const int AMOUNT) {

	int choice;

	choice = intTwoLimits(0, AMOUNT, "Enter the number of your bin or 0 to quit the program: ");

	return choice;

}

void editPart(Part &part, const int MAX_EDIT) {

	int choice;

	cout << "Editing " << part.description << endl;
	cout << "------------------------" << endl;
	cout << endl;
	cout << "1) Add part(s)" << endl;
	cout << "2) Remove part(s)" << endl;
	cout << endl;

	choice = intTwoLimits(1, 2, "Enter your selection: ");

	cout << "Current amount of " << part.description << ": " << part.number_in_bin << endl;

	if (choice == 1) {
		addParts(part, MAX_EDIT, "How many part(s) would you like to add:");
	}
	else {
		removeParts(part, MAX_EDIT, "How many part(s) would you like to remove:");
	}

	cout << "UPDATE: You now have " << part.number_in_bin << "x " << part.description << "(s) in your inventory." << endl;

	cout << endl;

}