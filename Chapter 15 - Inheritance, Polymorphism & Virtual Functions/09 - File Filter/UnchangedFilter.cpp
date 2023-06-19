#include "UnchangedFilter.h"

void UnchangedFilter::print(ostream& strm) const {

	strm << "UNCHANGED DATA " << "\n";
	strm << "--------------" << "\n";
	strm << getFilteredData() << "\n";

}

char UnchangedFilter::transform(char c) {

	return c;

}