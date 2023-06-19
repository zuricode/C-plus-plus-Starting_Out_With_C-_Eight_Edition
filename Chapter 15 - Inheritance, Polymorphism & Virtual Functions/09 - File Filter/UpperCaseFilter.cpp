#include "UpperCaseFilter.h"

void UpperCaseFilter::print(ostream& strm) const {

	strm << "UPPERCASE FILTER" << "\n";
	strm << "----------------" << "\n";
	strm << getFilteredData() << "\n";

}

char UpperCaseFilter::transform(char c) {

	return toupper(c);

}