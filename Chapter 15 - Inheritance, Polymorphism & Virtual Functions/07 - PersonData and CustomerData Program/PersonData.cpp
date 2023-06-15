#include "PersonData.h"

using std::cout;
using std::getline;

PersonData::PersonData() {

	lastName = "";
	firstName = "";
	address = "";
	city = "";
	state = "";
	zip = "";
	phone = "";

}

PersonData::PersonData(string l, string f, string a, string c, string s, string z, string p) {

	lastName = l;
	firstName = f;
	address = a;
	city = c;
	state = s;
	zip = z;
	phone = p;

}

void PersonData::print(ostream& strm) const {

	strm << "Last name: " << lastName << "\n";
	strm << "First name: " << firstName << "\n";
	strm << "Address: " << address << "\n";
	strm << "City: " << city << "\n";
	strm << "State: " << state << "\n";
	strm << "Zip: " << zip << "\n";
	strm << "Phone: " << phone << "\n";

}

void PersonData::enterData(istream& strm) {

	cout << "Last name: ";
	getline(strm, lastName);

	cout << "First name: ";
	getline(strm, firstName);

	cout << "Address: ";
	getline(strm, address);

	cout << "City: ";
	getline(strm, city);

	cout << "State: ";
	getline(strm, state);

	cout << "Zip: ";
	getline(strm, zip);

	cout << "Phone: ";
	getline(strm, phone);

}

ostream& operator << (ostream& strm, const PersonData& P) {

	P.print(strm);
	return strm;

}

istream& operator >> (istream& strm, PersonData& p) {

	p.enterData(strm);
	return strm;

}