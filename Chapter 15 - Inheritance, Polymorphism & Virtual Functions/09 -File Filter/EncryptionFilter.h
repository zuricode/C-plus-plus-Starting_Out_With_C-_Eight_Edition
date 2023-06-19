#ifndef ENCRYPTIONFILTER_H
#define ENCRYPTIONFILTER_H

#include "FileFilter.h"

class EncryptionFilter : public FileFilter {

private:
	int key;

public:
	EncryptionFilter() : FileFilter() { key = 10; }
	EncryptionFilter(const int KEY) : FileFilter() { key = KEY; }

	virtual void print(ostream&) const;
	virtual char transform(char);

};

#endif