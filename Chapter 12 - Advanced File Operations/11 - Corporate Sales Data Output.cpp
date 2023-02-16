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

const int	QUARTERS = 4;

struct				Company {

	string			name[QUARTERS] {"", "", "", ""};
	int				quarter[QUARTERS] {0, 0, 0, 0};
	double			sales[QUARTERS][QUARTERS]{ {0, 0, 0, 0}, 
												{0, 0, 0, 0},
												{0, 0, 0, 0},
												{0, 0, 0, 0}};

};

string	printDivisionName(int);
double enterSales();

Company enterCompanyData(const int);
void displayCompanyData(Company, const int);
void writeDataToFile(ofstream&, Company, const int);

int main() {

	Company company;
	ofstream file;

	company = enterCompanyData(QUARTERS);

	displayCompanyData(company, QUARTERS);

	writeDataToFile(file, company, QUARTERS);

}

string printDivisionName(int num) {

	string division_name;

	switch (num) {

	case 0:
		division_name = "East";
		break;
	case 1:
		division_name = "West";
		break;
	case 2:
		division_name = "North";
		break;
	case 3:
		division_name = "South";
		break;
	default:
		division_name = "INVALID DIVISION";
		break;

	}

	return division_name;

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

Company enterCompanyData(const int QUARTERS) {

	Company company;

	cout << "COMPANY DATA INPUT: " << endl;
	cout << "======================" << endl;
	cout << endl;

	for (int i = 0; i < QUARTERS; i++) {

		company.name[i] = printDivisionName(i);

		cout << "Division Name: " << company.name[i] << endl;
		cout << endl;

		for (int j = 0; j < QUARTERS; j++) {

			company.quarter[j] = j + 1;
			cout << "Quarter #" << j + 1 << " sales: $";
			company.sales[i][j] = enterSales();

		}

		cout << endl;

	}

	return company;

}

void displayCompanyData(Company company, const int QUARTERS) {

	cout << "COMPANY REPORT" << endl;
	cout << endl;
	cout << left << setw(13) << "Quarter" << setw(13) << "#1" << setw(13) << "#2" << setw(13) << "#3" << setw(13) << "#4" << endl;
	cout << left << setfill('=') << setw(70) << "" << endl;

	for (int i = 0; i < QUARTERS; i++) {

		cout << left << setfill(' ') << setw(13) << company.name[i];
		cout << fixed << setprecision(2);
		
		for (int j = 0; j < QUARTERS; j++) {
			cout << "$" << setw(12)	<< company.sales[i][j];
		}

		cout << endl;

	}

	cout << endl;

}

void writeDataToFile(ofstream& file, Company company, const int QUARTERS) {

	string location;

	cout << "Enter the file location to export the company data: ";
	getline(cin, location);

	cout << endl;

	file.open(location, ios::out );

	if (!file) {
		cout << "Error opening " << location << ". Re-run the program and enter a different export location." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}
	
		cout << "Writing company data to file..." << endl;
		cout << endl;

		file << "COMPANY REPORT" << endl;
		file << endl;
		file << left << setw(13) << "Quarter" << setw(13) << "#1" << setw(13) << "#2" << setw(13) << "#3" << setw(13) << "#4" << endl;
		file << left << setfill('=') << setw(70) << "" << endl;

		for (int i = 0; i < QUARTERS; i++) {

			file << left << setfill(' ') << setw(13) << company.name[i];
			file << fixed << setprecision(2);

			for (int j = 0; j < QUARTERS; j++) {
				file << "$" << setw(12) << company.sales[i][j];
			}

			file << endl;

		}

		file << endl;


	cout << "Company data has been successfully exported to " << location << endl;

	file.close();

}
