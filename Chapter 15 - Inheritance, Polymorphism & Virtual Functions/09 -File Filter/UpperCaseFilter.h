#ifndef UPPERCASEFILTER_H
#define UPPERCASEFILTER_H

#include "FileFilter.h"

class UpperCaseFilter : public FileFilter {

private:
	string uppercase_data;

public:
	UpperCaseFilter() : FileFilter() { uppercase_data = ""; }

	virtual void print(ostream&) const;
	virtual char transform(char);

};

#endif