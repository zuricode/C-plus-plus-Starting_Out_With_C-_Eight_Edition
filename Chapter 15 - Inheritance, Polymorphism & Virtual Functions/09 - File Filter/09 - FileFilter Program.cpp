//9. File Filter
//
//A file filter reads an input file, transforms it in some way, and writes the results to an output
//file.Write an abstract file filter class that defines a pure virtual function for transforming
//a character.Create one derived class of your file filter class that performs encryption,
//another that transforms a file to all uppercase, and another that creates an unchanged
//copy of the original file.The class should have the following member function :
//
//void doFilter(ifstream & in, ofstream & out)
//
//This function should be called to perform the actual filtering.The member function for
//transforming a single character should have the prototype :
//
//char transform(char ch)
//
//The encryption class should have a constructor that takes an integer as an argument
//and uses it as the encryption key.

#include "EncryptionFilter.h"
#include "UpperCaseFilter.h"
#include "UnchangedFilter.h"

void openSourceFile(ifstream&);
void openOutputFile(ofstream&);

int main() {

	EncryptionFilter e_filter(253);
	UpperCaseFilter upper_filter;
	UnchangedFilter unchanged_filter;

	ifstream source_file;
	ofstream output_file;
	string source_file_location;
	string output_file_location;

	cout << "=======================\n";
	cout << "09 - FILEFILTER PROGRAM\n";
	cout << "=======================\n";
	cout << "\n";

	openSourceFile(source_file);
	openOutputFile(output_file);

	e_filter.doFilter(source_file, output_file);
	upper_filter.doFilter(source_file, output_file);
	unchanged_filter.doFilter(source_file, output_file);
	cout << "\n";

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