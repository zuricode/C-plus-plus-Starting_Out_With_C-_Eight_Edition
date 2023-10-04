//9. File Reverser
//
//Write a program that opens a text file and reads its contents into a stack of characters.
//The program should then pop the characters from the stack and save them in a second text file.
//The order of the chracters saved in the second file should be the reverse of their order in the
//first file.

#include "TextStack.h"
#include <fstream>

using std::istream;
using std::ostream;

void importTextFromFile(TextStack&);
void exportStackToFile(const TextStack);

int main() {

	cout << "=========================\n";
	cout << "19-09 FILE REVERSE DRIVER\n";
	cout << "=========================\n";
	cout << "\n";

	TextStack stack;

	stack.push('Z');
	stack.push('u');
	stack.push('r');
	stack.push('i');



}

