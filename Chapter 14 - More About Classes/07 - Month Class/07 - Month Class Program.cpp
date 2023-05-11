#include "Month.h"
#include <iostream>

using std::cout;

void displayMonthInfo(Month);

int main() {

	Month month_1;
	Month month_2(5);
	Month month_3;

	cout << "Month 1" << "\n";
	cout << "-------" << "\n";
	displayMonthInfo(month_1);

	cout << "Month 2" << "\n";
	cout << "-------" << "\n";
	displayMonthInfo(month_2);

	month_3.setName("april");
	cout << "Month 3" << "\n";
	cout << "-------" << "\n";
	displayMonthInfo(month_3);

	month_3.setName("august");
	cout << "Month 3" << "\n";
	cout << "-------" << "\n";
	displayMonthInfo(month_3);

	month_3.setMonthNumber(11);
	cout << "Month 3" << "\n";
	cout << "-------" << "\n";
	displayMonthInfo(month_3);
	

}

void displayMonthInfo(Month m) {

	cout << "Month: " << m.getName() << " - Number: " << m.getMonthNumber() << "\n";
	cout << "\n";

}