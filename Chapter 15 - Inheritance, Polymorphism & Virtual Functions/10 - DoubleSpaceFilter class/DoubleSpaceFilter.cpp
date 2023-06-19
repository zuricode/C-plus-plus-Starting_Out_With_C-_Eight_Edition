#include "DoubleSpaceFilter.h"

void DoubleSpaceFilter::doFilter(ifstream& in, ofstream& out) {

	int counter = 0;

	importData(in);

	for (int i = 0; i < getOriginalData().length(); i++) {

		if (getOriginalData()[i] == '\n') {
			counter++;
			if (counter == 2) {
				counter = 0;
				setFilteredData('\n');
			}
		}

	setFilteredData(transform(getOriginalData()[i]));

	}

	cout << *this;
	out << *this;

}

void DoubleSpaceFilter::print(ostream& strm) const {

	strm << "DOUBLE SPACE FILTER " << "\n";
	strm << "--------------------" << "\n";
	strm << getFilteredData() << "\n";

}

char DoubleSpaceFilter::transform(char c) {

	return c;

}