//6. Essay class
//
//Design an Essay class that is derived from the GradedActivity class presented in this
//chapter.The Essay class should determine the grade a student receives on an essay.
//
//The student’s essay score can be up to 100, and is determined in the following manner :
//
//• Grammar : 30 points
//• Spelling : 20 points
//• Correct length : 20 points
//• Content : 30 points
//
//Demonstrate the class in a simple program.

#include "Essay.h"

int main() {

	cout << "==============================\n";
	cout << "15-06 ESSAY CLASS DEMO PROGRAM\n";
	cout << "==============================\n";
	cout << "\n";


	Essay swahili_essay(22, 25, 27 ,29);

	cout << swahili_essay;

}