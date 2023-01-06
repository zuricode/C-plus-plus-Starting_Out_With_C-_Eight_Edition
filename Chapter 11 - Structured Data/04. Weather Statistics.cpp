//4. Weather Statistics
// 
//Write a program that uses a structure to store the following weather data for a particular
//month :
//Total Rainfall
//High Temperature
//Low Temperature
//Average Temperature
// 
//The program should have an array of 12 structures to hold weather data for an
//entire year.When the program runs, it should ask the user to enter data for each
//month. (The average temperature should be calculated.) Once the data are entered
//for all the months, the program should calculateand display the average monthly
//rainfall, the total rainfall for the year, the highestand lowest temperatures for the
//year(and the months they occurred in), and the average of all the monthly average
//temperatures.
// 
//Input Validation : Only accept temperatures within the range between –100 and +140
//degrees Fahrenheit.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int		MONTHS_INT = 12, MIN = -100, MAX = 140;
const string	MONTHS[MONTHS_INT]{"January", "February", "March", "April", "May", "June",
									"July", "August", "September", "October", "November", "December"};

enum			MonthsEnum { JANUARY, FEBRUARY, MARCH, APRIL, MAY,
					JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

struct WeatherData {

	double total_rainfall{};
	double high_t{};
	double low_t{};
	double average_t{};

};

double inputTemp();
double inputRainfall();
void getTempData(WeatherData[], MonthsEnum, double&, double&, string&, string&);
void showTempData(WeatherData[], MonthsEnum, double, double, string, string);


int main() {

	WeatherData monthly_weather[MONTHS_INT];
	MonthsEnum month_step {};
	double highest_temp, lowest_temp;
	string highest_month, lowest_month;

	getTempData(monthly_weather, month_step, highest_temp, lowest_temp, highest_month, lowest_month);
	showTempData(monthly_weather, month_step, highest_temp, lowest_temp, highest_month, lowest_month);
}

double inputRainfall() {

	double num;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Rainfall must be a number greater than 0. Re-enter your value:  ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double inputTemp() {

	double num;

	while (!(cin >> num) || num < MIN || num > MAX) {
		cout << "ERROR: Temperature must be a value between " << MIN << " and " << MAX << "F. Re-enter your value:  ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void getTempData(WeatherData w[], MonthsEnum month, double& h_t, double& l_t, string& h_m, string& l_m) {

	for (month = JANUARY; month <= DECEMBER; month = static_cast<MonthsEnum>(month + 1)) {

		cout << MONTHS[month] << ": " << endl;
		cout << "------------" << endl;
		cout << "Rainfall (in mm): ";
		w[month].total_rainfall = inputRainfall();

		cout << "High Temperature (in F): ";
		w[month].high_t = inputTemp();

		cout << "Low Temperature (in F): ";
		w[month].low_t = inputTemp();

		if (month == JANUARY) {
			h_t = w[month].high_t;
			l_t = w[month].low_t;
			h_m = MONTHS[month];
			l_m = MONTHS[month];
		}

		if (w[month].high_t > h_t) {
			h_t = w[month].high_t;
			h_m = MONTHS[month];
		}

		if (w[month].low_t < l_t) {
			l_t = w[month].low_t;
			l_m = MONTHS[month];
		}

		w[month].average_t = (w[month].high_t + w[month].low_t) / 2;

		cout << endl;

	}

}

void showTempData(WeatherData w[], MonthsEnum month, double h_t, double l_t, string h_m, string l_m) {

	double annual_rainfall = 0;
	double annual_average_rainfall;

	cout << fixed << setprecision(1);

	for (month = JANUARY; month <= DECEMBER; month = static_cast<MonthsEnum>(month + 1)) {

		cout << MONTHS[month] << " average rainfall: " << w[month].average_t << " mm" << endl;
		annual_rainfall += w[month].total_rainfall;

	}

	cout << endl;

	annual_average_rainfall = annual_rainfall / 12;

	cout << "Annual rainfall: " << annual_rainfall << "mm" << endl;
	cout << "Annual temperature: " << annual_average_rainfall << "F" << endl;
	cout << "Highest temperature: " << h_t << "F in " << h_m << endl;
	cout << "Lowest temperature: " << l_t << "F in " << l_m << endl;

}