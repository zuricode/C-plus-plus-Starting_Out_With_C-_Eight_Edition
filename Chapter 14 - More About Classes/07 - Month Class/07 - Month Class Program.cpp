#include "Month.h"
#include <iostream>

using std::cout;
using std::cin;

void displayMonthInfo(Month);

int main() {

	Month month_1;
	Month month_2(5);
	Month month_3;

	month_3.setName("august");
	cout << month_3;

	++month_3;
	cout << month_3;

	++month_3;
	cout << month_3;

	--month_3;
	cout << month_3;

	--month_3;
	cout << month_3;

	month_3++;
	cout << month_3;

	month_3++;
	cout << month_3;

	cout << month_2;

	cout << month_1;

	cin >> month_1;

	cout << ++month_1;



}

void displayMonthInfo(Month m) {

	cout << "Month: " << m.getName() << " - Number: " << m.getMonthNumber() << "\n";
	cout << "\n";

}