//10. File Double-Spacer
//
//Create a derived class of the abstract filter class of Programming Challenge 9 that
//double - spaces a file : that is, it inserts a blank line between any two lines of the file.

#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\09 -File Filter\\EncryptionFilter.h"
#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\09 -File Filter\\UpperCaseFilter.h"
#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\09 -File Filter\\UnchangedFilter.h"
#include "DoubleSpaceFilter.h"

void openSourceFile(ifstream&);
void openOutputFile(ofstream&);

int main() {

	EncryptionFilter e_filter(53);
	UpperCaseFilter upper_filter;
	UnchangedFilter unchanged_filter;
	DoubleSpaceFilter doublespace_filter;

	ifstream source_file;
	ofstream output_file;
	string source_file_location;
	string output_file_location;

	cout << "===============================\n";
	cout << "10 - FILE DOUBLE-SPACER PROGRAM\n";
	cout << "===============================\n";
	cout << "\n";

	openSourceFile(source_file);
	openOutputFile(output_file);

	e_filter.doFilter(source_file, output_file);
	upper_filter.doFilter(source_file, output_file);
	unchanged_filter.doFilter(source_file, output_file);
	doublespace_filter.doFilter(source_file, output_file);

	cout << "Closing source file...\n";
	source_file.close();

	cout << "Closing destination file...\n";
	output_file.close();

}

void openSourceFile(ifstream& f) {

	string location;

	cout << "Enter the location of your source file: ";
	getline(cin, location);
	f.open(location, ios::in);

	while (!f) {
		cout << "\n";
		cout << "Error: source file location does not exist.\n";
		cout << "\n";
		cout << "Enter the location of your source file: ";
		getline(cin, location);
		f.open(location);
	}

	cout << "\n";
	cout << "SUCCESS: Source file was loaded successfully.\n";
	cout << "\n";

}

void openOutputFile(ofstream& f) {

	string location;

	cout << "Enter the location of your output file: ";
	getline(cin, location);
	cout << "\n";

	f.open(location, ios::out);

}