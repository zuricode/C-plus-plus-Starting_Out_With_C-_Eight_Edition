#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::ostream;
using std::istream;
using std::numeric_limits;
using std::streamsize;
using std::left;
using std::setw;

class EmployeeInfo {

private:

	int id;
	string name;

public:

	EmployeeInfo();									// Default constructor
	~EmployeeInfo();								// Destructor

	EmployeeInfo(const int&, const string);			// Parameterized Constructor

	EmployeeInfo(const EmployeeInfo&);				// Copy constructor
	EmployeeInfo& operator=(const EmployeeInfo&);	// Copy assignment operator
	EmployeeInfo(EmployeeInfo&&);					// Move constructor
	EmployeeInfo& operator=(EmployeeInfo&&);		// Move assignment operator

	bool operator >(const EmployeeInfo&);			// Greater than assignment operator
	bool operator <(const EmployeeInfo&);			// Lesser than assignment operator
	bool operator ==(const EmployeeInfo&);			// Lesser than assignment operator

	friend ostream& operator << (ostream&, const EmployeeInfo&);		// ostream assignment operator
	friend istream& operator >> (istream&, EmployeeInfo&);				// istream assignment operator

	void setId(const int);
	void setName(const string);

	int getId() const;
	string getName() const;

};

#endif