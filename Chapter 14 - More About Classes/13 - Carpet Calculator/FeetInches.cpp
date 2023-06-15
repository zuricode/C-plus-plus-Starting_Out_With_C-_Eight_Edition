// Implementation file for the FeetInches class
#include <cstdlib>  // Needed for abs()
#include "FeetInches.h"

//************************************************************
// Definition of member function simplify. This function     *
// checks for values in the inches member greater than       *
// twelve or less than zero. If such a value is found,       *
// the numbers in feet and inches are adjusted to conform    *
// to a standard feet & inches expression. For example,      *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet -2 inches would be adjusted to 4 feet 10 inches.   *
//************************************************************

void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}

//**********************************************
// Overloaded binary + operator.               *
//**********************************************

FeetInches FeetInches::operator + (const FeetInches &right)
{
	FeetInches temp;

	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}


//**********************************************
// Overloaded binary - operator.               *
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
	FeetInches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();	
	return temp;
}

//**********************************************
// Multiply function
//**********************************************

FeetInches FeetInches::multiply (const FeetInches& right) {

	FeetInches result;

	result.feet = feet * right.feet;
	result.inches = inches * right.inches;
	result.simplify();

	return result;

}

//*************************************************************
// Overloaded prefix ++ operator. Causes the inches member to *
// be incremented. Returns the incremented object.            *
//*************************************************************

FeetInches FeetInches::operator ++ ()
{
	++inches;
	simplify();
	return *this;
}

//***************************************************************
// Overloaded postfix ++ operator. Causes the inches member to  *
// be incremented. Returns the value of the object before the   *
// increment.                                                   *
//***************************************************************

FeetInches FeetInches::operator ++ (int)
{
	FeetInches temp(feet, inches);

	inches++;
	simplify();
	return temp;
}

//************************************************************
// Overloaded > operator. Returns true if the current object *
// is set to a value greater than that of right.             *
//************************************************************

bool FeetInches::operator > (const FeetInches &right)
{
	bool status;

	if (feet > right.feet)
		status = true;
	else if (feet == right.feet && inches > right.inches)
		status = true;
	else
		status = false;

	return status;
}

//************************************************************
// Overloaded < operator. Returns true if the current object *
// is set to a value less than that of right.                *
//************************************************************

bool FeetInches::operator < (const FeetInches &right)
{
	bool status;

	if (feet < right.feet)
		status = true;
	else if (feet == right.feet && inches < right.inches)
		status = true;
	else
		status = false;

	return status;
}

//*************************************************************
// Overloaded == operator. Returns true if the current object *
// is set to a value equal to that of right.                  *
//*************************************************************

bool FeetInches::operator == (const FeetInches &right)
{
	bool status;

	if (feet == right.feet && inches == right.inches)
		status = true;
	else
		status = false;

	return status;
}

//********************************************************
// Overloaded << operator. Gives cout the ability to     *
// directly display FeetInches objects.                  *
//********************************************************

ostream &operator<<(ostream &strm, const FeetInches &obj)
{
	strm << obj.feet << " feet, " << obj.inches << " inches";
	return strm;
}

//********************************************************
// Overloaded >> operator. Gives cin the ability to      *
// store user input directly into FeetInches objects.    *
//********************************************************

istream &operator >> (istream &strm, FeetInches &obj)
{
	// Prompt the user for the feet.
	cout << "Feet: ";

	while (!(strm >> obj.feet) || obj.feet < 0) {
		cout << "ERROR: Feet value must be greater than 0.\n";
		cout << "\n";
		strm >> obj.feet;
	}

	// Prompt the user for the inches.
	cout << "Inches: ";

	while (!(strm >> obj.inches) || obj.inches < 0) {
		cout << "ERROR: Inches value must be greater than 0.\n";
		cout << "\n";
		strm >> obj.inches;
	}

	// Normalize the values.
	obj.simplify();

	return strm;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to a double.                                               *
//*************************************************************

FeetInches::operator double()
{
	double temp = feet;

	temp += (inches / 12.0);
	return temp;
}

//*************************************************************
// Conversion function to convert a FeetInches object         *
// to an int.                                                 *
//*************************************************************

FeetInches:: operator int()
{ 
   return feet; 
}

bool FeetInches::operator <= (const FeetInches& obj) {

	int operand_1 = 0;
	int operand_2 = 0;

	for (int i = 0; i < feet; i++) {
		operand_1 += 12;
	}

	operand_1 += inches;

	for (int i = 0; i < obj.feet; i++) {
		operand_2 += 12;
	}

	operand_2 += obj.inches;

	if (operand_1 <= operand_2) {
		return true;
	}
	else {
		return false;
	}

}

bool FeetInches::operator >= (const FeetInches& obj) {

	int operand_1 = 0;
	int operand_2 = 0;

	for (int i = 0; i < feet; i++) {
		operand_1 += 12;
	}

	operand_1 += inches;

	for (int i = 0; i < obj.feet; i++) {
		operand_2 += 12;
	}

	operand_2 += obj.inches;

	if (operand_1 >= operand_2) {
		return true;
	}
	else {
		return false;
	}

}

bool FeetInches::operator != (const FeetInches& obj) {

	int operand_1 = 0;
	int operand_2 = 0;

	for (int i = 0; i < feet; i++) {
		operand_1 += 12;
	}

	operand_1 += inches;

	for (int i = 0; i < obj.feet; i++) {
		operand_2 += 12;
	}

	operand_2 += obj.inches;

	if (operand_1 != operand_2) {
		return true;
	}
	else {
		return false;
	}

}