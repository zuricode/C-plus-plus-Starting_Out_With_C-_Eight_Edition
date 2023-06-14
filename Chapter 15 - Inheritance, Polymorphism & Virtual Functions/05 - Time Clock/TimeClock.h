#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include "MilTime.h"

const int SECONDS_IN_A_DAY = 60 * 60 * 24;
const int SECONDS_IN_A_HOUR = 60 * 60;

class TimeClock {

	private:
		MilTime starting_time;
		MilTime ending_time;

	public:
		TimeClock();
		TimeClock(const MilTime, const MilTime);

		double getHoursElapsed();


}; 

#endif