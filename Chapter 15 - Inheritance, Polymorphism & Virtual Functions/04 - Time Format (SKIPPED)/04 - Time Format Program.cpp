//4. Time Format
//
//In Program 15 - 20, the file Time.h contains a Time class.Design a class called MilTime
//that is derived from the Time class.The MilTime class should convert time in military
//(24 - hour) format to the standard time format used by the Time class.The class should
//have the following member variables :
//
//milHours: Contains the hour in 24 - hour format.For example, 1 : 00 pm would be
//stored as 1300 hours, and 4 : 30 pm would be stored as 1630 hours.
//
//milSeconds : Contains the seconds in standard format.
//
//The class should have the following member functions :
//
//Constructor: The constructor should accept arguments for the hourand seconds, in
//military format.The time should then be converted to standard time
//and stored in the hours, min, and sec variables of the Time class.
//
//setTime : Accepts arguments to be stored in the milHoursand milSeconds
//variables.The time should then be converted to standard timeand
//stored in the hours, min, and sec variables of the Time class.
//
//getHour : Returns the hour in military format.
//
//getStandHr : Returns the hour in standard format.
//
//Demonstrate the class in a program that asks the user to enter the time in military format.
//The program should then display the time in both militaryand standard format.
//
//Input Validation : The MilTime class should not accept hours greater than 2359, or less
//than 0. It should not accept seconds greater than 59 or less than 0.

#include "MilTime.h"

using namespace std;

int main() {

	cout << "=========================\n";
	cout << "15-04 TIME FORMAT PROGRAM\n";
	cout << "=========================\n";
	cout << "\n";

	MilTime military_watch(1001,49);
	Time clock(23,41,19);

	cout << clock << "\n";
	cout << military_watch << "\n";

}