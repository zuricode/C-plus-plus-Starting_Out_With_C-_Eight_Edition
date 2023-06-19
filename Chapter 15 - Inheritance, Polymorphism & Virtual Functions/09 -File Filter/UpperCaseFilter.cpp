#include "UpperCaseFilter.h"

void UpperCaseFilter::print(ostream& strm) const {

	strm << "UPPERCASE FILTER: " << getFilteredData();

}

char UpperCaseFilter::transform(char c) {

	return toupper(c);

}