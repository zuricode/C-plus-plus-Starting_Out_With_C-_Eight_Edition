#include "UnchangedFilter.h"

void UnchangedFilter::print(ostream& strm) const {

	strm << "UNCHANGED DATA: " << getFilteredData();

}

char UnchangedFilter::transform(char c) {

	return c;

}