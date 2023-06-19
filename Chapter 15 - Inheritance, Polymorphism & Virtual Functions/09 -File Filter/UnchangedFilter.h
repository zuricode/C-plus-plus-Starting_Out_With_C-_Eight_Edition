#ifndef UNCHANGEDFILTER_H
#define UNCHANGEDFILTER_H

#include "FileFilter.h"

class UnchangedFilter : public FileFilter {

public:
	UnchangedFilter() : FileFilter() {}

	virtual void print(ostream&) const;
	virtual char transform(char);

};

#endif