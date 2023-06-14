//5. Time Clock
//
//Design a class named TimeClock.The class should be derived from the MilTime class
//you designed in Programming Challenge 4. The class should allow the programmer to
//pass two times to it : starting time and ending time.The class should have a member
//function that returns the amount of time elapsed between the two times.For example,
//if the starting time is 900 hours(9:00 am), and the ending time is 1300 hours(1:00pm),
//the elapsed time is 4 hours.
//
//Input Validation : The class should not accept hours greater than 2359 or less than 0.

#include "TimeClock.h"
#include <iomanip>

using namespace std;

int main() {

	cout << "========================\n";
	cout << "15-05 TIME CLOCK PROGRAM\n";
	cout << "========================\n";
	cout << "\n";

	TimeClock clock_1;

	cout << "The length of time between the two times is " << fixed << setprecision(2) << clock_1.getHoursElapsed() << " hours.\n";
	cout << "\n"; 

}