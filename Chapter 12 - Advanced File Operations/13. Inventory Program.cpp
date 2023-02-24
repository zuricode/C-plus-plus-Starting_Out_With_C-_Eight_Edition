//Write a program that uses a structure to store the following inventory data in a file :
//
//Item Description
//Quantity on Hand
//Wholesale Cost
//Retail Cost
//Date Added to Inventory
//
//The program should have a menu that allows the user to perform the following tasks :
//
//• Add new records to the file.
//• Display any record in the file.
//• Change any record in the file.
//
//Input Validation : The program should not accept quantities, or wholesale or retail
//costs, less than 0. The program should not accept dates that the programmer determines
//are unreasonable.

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const int		DESC_SIZE = 51;
const int		DATE_SIZE = 11;
const string	MONTHS[] = { "January", "February", "March", "April", "May",	"June",
							"July", "August", "September", "October", "November", "December" };
const string	NUMBERS[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const string	TENS[] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
const string	TEENS[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

struct Item {

	char description[DESC_SIZE];
	int	current_stock;
	double wholesale_cost;
	double retail_cost;
	char date_added[DATE_SIZE] {NULL};

};

void Menu(fstream &file, const string);

int inputValidation(int, string);
int inputValidation(int, int, string);
double inputValidation(double, string);

void dateInput(char *);
bool checkDate(int, int, int, const string[]);

void openFile(fstream& file, string &);
void addRecord(fstream& file, const string);
Item addAttributes();
void displayRecords(fstream& file, const string);
void changeRecord(fstream& file, const string);

int numOfRecords(fstream &file);

int main() {

	fstream file;
	string location;

	openFile(file, location);

	Menu(file, location);

	file.close();

}

void openFile(fstream& file, string &location) {

	cout << "Enter the location of your inventory file: ";
	getline(cin, location);

	file.open(location, ios::in | ios::out | ios::app | ios::binary);

	while (file.fail()) {

		cout << "Error opening " << location << endl;
		file.clear();

		cout << "Enter the location of your inventory file: ";
		getline(cin, location);

		file.open(location, ios::in | ios::out | ios::app | ios::binary);

	}

	cout << endl;

	cout << "Inventory file was successfully opened." << endl;

	cout << endl;

}

void Menu(fstream &file, const string FILE_LOCATION) {

	int choice;

	do {

		cout << "MENU" << endl;
		cout << "==========" << endl;
		cout << endl;
		cout << "1. Add a new record" << endl;
		cout << "2. Display records" << endl;
		cout << "3. Change a record" << endl;
		cout << "4. Quit the program" << endl;
		cout << endl;
		cout << "Enter your selection: ";

		while (!(cin >> choice) || (choice < 1 || choice > 4)) {
			cout << "ERROR: Selection must be between 1 and 4. Try again: ";
			cin.clear();
			cin.ignore(1200, '\n');
		}

		cin.clear();
		cin.ignore(1200, '\n');

		cout << endl;

		switch (choice) {
		case 1:
			addRecord(file, FILE_LOCATION);
			break;
		case 2:
			displayRecords(file, FILE_LOCATION);
			break;
		case 3:
			changeRecord(file, FILE_LOCATION);
			break;
		case 4:
			break;
		}

	} while (choice != 4);

	cout << "Quiting the program..." << endl;
	
}

int inputValidation(int min, string request) {

	int num;

	cout << request;

	while (!(cin >> num) || num < min) {
		cout << "Value must be an integer greater than " << min << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}
	
	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

int inputValidation(int min, int max, string request) {

	int num;

	cout << request;

	while (!(cin >> num) || num < min || num > max) {
		cout << "Value must be an integer greater than " << min << " and less than " << max << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

double inputValidation(double min, string request) {

	double num;

	cout << request;

	while (!(cin >> num) || num < min) {
		cout << "Value must be a double greater than " << min << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

void dateInput(char struct_date[]) {

	string date, mm, dd, yyyy;
	int i = 0, month, day, year;
	bool valid_date = false;

	do {

		mm = "", dd = "", yyyy = "";

		cout << "Date addded to inventory: ";
		getline(cin, date);
		cin.clear();

		if (date.length() != DATE_SIZE - 1 || date[2] != '/' || date[5] != '/') {

			cout << "Error: " << date << " must be in the following format: mm/dd/yyyy" << endl;

		}

		else {

			for (int j = 0; j < DATE_SIZE - 1; j++) {

				if (j == 0 || j == 1) {
					mm += date[j];
				}

				else if (j == 2 || j == 5) {
					continue;
				}

				else if (j == 3 || j == 4) {
					dd += date[j];
				}

				else {
					yyyy += date[j];
				}

			}

			month = stoi(mm);
			day = stoi(dd);
			year = stoi(yyyy);

			valid_date = checkDate(month, day, year, MONTHS);

			if (!valid_date) {
				cout << date << " is not a valid date. Please try again." << endl;
			}

		}

	} while (!valid_date);

	for (int i = 0; i < DATE_SIZE - 1; i++) {
		struct_date[i] = date[i];
	}

}

bool checkDate(int month, int day, int year, const string MONTHS[]) {

	bool valid_date = true, leap_year = false;

	//LIMITS OF MONTH, DAY AND YEAR ENTRY
	if (month < 1 || month > 12) {
		valid_date = false;
		cout << "Error: Your month entered must be a value between 1 - 12." << endl;
	}

	if (day < 1 || day > 31) {
		valid_date = false;
		cout << "Error: Your day entered must be a value between 1 - 31." << endl;
	}

	if (year < 1 || year > 9999) {
		valid_date = false;
		cout << "Error: Your year entered must be a value between 1 - 9999." << endl;
	}

	//LEAP YEAR CHECK
	if (year % 4 == 0) {
		leap_year = true;
	}

	//IN-DEPTH DATE CHECK
	if (month == 4 || month == 6 || month == 9 || month == 11) {

		if (day > 30) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " cannot have more than 30 days." << endl;
		}

	}

	if (month == 2) {

		if (leap_year && day > 29) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " in " << year << " cannot have more than 29 days." << endl;
		}

		else if (!leap_year && day > 28) {
			valid_date = false;
			cout << "Error: " << MONTHS[month - 1] << " in " << year << " cannot have more than 28 days." << endl;
		}

	}

	return valid_date;

}

void addRecord(fstream &file, const string FILE_LOCATION) {

	Item new_item;

	new_item = addAttributes();

	file.write(reinterpret_cast<char*>(&new_item), sizeof(new_item));

	cout << endl;
	cout << "The new record was successfully added to the file." << endl;

	file.close();

	cout << endl;

}

Item addAttributes() {

	Item new_item;

	cout << "Item Description: ";
	cin.getline(new_item.description, DESC_SIZE);

	new_item.current_stock = inputValidation(0, "Current stock: ");
	new_item.wholesale_cost = inputValidation(0, "Wholesale cost: $");
	new_item.retail_cost = inputValidation(0, "Retail cost: $");
	dateInput(new_item.date_added);

	cout << endl;

	return new_item;

}

void displayRecords(fstream &file, const string FILE_LOCATION) {

	long file_size;
	long struct_size = sizeof(Item);
	int number_of_records;

	Item new_item;

	file.seekg(0L, ios::end);
	file_size = static_cast<int>(file.tellg());

	file.seekg(0L, ios::beg);

	if (file_size % struct_size == 0) {

		number_of_records = file_size / struct_size;

		cout << "INVENTORY RECORDS" << endl;
		cout << endl;
		cout << "No." << left << setw(3) << " " << setw(50) << "ITEM DESCRIPTION" << setw(9) << "STOCK" << setw(17) << "WHOLESALE COST" << setw(16) << "RETAIL COST" << setw(10) << "DATE ADDED" << endl;
		cout << "===========================================================================================================" << endl;

		for (int i = 0; i < number_of_records; i++) {

			file.read(reinterpret_cast<char*>(&new_item), sizeof(new_item));

			cout << i + 1 << setw(5) << "#" << setw(50) << new_item.description
				<< setw(8) << new_item.current_stock << " $" << fixed << setprecision(2)
				<< setw(15) << new_item.wholesale_cost << " $" 
				<< setw(15) << new_item.retail_cost 
				<< setw(10) << new_item.date_added << endl;

		}

	}

	cout << endl;

}

void changeRecord(fstream &file, const string FILE_LOCATION) {

	int choice;
	int number_of_records;
	long start;
	Item item;

	number_of_records = numOfRecords(file);

	displayRecords(file, FILE_LOCATION);

	choice = inputValidation(1, number_of_records, "Which item would you like to edit: ");

	start = (choice - 1) * sizeof(Item);

	file.seekg(start, ios::beg);

	file.read(reinterpret_cast<char*>(&item), sizeof(item));

	cout << "Which attribute would you like to change :" << endl;
	cout << endl;
	cout << "1. Item description (" << item.description << ")" << endl;
	cout << "2. Current stock (" << item.current_stock << ")" << endl;
	cout << "3. Wholesale cost ($" << item.wholesale_cost << ")" << endl;
	cout << "4. Retail cost ($" << item.retail_cost << ")" << endl;
	cout << "5. Date added (" << item.date_added << ")" << endl;
	cout << endl;

	choice = inputValidation(1, 5, "Which attribute would you like to edit: ");

	switch (choice) {
		case 1:
			cout << "Current item description: " << item.description << endl;
			cout << "Enter the new item description: ";
			cin.getline(item.description, DESC_SIZE);
			break;
		case 2:
			cout << "Current stock: " << item.current_stock << endl;
			item.current_stock = inputValidation(0, "Enter the new stock quantity: ");
			break;
		case 3:
			cout << "Current wholesale cost: $" << item.wholesale_cost << endl;
			item.wholesale_cost = inputValidation(0, "Enter the new wholesale cost: $");
			break;
		case 4:
			cout << "Current retail cost: $" << item.retail_cost << endl;
			item.retail_cost = inputValidation(0, "Enter the new retail cost: $");
			break;
		case 5:
			cout << "Current date item was added to the inventory: " << item.date_added << endl;
			dateInput(item.date_added);
			break;	
	}

	file.seekg(start, ios::beg);

	file.write(reinterpret_cast<char*>(&item), sizeof(item));

}

int numOfRecords(fstream &file) {

	long file_size;
	long struct_size = sizeof(Item);
	int number_of_records;

	file.seekg(0L, ios::end);
	file_size = static_cast<int>(file.tellg());

	file.seekg(0L, ios::beg);

	if (file_size % struct_size == 0) {
		number_of_records = file_size / struct_size;
	}
	else {
		number_of_records = -1;
	}

	return number_of_records;

}
