#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;

const int MIN_MIL_HOURS = 0;
const int MAX_MIL_HOURS = 2359;
const int MIN_SECONDS = 0;
const int MAX_SECONDS = 59;

class MilTime : public Time {

private:
	string milHours;
	string milSeconds;

public:
	MilTime() : Time() { milHours = "0000"; milSeconds = "00"; }
	MilTime(int, int);

	string convertHoursToMilHours(int);

	void milHoursValidation(int&);
	void milSecondsValidation(int);

	void setTime(int, int);

	string getHour() const { return milHours; }
	int getStandHr() const { return hour; }

	virtual void print(ostream&) const;

};

#endif