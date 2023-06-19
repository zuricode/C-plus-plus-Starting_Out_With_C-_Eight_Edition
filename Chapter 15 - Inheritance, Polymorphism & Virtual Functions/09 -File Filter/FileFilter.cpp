#include "FileFilter.h"

using std::getline;

void FileFilter::importData(ifstream& in) {

	string s;

	if (in.tellg() != 0) {
		in.clear();
		in.seekg(0L, ios::beg);
	}

		while (getline(in, s)) {
			original_data += s;
		}

}

void FileFilter::exportDataWriteFile(ofstream& o_file, const string FILE_LOCATION) {

	o_file.open(FILE_LOCATION);

	if (!o_file.fail()) {

		for (int i = 0; i < original_data.length(); i++) {
			o_file << original_data[i];
		}

		o_file.close();
		wipeData();

	}
	else {
		cout << "Error: Data could not be exported because" << FILE_LOCATION << " does not exist.\n";
		cout << "\n";
	}

}

void FileFilter::doFilter(ifstream& in, ofstream& out) {

	importData(in);

	for (int i = 0; i < original_data.length(); i++) {
		filtered_data += transform(original_data[i]);
	}

	cout << *this << "\n";
	out << *this << "\n";

}

ostream& operator << (ostream& strm, const FileFilter& F) {

	F.print(strm);
	return strm;

}