#include  "EmployeeInfo.h"

EmployeeInfo::EmployeeInfo() {

	id = 0;
	name = "";

}

EmployeeInfo::~EmployeeInfo() {

	id = 0;
	name = "";

}

EmployeeInfo::EmployeeInfo(const int& ID, const string NAME) {

	name = NAME;
	id = ID;

}

EmployeeInfo::EmployeeInfo(const EmployeeInfo& SOURCE) {

	name = SOURCE.name;
	id = SOURCE.id;

}

EmployeeInfo& EmployeeInfo::operator=(const EmployeeInfo& SOURCE) {

	if (this != &SOURCE) {

		delete this;

		this->name = SOURCE.name;
		this->id = SOURCE.id;

	}	

	return *this;

}

EmployeeInfo::EmployeeInfo(EmployeeInfo&& source) {

	id = source.id;
	name = source.name;
	source.id = 0;
	source.name = "";

}

EmployeeInfo& EmployeeInfo::operator=(EmployeeInfo&& source) {

	if (this != &source) {

		delete this;

		this->id = source.id;
		this->name = source.name;
		source.id = 0;
		source.name = "";

		return *this;

	}	

}

ostream& operator<<(ostream& strm, const EmployeeInfo& SOURCE) {

	strm << "Employee Name: " << SOURCE.name << " | ID: " << SOURCE.id << "\n";
	strm << "\n";

	return strm;

}

istream& operator>>(istream& strm, EmployeeInfo& employee) {

	string name;

	cout << "Employee Data Entry\n";
	cout << "-------------------\n";
	cout << "\n";
	cout << "Full Name: ";
	getline(strm, employee.name);

	cout << "ID: ";
	strm >> employee.id;

	cout << "\n";

	strm.ignore(numeric_limits<streamsize>::max(), '\n');

	return strm;

}

void EmployeeInfo::setId(const int ID) {
	id = ID;
}

void EmployeeInfo::setName(const string NAME) {
	name = NAME;
}

int EmployeeInfo::getId() const {
	return id;
}

string EmployeeInfo::getName() const {
	return name;
}