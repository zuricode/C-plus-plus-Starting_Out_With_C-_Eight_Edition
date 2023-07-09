#ifndef MILTIME_H
#define MILTIME_H

#include "Time.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::to_string;
using std::cout;
using std::cin;
using std::stoi;

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
	MilTime(const string, const string);

	string convertHoursToMilHours(int);

	void milHoursValidation(const string);
	void milSecondsValidation(const string);

	void setTime(int, int);

	string getHour() const { return milHours; }
	int getStandHr() const { return hour; }

	virtual void print(ostream&) const;
	virtual void enterData(istream&);

	class BadHour {
	
	private:
		int bad_hour;

	public:
		BadHour(int bH) { bad_hour = bH; }
		int getBadHour() const { return bad_hour; }

	};

	class BadSeconds {
	
	private:
		int bad_seconds;

	public:
		BadSeconds(int bS) { bad_seconds = bS; }
		int getBadSeconds() const { return bad_seconds; }
	
	};

};

#endif