#include "MilTime.h"

using std::to_string;
using std::cout;
using std::cin;
using std::stoi;

MilTime::MilTime(int mH, int mS)  {

	milHoursValidation(mH);
	milSecondsValidation(mS);

	hour = mH / 100;
	min = mH % 100;
	sec = mS;

}

void MilTime::milHoursValidation(int& mH) {

		while (mH % 100 > 59) {
			cout << "ERROR: The last two digits of time represent minutes.\n";
			cout << "You cannot not have more than 59 minutes within an hour.\n";
			cout << "\n";
			cout << "Military hours: ";
			cin >> mH;
			cout << "\n";
		}

		while (mH < MIN_MIL_HOURS || mH > MAX_MIL_HOURS) {
			cout << "ERROR: Hours value must be between " << MIN_MIL_HOURS << " and "
				<< MAX_MIL_HOURS << ".\n";
			cout << "\n";
			cout << "Military hours: ";
			cin >> mH;
			cout << "\n";
		}

		milHours = convertHoursToMilHours(mH);

}

void MilTime::milSecondsValidation(int mS) {

	if (mS < MIN_SECONDS || mS > MAX_SECONDS) {
		cout << "ERROR: Seconds value must be between " << MIN_SECONDS << " and "
			<< MAX_SECONDS << ".\n";
		cout << "\n";
		cout << "Seconds: ";
		cin >> mS;
		cout << "\n";
	}

	milSeconds = to_string(mS);

}

string MilTime::convertHoursToMilHours(int time) {

	string units;
	string tens;
	string hundreds;
	string thousands;
	string convertedHours;

	thousands = to_string(time / 1000);
	if (thousands == "0") {
		time %= (1 * 1000);
	}
	else {
		time %= (stoi(thousands) * 1000);
	}

	hundreds = to_string(time / 100); 
	if (hundreds == "0") {
		time %= (1 * 100);
	}
	else {
		time %= (stoi(hundreds) * 100);
	}

	tens = to_string(time / 10);
	if (tens == "0") {
		time %= (1 * 10);
	}
	else {
		time %= (stoi(tens) * 10);
	}

	units = to_string(time);

	convertedHours = thousands + hundreds + tens + units;

	return convertedHours;

}

void MilTime::print(ostream& strm) const {

	strm << "MILITARY TIME:\n";
	strm << milHours[0] << milHours[1] << milHours[2] << milHours[3] << ":" << milSeconds[0] << milSeconds[1] << "Z\n";

}