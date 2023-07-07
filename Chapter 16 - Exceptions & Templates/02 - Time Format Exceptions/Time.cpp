#include "Time.h"

void Time::print(ostream& strm) const {

	strm << "STANDARD TIME:\n";

	if (hour < 10) {
		strm << "0";
	}
	strm << hour << ":";
	
	if (min < 10) {
		strm << "0";
	} 
	strm << min << ":";
	
	if (sec < 10) {
		strm << "0";
	} 
	strm << sec << " ";

	if (hour >= 12) {
		strm << "PM";
	}
	else {
		strm << "AM";
	}
		
	strm << "\n";

}

void Time::enterData(istream& strm) {

	cout << "Hour: ";
	strm >> hour;

	cout << "Min: ";
	strm >> min;

	cout << "Sec: ";
	strm >> sec;

}

ostream& operator << (ostream& strm, const Time& T) {

	T.print(strm);
	return strm;

}

istream& operator >> (istream& strm, Time& t) {

	t.enterData(strm);
	return strm;

}