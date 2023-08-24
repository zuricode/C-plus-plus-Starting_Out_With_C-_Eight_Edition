//9. Gas Prices
//
//In the student sample program files for this chapter, you will find a text file
//named GasPrices.txt. The file contains the weekly average prices for a gallon of gas in the U.S,
//beginning on April 5, 1993 and ending on August 26, 2013. Figure 17-10 shows an
//example of the first few lines of the file's contents.
//
//Each line in the file contains the average price for a gallon of gas on a specific
//date. Each line is formatted in the following way:
//
//	MM-DD-YYYY:Price
//
//MM is the two-digit month, DD is the two-digit day, and YYYY is the four-digit
//year. Price is the average price per gallon of gas on the specified date.
//
//For this assignment, you are write one or more programs that read the contents
//of the file and perform the following calculations:
//
//Average Price Per Year: Calculate the average price of gas per year, for each
//year in the file. (The file's data starts in April of 1993, and it ends in August
//2013. Use the data that is present for the years 1993 and 2013.)
//
//Average Price Per Month: Calculate the average price for each month in the file.
//
//Highest and Lowest Prices Per Year: For each year in the file, determine the date
//and amount for the lowest price, and the highest price.
//
//List of Prices, Lowest to Highest: Generate a text file that lists the dates and
//prices, sorted from the lowest price to the highest.
//
//List of Prices, Highest to Lowest: Generate a text file that lists the dates and
//prices, sorted from the highest price to the lowest.

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<iomanip>
#include<set>

using namespace std;

int menu();
void importFileData(vector<string>&);
void displayAveragePricePerYear(const vector<string>&);
void displayAveragePricePerMonth(const vector<string>&);
void displayHighestLowestPerYear(const vector<string>&);

void createWeeklyPriceMap(const vector<string>&, map<double, string>&);
void exportWeeklyPriceLowestToHighest(const map<double, string>&);
void exportWeeklyPriceHighestToLowest(const map<double, string>&);


void displayVector(const vector<string, double>&, const string, const string, const int);
void displayMap(const map<string, double>&, const string, const string, const int);

string monthAsWord(const string&);

int main() {

	const string GAS_PRICES = "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C - plus - plus - Starting_Out_With_C - _Eight_Edition\\Chapter 17 - Introduction to the Standard Template Library\\09 - Gas Prices\\GasPrices.txt";

	int menu_choice;
	vector<string> file_data;
	map<double, string> weeklyPrices;

	cout << "========================\n";
	cout << "17-09 GAS PRICES PROGRAM\n";
	cout << "========================\n";
	cout << "\n";

	importFileData(file_data);

	do {

		menu_choice = menu();

		switch (menu_choice) {
		case 1:
			displayAveragePricePerYear(file_data);
			break;
		case 2:
			displayAveragePricePerMonth(file_data);
			break;
		case 3:
			displayHighestLowestPerYear(file_data);
			break;
		case 4:
			createWeeklyPriceMap(file_data, weeklyPrices);
			exportWeeklyPriceLowestToHighest(weeklyPrices);
			break;
		case 5:
			createWeeklyPriceMap(file_data, weeklyPrices);
			exportWeeklyPriceHighestToLowest(weeklyPrices);
			break;
		default:
			cout << "This feature is not ready yet\n";
			cout << "\n";
			break;
		}

	} while (menu_choice != 6);

	cout << "You have chosen to exit the program.\n";
	cout << "Exiting the program...\n";
	cout << "\n";

}

int menu() {

	int choice;

	cout << "----\n";
	cout << "MENU\n";
	cout << "----\n";
	cout << "\n";

	cout << "1. Average Price Per Year\n";
	cout << "2. Average Price Per Month\n";
	cout << "3. Highest and Lowest Prices Per Year\n";
	cout << "4. List of Prices, Lowest to Highest\n";
	cout << "5. List of Prices, Highest to Lowest\n";
	cout << "6. Quit Program\n";

	cout << "\n";

	cout << "Enter your selection: ";
	
	while (!(cin >> choice) || (choice < 1 || choice > 6)) {
		cout << "ERROR: You have entered an invalid option.\n";
		cout << "Please enter a value between 1 - 6.\n";
		cin.clear();
		cin.ignore();
		cout << "\n";
		cout << "Enter your selection: ";
	}

	cin.clear();
	cin.ignore();
	cout << "\n";

	return choice;

}

void importFileData(vector<string>& vector) {

	ifstream file;
	string file_location;
	string line;

	do {

		cout << "Enter the location for the GasPrices.txt file: ";
		getline(cin, file_location);

		file.open(file_location, ios::in);

		if (file.fail()) {
			cout << "ERROR: You have provided an invalid file location.\n";
			cout << "\n";
		}
		else {
			cout << "File was successfully opened.\n";
			file.clear();
		}

	} while (file.fail());

	cout << "\n";

	while (file >> line) {
		vector.push_back(line);
	}

	cout << "File data was successfully imported into the program.\n";
	cout << "\n";

}

void displayAveragePricePerYear(const vector<string>& VECTOR) {

	map<string, double> averagePrices;
	string price_as_string;
	string average_as_string;
	string current_year = "";
	string old_year = "";
	string current_line;
	vector<double> prices;
	double average;

	vector<string>::const_iterator cit;
	vector<double>::iterator it;

	for (cit = VECTOR.begin(); cit != VECTOR.end(); cit++) {

		current_year = "";
		current_line = *cit;

		current_year += current_line[6];
		current_year += current_line[7];
		current_year += current_line[8];
		current_year += current_line[9];

		if (old_year == "") {
			old_year = current_year;
		}		

		if (current_year == old_year) {

			price_as_string = "";

			for (int i = 11; i < current_line.size(); i++) {
				price_as_string += current_line[i];
			}

			prices.push_back(stod(price_as_string));

		} if (current_year != old_year || cit == (VECTOR.end() - 1)) {
			
			average = 0;

			for (it = prices.begin(); it != prices.end(); it++) {
				average += *it;					
			}

			average /= prices.size();
			averagePrices.insert(make_pair(old_year, average));
			prices.clear();

			old_year = current_year;

		}

	}

	displayMap(averagePrices, "YEAR", "AVERAGE PRICE", 15);

}

void displayAveragePricePerMonth(const vector<string>& VECTOR) {

	vector<string> month;
	vector<double> average_monthly_price;
	vector<double> prices;

	vector<string>::const_iterator cit;

	string current_line;
	string current_month;
	string current_year;
	string old_year = "";
	string current_price;
	string old_month = "";
	string single_month;
	string month_and_year;
	double total;
	double average;

	for (cit = VECTOR.begin(); cit != VECTOR.end(); cit++) {

		total = 0;

		current_line = *cit;
		current_month = "";
		current_price = "";
		current_year = "";

		for (int i = 0; i < 2; i++) {
			current_month += current_line[i];
		}

		for (int i = 6; i <10; i++) {
			current_year += current_line[i];
		}

		if (old_month == "") {
			old_month = current_month;
			old_year = current_year;
		}

		if (current_month != old_month || cit == (VECTOR.end() - 1)) {

			for (auto element : prices) {
				total += element;
			}

			average = total / prices.size();

			prices.clear();

			single_month = monthAsWord(old_month);

			month_and_year = single_month + ", " + old_year;

			month.push_back(month_and_year);
			average_monthly_price.push_back(average);

			old_month = current_month;
			old_year = current_year;

		}

		if (current_month == old_month) {

			for (int i = 11; i < current_line.size(); i++) {
				current_price += current_line[i];
			}

			prices.push_back(stod(current_price));

		}

	}

	cout << left;

	cout << "-----------------------------------\n";
	cout << "LIST OF AVERAGE GAS PRICES PER MONTH\n";
	cout << "-----------------------------------\n";
	cout << "\n";

	cout << setw(25) << "MONTH" << "AVERAGE PRICE" << "\n";
	cout << setfill('-') << setw(25 * 2) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

	cout << fixed << setprecision(3);

	for (int i = 0; i < month.size(); i++) {
		cout << setw(25) << month[i] << "$" << average_monthly_price[i] << "\n";
	}

	cout << "\n";
	cout << setfill('-') << setw(25 * 2) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

}

string monthAsWord(const string& MONTH) {

	int m = stoi(MONTH);

	string month;

	switch (m) {

	case 1:
		month = "January";
		break;
	case 2:
		month = "February";
		break;
	case 3:
		month =  "March";
		break;
	case 4:
		month = "April";
		break;
	case 5:
		month = "May";
		break;
	case 6:
		month = "June";
		break;
	case 7:
		month = "July";
		break;
	case 8:
		month = "August";
		break;
	case 9:
		month = "September";
		break;
	case 10:
		month = "October";
		break;
	case 11:
		month = "November";
		break;
	case 12:
		month = "December";
		break;
	}

	return month;

}

void displayMap(const map<string, double>& MAP, const string HEADER_1, const string HEADER_2, const int WIDTH) {

	map<string, double>::const_iterator cit;

	cout << left;

	cout << "-----------------------------------\n";
	cout << "LIST OF AVERAGE GAS PRICES PER YEAR\n";
	cout << "-----------------------------------\n";
	cout << "\n";

	cout << setw(WIDTH) << HEADER_1 << HEADER_2 << "\n";
	cout << setfill('-') << setw(WIDTH * 2) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

	cout << fixed << setprecision(3);

	for (cit = MAP.begin(); cit != MAP.end(); cit++) {
		cout << setw(WIDTH) << cit->first << "$" << cit->second << "\n";
	}

	cout << "\n";
	cout << setfill('-') << setw(WIDTH * 2) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

}

void displayMap(const unordered_map<string, double>& MAP, const string HEADER_1, const string HEADER_2, const int WIDTH) {

	unordered_map<string, double>::const_iterator cit;

	cout << left;

	cout << "-----------------------------------\n";
	cout << "LIST OF AVERAGE GAS PRICES PER YEAR\n";
	cout << "-----------------------------------\n";
	cout << "\n";

	cout << setw(WIDTH) << HEADER_1 << HEADER_2 << "\n";
	cout << setfill('-') << setw(WIDTH * 2) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

	cout << fixed << setprecision(3);

	for (cit = MAP.begin(); cit != MAP.end(); cit++) {
		cout << setw(WIDTH) << cit->first << "$" << cit->second << "\n";
	}

	cout << "\n";
	cout << setfill('-') << setw(WIDTH * 2) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

}

void createWeeklyPriceMap(const vector<string>& VECTOR, map<double, string>& weeklyPrices) {

	vector<string>::const_iterator cit;

	string line;
	string month;
	string day;
	string year;
	string price_string;
	string date;

	double price;

	for (cit = VECTOR.begin(); cit != VECTOR.end(); cit++) {


		date = "";
		day = "";
		month = "";
		year = "";
		price_string = "";

		line = *cit;

		for (int i = 0; i < line.size(); i++) {

			if (i >= 0 && i < 2) {
				month += line[i];
			}
			else if (i >= 3 && i < 5)  {
				day += line[i];
			}
			else if (i >= 6 && i < 10) {
				year += line[i];
			}
			else if (i >= 11 && i < 16) {
				price_string += line[i];
			}

		}

		month = monthAsWord(month);

		date += month + " " + day + ", " + year;
		price = stod(price_string);

		weeklyPrices.insert(make_pair(price, date));

	}

}

void exportWeeklyPriceLowestToHighest(const map<double, string>& MAP) {

	ofstream file;
	string output_location;
	int width = 25;

	cout << "Enter the output location of your file: ";
	getline(cin, output_location);

	cout << "\n";

	file.open(output_location, ios::out | ios::app);

	map<double, string>::const_iterator cit;

	file << left << fixed << setprecision(3);

	file << "=============================================\n";
	file << "LIST OF WEEKLY GAS PRICES (LOWEST TO HIGHEST)\n";
	file << "=============================================\n";
	file << "\n";
	file << setw(width) << "WEEK" << "PRICE" << "\n";
	file << setfill('-') << setw(width * 2) << "";
	file << setfill(' ') << "\n";
	file << "\n";		 

	for (cit = MAP.begin(); cit != MAP.end(); cit++) {
		file << setw(width) << cit->second << "$" << cit->first << "\n";
	}

	file << "\n";

	file << setfill('-') << setw(width * 2) << "";
	file << setfill(' ') << "\n";
	file << "\n";

	file.close();

	cout << "Data was successfully exported to " << output_location << ".\n";
	cout << "\n";
	
	cout << "Output file has been closed.\n";
	cout << "\n";

}

void exportWeeklyPriceHighestToLowest(const map<double, string>& MAP) {

	ofstream file;
	string output_location;
	int width = 25;

	cout << "Enter the output location of your file: ";
	getline(cin, output_location);

	cout << "\n";

	file.open(output_location, ios::out | ios::app);

	map<double, string>::const_reverse_iterator crit;

	file << left << fixed << setprecision(3);

	file << "=============================================\n";
	file << "LIST OF WEEKLY GAS PRICES (HIGHEST TO LOWEST)\n";
	file << "=============================================\n";
	file << "\n";
	file << setw(width) << "WEEK" << "PRICE" << "\n";
	file << setfill('-') << setw(width * 2) << "";
	file << setfill(' ') << "\n";
	file << "\n";

	for (crit = MAP.rbegin(); crit != MAP.rend(); crit++) {
		file << setw(width) << crit->second << "$" << crit->first << "\n";
	}

	file << "\n";

	file << setfill('-') << setw(width * 2) << "";
	file << setfill(' ') << "\n";
	file << "\n";

	file.close();

	cout << "Data was successfully exported to " << output_location << ".\n";
	cout << "\n";

	cout << "Output file has been closed.\n";
	cout << "\n";

}

void displayHighestLowestPerYear(const vector<string>& VECTOR) {
	
	map<string, set<double>> priceMap;
	set<double> prices;

	vector<string>::const_iterator cit;
	map<string, set<double>>::iterator it;

	string current_line;
	string current_price;
	string current_year;
	string old_year = "";
	string lowest_price;
	string highest_price;

	for (cit = VECTOR.begin(); cit != VECTOR.end(); cit++) {

		current_line = *cit;

		current_price = "";
		current_year = "";

		for (int i = 6; i < 10; i++) {
			current_year += current_line[i];
		}

		for (int i = 11; i < current_line.size(); i++) {
			current_price += current_line[i];
		}

		if (old_year == "") {
			old_year = current_year;
			lowest_price = current_price;
			highest_price = current_price;
		}

		if (current_year != old_year || cit == (VECTOR.end() - 1)) {

			prices.insert(stod(highest_price));
			prices.insert(stod(lowest_price));

			priceMap.insert(make_pair(old_year, prices));

			prices.clear();

			old_year = current_year;
			lowest_price = current_price;
			highest_price = current_price;

		}		

		if (current_year == old_year) {

			if (stod(current_price) < stod(lowest_price)) {
				lowest_price = current_price;
			}

			if (stod(current_price) > stod(highest_price)) {
				highest_price = current_price;
			}

		}		

	}

	int width = 15;

	cout << left << fixed << setprecision(3);

	cout << "======================================\n";
	cout << "HIGHEST AND LOWEST GAS PRICES PER YEAR\n";
	cout << "======================================\n";
	cout << "\n";

	cout << setw(width - 5) << "YEAR" << setw(width) << "LOWEST PRICE" << "HIGHEST PRICE" << "\n";
	cout << setfill('-') << setw(width * 3) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

	for (it = priceMap.begin(); it != priceMap.end(); it++) {

		cout << setw(width - 5) << it->first << "$";

		for (auto element : it->second) {
			cout << setw(width) << element;
		} 
		
		cout << "\n";

	}
	
	cout << "\n";
	cout << setfill('-') << setw(width * 3) << "";
	cout << setfill(' ') << "\n";
	cout << "\n";

}