//14. Inventory Screen Report
//
//Write a program that reads the data in the file created by the program in Programming
//Challenge 13. The program should calculate and display the following data :
//
//• The total wholesale value of the inventory
//• The total retail value of the inventory
//• The total quantity of all items in the inventory

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

const int		DESC_SIZE = 51;
const int		DATE_SIZE = 11;

struct Item {

	char description[DESC_SIZE];
	int	current_stock;
	double wholesale_cost;
	double retail_cost;
	char date_added[DATE_SIZE]{ NULL };

};

vector<Item> importInventoryData();

void displayItems(vector<Item>);

void showWholesaleTotal(vector<Item>);
void showRetailTotal(vector<Item>);
void showQuantityTotal(vector<Item>);

int main() {

	vector<Item> inventory_data;

	inventory_data = importInventoryData();

	displayItems(inventory_data);

	showWholesaleTotal(inventory_data);
	showRetailTotal(inventory_data);
	showQuantityTotal(inventory_data);

}

vector<Item> importInventoryData() {

	fstream file;
	string location;
	long file_size;
	long current_byte;
	int number_of_records;
	bool fileError;

	Item new_item;
	vector<Item> inventory_data;

	do {

		fileError = false;

		cout << "Enter the location of the inventory file: ";
		getline(cin, location);

		cout << endl;

		file.open(location, ios::in | ios::binary);

		if (file.fail()) {

			fileError = true;
			cout << "ERROR: " << location << " could not be opened. Double-check your file location and try again." << endl;
			file.close();
			cout << endl;
		}

		else if (!fileError) {

			file.seekg(0L, ios::end);
			file_size = file.tellg();

			if (file_size < sizeof(Item) || file_size % sizeof(Item) != 0) {
				fileError = true;
				cout << "ERROR: " << location << " is not an inventory file. Be sure to choose an inventory file." << endl;
				file.close();
				cout << endl;
			}

		}

	} while (fileError);

	number_of_records = file_size / sizeof(Item);

	for (int i = 0; i < number_of_records; i++) {

		current_byte = i * sizeof(Item);
		file.seekg(current_byte, ios::beg);

		file.read(reinterpret_cast<char*>(&new_item), sizeof(new_item));
		inventory_data.push_back(new_item);

	}

	file.close();

	return inventory_data;

}

void displayItems(vector<Item> data) {

	

	if (data.size() != 0) {

		cout << "INVENTORY RECORDS" << endl;
		cout << endl;
		cout << "No." << left << setw(4) << " " << setw(50) << "ITEM DESCRIPTION" << setw(9) << "STOCK" << setw(17) << "WHOLESALE COST" << setw(16) << "RETAIL COST" << setw(10) << "DATE ADDED" << endl;
		cout << "=============================================================================================================" << endl;

		for (int i = 0; i < data.size(); i++) {

			cout << "#" << setw(6) << i + 1 << setw(50) << data[i].description
				<< setw(8) << data[i].current_stock << " $" << fixed << setprecision(2)
				<< setw(15) << data[i].wholesale_cost << " $"
				<< setw(15) << data[i].retail_cost
				<< setw(10) << data[i].date_added << endl;

		}

		cout << "=============================================================================================================" << endl;

	}

	else {
		cout << "ERROR: There are no records to display." << endl;
	}

	cout << endl;

}

void showQuantityTotal(vector<Item> data) {

	double total = 0;

	for (int i = 0; i < data.size(); i++) {

		total += data[i].current_stock;

	}

	cout << "Total amount of inventory items: " << total << endl;

}

void showWholesaleTotal(vector<Item> data) {

	double total = 0;

	for (int i = 0; i < data.size(); i++) {

		total += data[i].current_stock * data[i].wholesale_cost;

	}

	cout << "Wholesale total of inventory: $" << fixed << setprecision(2) << total << endl;

}

void showRetailTotal(vector<Item> data) {

	double total = 0;

	for (int i = 0; i < data.size(); i++) {

		total += data[i].current_stock * data[i].retail_cost;

	}

	cout << "Retail total of inventory: $" << fixed << setprecision(2) << total << endl;

}



