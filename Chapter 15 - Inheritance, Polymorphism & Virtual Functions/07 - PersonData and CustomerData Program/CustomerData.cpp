#include "CustomerData.h"

using std::cout;

CustomerData::CustomerData(string l, string f, string a, string c, string s,
	string z, string p, int num, bool b) : PersonData(l, f, a, c, s, z, p) {

	customerNumber = num;
	mailingList = b;

}

void CustomerData::print(ostream& strm) const {

	PersonData::print(strm);

	strm << "Customer number: " << customerNumber << "\n";
	strm << "Mailing list: ";

	if (mailingList == 1) {
		strm << "TRUE" << "\n";
	}
	else {
		strm << "FALSE" << "\n";
	}

}

void CustomerData::enterData(istream& strm) {

	PersonData::enterData(strm);

	bool isValid = false;

	cout << "Customer number: ";
	strm >> customerNumber;

	while (!isValid) {

		cout << "Mailing list (Enter 1 for Y / 0 for N): ";
		strm >> mailingList;

		if (mailingList != 0 && mailingList != 1) {
			cout << "ERROR: Incorrect value.\n ";
			cout << "\n";
		}
		else {
			isValid = true;
		}

	}

}