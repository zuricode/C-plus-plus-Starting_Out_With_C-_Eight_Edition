//11. Corporate Sales Data Output
//
//Write a program that uses a structure to store the following data on a company division :
//
//Division Name(such as East, West, North, or South)
//Quarter(1, 2, 3, or 4)
//Quarterly Sales
//
//The user should be asked for the four quarters’ sales figures for the East, West, North,
//and South divisions.The data for each quarter for each division should be written to
//a file.
//
//Input Validation : Do not accept negative numbers for any sales figures.

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const int DIVISIONS = 4;
const int QUARTERS = 4;
const int NAME_SIZE = 51;

struct				Division {

	char			name[NAME_SIZE]{'A'};
	double			sales[QUARTERS]{0, 0, 0, 0};

};

struct Company {

	Division div[DIVISIONS];

};

double enterSales();

void enterCompanyData(Company&, const int);
void displayCompanyData(Company, const int);
void writeDataToFile(fstream &, Company, const int);

int main() {

	Company company;
	fstream file;

	enterCompanyData(company, QUARTERS);

	displayCompanyData(company, QUARTERS);

	writeDataToFile(file, company, QUARTERS);

}

double enterSales() {

	double sales;

	while (!(cin >> sales) || sales < 0) {
		cout << "ERROR: Sales figure cannot be a negative value. Re-enter your sales figure: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return sales;

}

void enterCompanyData(Company &company, const int QUARTERS) {

	cout << "COMPANY DATA INPUT: " << endl;
	cout << "======================" << endl;
	cout << endl;

	for (int i = 0; i < QUARTERS; i++) {

		cout << "Division Name: ";
		cin.getline(company.div[i].name, NAME_SIZE);

		cout << endl;

		for (int j = 0; j < DIVISIONS; j++) {

			cout << "Quarter #" << j + 1 << " sales: $";
			company.div[i].sales[j] = enterSales();

		}

		cout << endl;

	}

}

void displayCompanyData(Company company, const int QUARTERS) {

	cout << "COMPANY REPORT" << endl;
	cout << endl;
	cout << left << setw(13) << "Quarter" << setw(13) << "#1" << setw(13) << "#2" << setw(13) << "#3" << setw(13) << "#4" << endl;
	cout << left << setfill('=') << setw(70) << "" << endl;

	for (int i = 0; i < QUARTERS; i++) {

		cout << left << setfill(' ') << setw(13) << company.div[i].name;

		cout << fixed << setprecision(2);

		for (int j = 0; j < QUARTERS; j++) {
			cout << "$" << setw(12) << company.div[i].sales[j];
		}

		cout << endl;
			
	}

	cout << endl;

}

void writeDataToFile(fstream &file, Company company, const int QUARTERS) {

	string location;

	cout << "Enter the file location to export the company data: ";
	getline(cin, location);

	cout << endl;

	file.open(location, ios::out | ios::binary);

	if (!file) {
		cout << "Error opening " << location << ". Re-run the program and enter a different export location." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}
	else {

		cout << "Writing company data to file..." << endl;
		cout << endl;

		file.write(reinterpret_cast<char*>(&company), sizeof(company));

		cout << "Company data has been successfully exported to " << location << endl;

		file.close();

	}
	
}