//2. Time Format Exceptions
//
//Modify the MilTime class you created for Programming Challenge 4 of Chapter 15 .//
//The class should implement the following exceptions :
//
//BadHour Throw when an invalid hour(< 0 or > 2359) is passed to the class.
//BadSeconds Throw when an invalid number of seconds(< 0 or > 59) is passed
//to the class.
//
//Demonstrate the class in a driver program.

#include "MilTime.h"

int main() {

	cout << "======================================\n";
	cout << "16-02 - TIME FORMAT EXCEPTIONS PROGRAM\n";
	cout << "======================================\n";
	cout << "\n";

	MilTime miltime("1453", "42");
	bool try_again = true;

	while (try_again) {

		try {
			cin >> miltime;
			try_again = false;
			cout << "\n";
		}
		catch (MilTime::BadHour bH) {
			cout << "ERROR: " << bH.getBadHour() << " is an invalid value.\n";
			cout << "Hours value must be between " << MIN_MIL_HOURS << " and " << MAX_MIL_HOURS << ".\n";
			cout << "\n";
		}
		catch (MilTime::BadSeconds bS) {
			cout << "ERROR: " << bS.getBadSeconds() << " is an invalid value.\n";
			cout << "Seconds value must be between " << MIN_SECONDS << " and " << MAX_SECONDS << ".\n";
			cout << "\n";
		}

	}
	
	cout << miltime << "\n";

}