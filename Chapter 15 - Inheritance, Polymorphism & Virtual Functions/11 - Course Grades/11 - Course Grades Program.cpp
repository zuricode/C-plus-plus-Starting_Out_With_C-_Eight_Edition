11. Course Grades

In a course, a teacher gives the following testsand assignments:

• A lab activity that is observed by the teacherand assigned a numeric score.
• A pass / fail exam that has 10 questions.The minimum passing score is 70.
• An essay that is assigned a numeric score.
• A final exam that has 50 questions.

Write a class named CourseGrades.The class should have a member named grades
that is an array of GradedActivity pointers.The grades array should have four elements,
one for each of the assignments previously described.The class should have the
following member functions :

setLab:				This function should accept the address of a GradedActivity
					object as its argument.This object should already hold the student’s
					score for the lab activity.Element 0 of the grades array
					should reference this object.

setPassFailExam :	This function should accept the address of a PassFailExam
					object as its argument.This object should already hold the student’s
					score for the pass / fail exam.Element 1 of the grades array
					should reference this object.

setEssay :			This function should accept the address of an Essay object as
					its argument. (See Programming Challenge 6 for the Essay class.
					If you have not completed Programming Challenge 6, use a
					GradedActivity object instead.) This object should already hold
					the student’s score for the essay.Element 2 of the grades array
					should reference this object.

setPassFailExam :	This function should accept the address of a FinalExam object as
					its argument.This object should already hold the student’s score
					for the final exam. Element 3 of the grades array should reference
					this object.

print :				This function should display the numeric scores and grades for
					each element in the grades array.

Demonstrate the class in a program.

#include "CourseGrades.h"

int main() {



}