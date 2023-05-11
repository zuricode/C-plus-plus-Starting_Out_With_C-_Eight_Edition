#ifndef	TIMEOFF_H
#define TIMEOFF_H
#include "NumDays.h"
#include<string>

using std::string;

class TimeOff {

private:

	string name;
	int id_number;
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays vacTaken;
	NumDays maxUnpaid;
	NumDays unpaidTaken;

public:

	TimeOff();
	TimeOff(string, int, int, int, int, int, int, int);

	void setName(string);
	void setIdNumber(int);
	void setMaxSickDays(int hours) { maxSickDays.setHours(hours); }
	void setSickTaken(int hours) { sickTaken.setHours(hours); }
	void setMaxVacation(int hours) { maxVacation.setHours(hours); }
	void setVacTaken(int hours) { vacTaken.setHours(hours); }
	void setMaxUnpaid(int hours) { maxUnpaid.setHours(hours); }
	void setUnpaidTaken(int hours) { unpaidTaken.setHours(hours); }

	double getMaxSickDays() { return maxSickDays.getDays(); }
	double getSickTaken() { return sickTaken.getDays(); }
	double getMaxVacation() { return maxVacation.getDays(); }
	double getVacTaken() { return vacTaken.getDays(); }
	double getMaxUnpaid() { return maxUnpaid.getDays(); }
	double getUnpaidTaken() { return unpaidTaken.getDays(); }

};

#endif