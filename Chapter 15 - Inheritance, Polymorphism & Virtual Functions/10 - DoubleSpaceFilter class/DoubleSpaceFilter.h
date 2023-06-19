#ifndef DOUBLESPACEFILTER_H
#define DOUBLESPACEFILTER_H

#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\09 -File Filter\\FileFilter.h"

class DoubleSpaceFilter : public FileFilter {

public:
	DoubleSpaceFilter() : FileFilter() {}

	virtual void doFilter(ifstream&, ofstream&);

	virtual void print(ostream&) const;
	virtual char transform(char);

};

#endif