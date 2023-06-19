#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <fstream>
#include <string>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::ostream;
using std::string;
using std::cout;
using std::cin;
using std::ios;

class FileFilter {

private:
	string original_data;
	string filtered_data;

public:	
	FileFilter() { original_data = ""; filtered_data = ""; }

	void importData(ifstream&);
	void exportDataWriteFile(ofstream&, const string);

	virtual char transform(char) = 0;

	virtual void doFilter(ifstream& in, ofstream& out);

	string getOriginalData() const { return original_data; }
	string getFilteredData() const { return filtered_data; }

	void setFilteredData(const char C) { filtered_data += C; }

	virtual void print(ostream&) const = 0;

	friend ostream& operator << (ostream&, const FileFilter&);

	void wipeData() { original_data = ""; filtered_data = ""; }

};

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       