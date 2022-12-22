//19. Check Writer
//
//Write a program that displays a simulated paycheck.The program should ask the user to
//enter the date, the payee’s name, and the amount of the check(up to $10, 000).It should
//then display a simulated check with the dollar amount spelled out, as shown here :
//
//Date: 11 / 24 / 2014
//Pay to the Order of : John Phillips $1920.85
//
//One thousand nine hundred twenty and 85 cents
//
//Be sure to format the numeric value of the check in fixed - point notation with two
//decimal places of precision.Be sure the decimal place always displays, even when the
//number is zero or has no fractional part.Use either C - strings or string class objects
//in this program.
//
//Input Validation : Do not accept negative dollar amounts, or amounts over $10, 000.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int		DATE_LENGTH = 10;
const string	MONTHS[] = { "January", "February", "March", "April", "May",	"June",
							"July", "August", "September", "October", "November", "December" };
const string	NUMBERS[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const string	TENS[] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
const string	TEENS[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };


double doubleValidation(double, double);
string dateInput();
bool checkDate(int, int, int, const string[]);
string nameInput();
double paycheckAmountInput();
string trim(string);
string amountToWordsConversion(double);
void showPaycheck(string, string, double, string);

int main() {

	string date, name, text_amount;
	double amount;

	date = dateInput();
	name = nameInput();
	amount = paycheckAmountInput();
	text_amount = amountToWordsConversion(amount);

	cout << endl;

	showPaycheck(date, name, amount, text_amount);

}

double doubleValidation(double min_limit, double max_limit) {

	double num;

	while (!(cin >> num) || num < min_limit || num > max_limit) {
		cout << "Error: Value must be an integer greater than " << min_limit << " and less than " << max_limit << ". Re-enter your value: ";
		cin.clear();
	}

	num += 0.00;

	return num;

}

string dateInput() {

	string date, mm, dd, yyyy;
	int i = 0, month, day, year;
	bool valid_date = false;

	do {

		mm = "", dd = "", yyyy = "";

		cout << "Enter the date of the payment in mm/dd/yyyy format: ";
		getline(cin, date);
		cin.clear();
		cout << endl;

		if (date.length() != DATE_LENGTH || date[2] != '/' || date[5] != '/') {

			cout << "Error: " << date << " must be in the following format: mm/dd/yyyy" << endl;

		}

		else {
		
			for (int j = 0; j < DATE_LENGTH; j++) {

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
	
	return date;

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

string nameInput() {

	string name;

	cout << "Enter your full name: ";
	getline(cin, name);
	cin.clear();

	return name;

}

double paycheckAmountInput() {

	double amount;

	cout << "Enter the value of the paycheck: ";

	amount = doubleValidation(0, 10000);

	return amount;

}

string trim(string amount) {

	int position;

	while (amount[0] == 0 || !isdigit(amount[0])) {
		amount.erase(0, 1);
	}

	position = amount.find('.', 0);

	while (amount.length() != position + 3) {
		amount.resize(amount.length() - 1);
	}

	return amount;

}

string amountToWordsConversion(double amount) {

	string amount_string = to_string(amount);
	amount_string = trim(amount_string);
	string amount_words = "";
	string text;
	int size = amount_string.length();
	int num, temp, temp_teens, position;
	vector<int> amount_denominations;
	bool	thousands = false, hundreds = false, teens = false, tens = false,
			units = false, dimes = false, dime_teens = false, cents = false;

	position = amount_string.find('.', 0);

	for (int i = 0; i < size; i++) {

		if (amount_string[i] != '.') {

			//int num;
			//string text;
			text = amount_string[i];
			num = stoi(text);
			amount_denominations.push_back(num);

		}
		else {
			amount_denominations.push_back(-1);
		}

	}

	for (int j = 0; j < amount_denominations.size(); j++) {

		temp = amount_denominations[j];

		if (position - j == 4) {
			thousands = true;
			amount_words += NUMBERS[temp] + " thousand";
		}

		else if (position - j == 3) {


			if (temp != 0) {

				hundreds = true;

				if (thousands) {
					amount_words += ", " + NUMBERS[temp] + " hundred";
				}
				else {
					amount_words += NUMBERS[temp] + " hundred";
				}
			}
			
		}

		else if (position - j == 2) {

			if (temp == 1) {
				teens = true;
				tens = true;
				temp_teens = amount_denominations[j + 1];
				amount_words += ", " + TEENS[temp_teens];
			}

			else if (temp != 0 && temp != 1) {
				tens = true;
			amount_words += ", " + TENS[temp - 2];
			}

		}

		else if (position - j == 1) {

			units = true;

			if (temp == 0) {
				continue;
			} 

			else {

				units = true;

				if (temp != 0 && tens && !teens) {
					amount_words += "-" + NUMBERS[temp];
				}

				else if (thousands || hundreds || tens) {
					amount_words += " and " + NUMBERS[temp];
				}

				else {
					amount_words += NUMBERS[temp];
				}

			}

			

		}

		else if (position - j == 0) {
			amount_words += " dollars";
		}

		else if (position - j == -1) {

			if (temp != 0) {

				dimes = true;

				if (temp == 1) {
					dime_teens = true;
					temp_teens = amount_denominations[j + 1];
					amount_words += " and " + TEENS[temp_teens];
				}

				else if (temp != 0 && temp != 1) {
					amount_words += " and " + TENS[temp - 2];
				}

			}

		}

		else if (position - j == -2) {

			if (temp == 0) {

				if (!dimes) {
					amount_words += ".";
				}

				else {
					amount_words += " cents.";
				}

			}			

			else {
			
				if (!dime_teens && dimes) {
					amount_words += "-" + NUMBERS[temp] + " cents.";
				}
				else {
					amount_words += " and " + NUMBERS[temp] + " cents.";
				}
			
			}

		}

	}

	amount_words[0] = toupper(amount_words[0]);

	return amount_words;

}

void showPaycheck(string date, string name, double amount, string text_amount) {

	cout << "PAYCHECK: " << endl;
	cout << "==================================================================" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\tDate: " << date << endl;
	cout << endl;
	cout << "Pay to the Order of: " << name << "\t\t\t$" << setprecision(2) << fixed << amount << endl;
	cout << endl;
	cout << text_amount << endl;
	cout << endl;

}
