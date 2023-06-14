#include "TimeClock.h"

using std::cout;
using std::cin;

TimeClock::TimeClock() {

	cout << "STARTING TIME\n";
	cout << "-------------\n";
	cin >> starting_time;

	cout << "ENDING TIME\n";
	cout << "-----------\n";
	cin >> ending_time;

	cout << "\n";

}

int convertTimeToSeconds(const MilTime T) {

	int seconds = 0;

	seconds += stoi(T.getHour()) * 60 * 60;
	seconds += stoi(T.getMins()) * 60;
	seconds += stoi(T.getSecs());

	return seconds;

}

TimeClock::TimeClock(const MilTime T1, const MilTime T2) {

	starting_time = T1;
	ending_time = T2;

}

double TimeClock::getHoursElapsed() {

	int seconds_elapsed = 0;

	int t1;
	int t2;

	t1 = convertTimeToSeconds(starting_time);
	t2 = convertTimeToSeconds(ending_time);

	while (t1 != t2) {

		if (t1 + 1 > SECONDS_IN_A_DAY) {
			t1 = 1;
		}
		else {
			t1++;
		}

		seconds_elapsed++;

	}

	return static_cast<double>(seconds_elapsed) / SECONDS_IN_A_HOUR;

}
