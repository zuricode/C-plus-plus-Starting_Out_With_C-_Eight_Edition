#include "EncryptionFilter.h"

void EncryptionFilter::print(ostream& strm) const {

	strm << "ENCRYPTED TEXT (Key = " << key << "): " << getFilteredData();

}

char EncryptionFilter::transform(char c) {

	return c + key;

}