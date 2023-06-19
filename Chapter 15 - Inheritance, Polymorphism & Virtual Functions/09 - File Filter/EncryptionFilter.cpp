#include "EncryptionFilter.h"

void EncryptionFilter::print(ostream& strm) const {

	strm << "ENCRYPTED TEXT (Key = " << key << ")" << "\n";
	strm << "-------------------------" << "\n"; 
	strm << getFilteredData() << "\n";

}

char EncryptionFilter::transform(char c) {

	if (c == '\n') {
		return c;
	}
	else {
		return c + key;
	}

}