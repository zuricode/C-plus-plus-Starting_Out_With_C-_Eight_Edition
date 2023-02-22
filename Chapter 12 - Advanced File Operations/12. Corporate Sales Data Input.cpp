//12. Corporate Sales Data Input
//
//Write a program that reads the data in the file created by the program in Programming
//Challenge 11. The program should calculate and display the following figures :
//
//• Total corporate sales for each quarter
//• Total yearly sales for each division
//• Total yearly corporate sales
//• Average quarterly sales for the divisions
//• The highest and lowest quarters for the corporation

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

const int DIVISIONS = 4;
const int QUARTERS = 4;
const int NAME_SIZE = 51;

struct				Division {

	char			name[NAME_SIZE]{ 'A' };
	double			sales[QUARTERS]{ 0, 0, 0, 0 };

};

struct Company {

	Division div[DIVISIONS];

};

Company importSalesData();
void displayCompanyData(Company, const int);

void showSalesPerQuarter(Company, const int, const int);
void showYearlySalesPerDivision(Company, const int, const int);
void showYearlyCorporateSales(Company, const int, const int);
void showAverageQuarterlySalesPerDivision(Company, const int, const int);
void showHighestAndLowestQuarters(Company, const int, const int);

int main() {

	Company company;

	company = importSalesData();

	displayCompanyData(company, DIVISIONS);

	showSalesPerQuarter(company, QUARTERS, DIVISIONS);

	showYearlySalesPerDivision(company, DIVISIONS, QUARTERS);

	showYearlyCorporateSales(company, DIVISIONS, QUARTERS);

	showAverageQuarterlySalesPerDivision(company, DIVISIONS, QUARTERS);

	showHighestAndLowestQuarters(company, QUARTERS, DIVISIONS);

}

Company importSalesData() {

	ifstream file;
	Company company;

	string location;

	cout << "Enter the location of the sales data file: ";
	getline(cin, location);

	cout << endl;

	file.open(location, ios::in);

	if (file.fail()) {
		cout << "Error opening " << location << ". Re-run the program with a valid file." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}
	else {

		cout << location << " was successfully opened." << endl;

		cout << "Importing file data..." << endl;
		cout << endl;

		cout << fixed << setprecision(2) << endl;

		file.read(reinterpret_cast<char*>(&company), sizeof(company));

		cout << endl;

	}

	file.close();

	return company;

}

void displayCompanyData(Company company, const int DIVISIONS) {

	cout << "COMPANY REPORT" << endl;
	cout << endl;
	cout << left << setw(13) << "Quarter" << setw(13) << "#1" << setw(13) << "#2" << setw(13) << "#3" << setw(13) << "#4" << endl;
	cout << left << setfill('=') << setw(70) << "" << endl;

	for (int i = 0; i < DIVISIONS; i++) {

		cout << left << setfill(' ') << setw(13) << company.div[i].name;

		cout << fixed << setprecision(2);

		for (int j = 0; j < DIVISIONS; j++) {
			cout << "$" << setw(12) << company.div[i].sales[j];
		}

		cout << endl;

	}

	cout << endl;

}

void showSalesPerQuarter(Company company, const int QUARTERS, const int DIVISIONS) {

	double total;

	for (int i = 0; i < QUARTERS; i++) {

		total = 0;

		cout << "Q" << i + 1 << " sales: $";

		for (int j = 0; j < DIVISIONS; j++) {

			total += company.div[j].sales[i];

		}

		cout << total << endl;

	}

	cout << endl;

}

void showYearlySalesPerDivision(Company company, const int DIVISIONS, const int QUARTERS) {

	cout << fixed << setprecision(2);

	double total;

	for (int i = 0; i < DIVISIONS; i++) {

		total = 0;

		for (int j = 0; j < QUARTERS; j++) {

			total += company.div[i].sales[j];

		}

		cout << company.div[i].name << " division annual sales: $" << total << endl;

	}

	cout << endl;

}

void showYearlyCorporateSales(Company company, const int DIVISIONS, const int QUARTERS) {

	double total = 0;

	cout << fixed << setprecision(2);

	for (int i = 0; i < DIVISIONS; i++) {

		for (int j = 0; j < QUARTERS; j++) {

			total += company.div[i].sales[j];

		}

	}

	cout << "Total yearly corporate sales: $" << total << endl;

	cout << endl;

}

void showAverageQuarterlySalesPerDivision(Company company, const int DIVISIONS, const int QUARTERS) {

	double total;
	double average;
	
	cout << fixed << setprecision(2);

	for (int i = 0; i < DIVISIONS; i++) {

		total = 0;

		for (int j = 0; j < QUARTERS; j++) {

			total += company.div[i].sales[j];

		}

		average = total / QUARTERS;

		cout << "Quarterly average for " << company.div[i].name << ": $" << average << endl;

	}

	cout << endl;

}

void showHighestAndLowestQuarters(Company company, const int QUARTERS, const int DIVISION) {

	double total;
	double highest_sales = 0, lowest_sales = 0;
	int highest_quarter = 0, lowest_quarter = 0;

	cout << fixed << setprecision(2);

	for (int i = 0; i < QUARTERS; i++) {

		total = 0;

		for (int j = 0; j < DIVISION; j++) {

			total += company.div[j].sales[i];

		}

		if (i == 0) {
			highest_sales = total;
			lowest_sales = total;
			highest_quarter = i + 1;
			lowest_quarter = i + 1;
		}

		else if (total > highest_sales) {
			highest_sales = total;
			highest_quarter = i + 1;
		}

		else if (total < lowest_sales) {
			lowest_sales = total;
			lowest_quarter = i + 1;
		}

	}

	cout << "Best performing quarter: Q" << highest_quarter << " - Sales: $" << highest_sales << endl;
	cout << "Worst performing quarter: Q" << lowest_quarter << " - Sales: $" << lowest_sales << endl;

	cout << endl;

}

