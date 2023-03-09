#include <iostream>
#include <string>

using namespace std;

const int DATE_SIZE{ 10 };

class Date {

private:
	string full_date;
public:
	void setDate(string);
	string getDate();
};

void Date::setDate(string date) {
	full_date = date;
}

string Date::getDate() {
	return full_date;
}

int main() {

	Date special_day;
	string custom_date;

	cout << "Enter a date: ";
	getline(cin, custom_date);

	special_day.setDate(custom_date);
	
	cout << "Your chosen date is " << special_day.getDate() << endl;
	
}