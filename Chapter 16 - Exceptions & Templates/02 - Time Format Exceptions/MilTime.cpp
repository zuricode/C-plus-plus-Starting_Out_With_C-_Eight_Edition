#include "MilTime.h"

MilTime::MilTime(const string mH, const string mS)  {

	milHours = mH;
	milSeconds = mS;

	milHoursValidation(mH);
	milSecondsValidation(mS);

	hour = stoi(milHours) / 100;
	min = stoi(milHours) % 100;
	sec = stoi(milSeconds);

}

void MilTime::milHoursValidation(const string mH) {

	int mH_int = stoi(mH);

		while (mH_int % 100 > 59) {
		
			throw BadHour();
			
			/*	milHours = to_string(mH_int);
			cout << *this << "\n";
			cout << "ERROR: The last two digits of time represent minutes.\n";
			cout << "You cannot not have more than 59 minutes within an hour.\n";
			cout << "\n";
			cout << "Military hours: ";
			cin >> mH_int;
			cout << "\n";*/

		}

		while (mH_int < MIN_MIL_HOURS || mH_int > MAX_MIL_HOURS) {
			
			throw BadHour();
			
			/*cout << "ERROR: Hours value must be between " << MIN_MIL_HOURS << " and "
				<< MAX_MIL_HOURS << ".\n";
			cout << "\n";
			cout << "Military hours: ";
			cin >> mH_int;
			cout << "\n";*/

		}

		milHours = convertHoursToMilHours(mH_int);

}

void MilTime::milSecondsValidation(const string mS) {

	int mS_int = stoi(mS);

	if (mS_int < MIN_SECONDS || mS_int > MAX_SECONDS) {

		throw BadSeconds();

		/*cout << "ERROR: Seconds value must be between " << MIN_SECONDS << " and "
			<< MAX_SECONDS << ".\n";
		cout << "\n";
		cout << "Seconds: ";
		cin >> mS_int;
		cout << "\n";*/

	}

	milSeconds = to_string(mS_int);

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
	strm << milHours[0] << milHours[1] << milHours[2] << milHours[3] << ":" << milSeconds[0] << milSeconds[1] << "Z";

}

void MilTime::enterData(istream& strm) {

	string mH;
	string mS;

	cout << "Military Time Data Entry\n";
	cout << "------------------------\n";
	cout << "\n";

	cout << "Military Hours: ";
	strm >> mH;
	milHoursValidation(mH);

	cout << "Seconds: ";
	strm >> mS;
	milSecondsValidation(mS);
	
	hour = stoi(milHours) / 100;
	min = stoi(milHours) % 100;
	sec = stoi(milSeconds);

}