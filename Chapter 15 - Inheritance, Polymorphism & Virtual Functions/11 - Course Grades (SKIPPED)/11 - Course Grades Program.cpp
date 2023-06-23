//11. Course Grades
//
//In a course, a teacher gives the following testsand assignments:
//
//• A lab activity that is observed by the teacherand assigned a numeric score.
//• A pass / fail exam that has 10 questions.The minimum passing score is 70.
//• An essay that is assigned a numeric score.
//• A final exam that has 50 questions.
//
//Write a class named CourseGrades.The class should have a member named grades
//that is an array of GradedActivity pointers.The grades array should have four elements,
//one for each of the assignments previously described.The class should have the
//following member functions :
//
//setLab:				This function should accept the address of a GradedActivity
//					object as its argument.This object should already hold the student’s
//					score for the lab activity.Element 0 of the grades array
//					should reference this object.
//
//setPassFailExam :	This function should accept the address of a PassFailExam
//					object as its argument.This object should already hold the student’s
//					score for the pass / fail exam.Element 1 of the grades array
//					should reference this object.
//
//setEssay :			This function should accept the address of an Essay object as
//					its argument. (See Programming Challenge 6 for the Essay class.
//					If you have not completed Programming Challenge 6, use a
//					GradedActivity object instead.) This object should already hold
//					the student’s score for the essay.Element 2 of the grades array
//					should reference this object.
//
//setPassFailExam :	This function should accept the address of a FinalExam object as
//					its argument.This object should already hold the student’s score
//					for the final exam. Element 3 of the grades array should reference
//					this object.
//
//print :				This function should display the numeric scores and grades for
//					each element in the grades array.
//
//Demonstrate the class in a program.

#include "CourseGrades.h"

void enterLabAct(CourseGrades&);
void enterPassFailExam(CourseGrades&);
void enterEssay(CourseGrades&);
void enterFinalExam(CourseGrades&);

void showCourseResults(const CourseGrades&);

int main() {

	CourseGrades course;

	cout << "==========================\n";
	cout << "15-11 COURSE GRADE PROGRAM\n";
	cout << "==========================\n";
	cout << "\n";

	enterLabAct(course);
	enterPassFailExam(course);
	enterEssay(course);
	enterFinalExam(course);

	showCourseResults(course);

}

void enterLabAct(CourseGrades& c) {

	int num;

	cout << "Lab Activity\n";
	cout << "------------\n";
	cout << "\n";

	cout << "The teacher set a lab activity. What was the score?\n";
	cout << "Score (0-100): ";
	cin >> num;
	cout << "\n";
	GradedActivity* g = new GradedActivity(num);

	c.setLab(g);

}

void enterPassFailExam(CourseGrades& c) {

	int num;

	cout << "Pass/Fail Exam\n";
	cout << "--------------\n";
	cout << "\n";

	cout << "A pass/fail exam of ten question was set. Minimum passing score is 70.\n";
	cout << "Questions: 10\n";
	cout << "Points per question: 10\n";

	cout << "How many questions were missed: ";
	cin >> num;
	cout << "\n";

	PassFailExam* pfe = new PassFailExam(10, 10, num);

	c.setPassFailExam(pfe);

}

void enterEssay(CourseGrades& c) {

	int num_1;
	int num_2;
	int num_3;
	int num_4;

	cout << "Essay\n";
	cout << "-----\n";
	cout << "An essay was set. Enter the marks for the following criteria: \n";

	cout << "Spelling: ";
	cin >> num_1;

	cout << "Correct Length: ";
	cin >> num_2;

	cout << "Content: ";
	cin >> num_3;

	cout << "Grammar: ";
	cin >> num_4;

	cout << "\n";

	Essay* e = new Essay(num_1, num_2, num_3, num_4);

	c.setEssay(e);

}

void enterFinalExam(CourseGrades& c) {

	int num_1;
	int num_2;

	cout << "Final Exam\n";
	cout << "----------\n";
	cout << "\n";

	cout << "The final exam has 50 questions\n";
	cout << "Questions: 50\n";
	cout << "Points per question: ";
	cin >> num_1;

	cout << "How many questions were missed: ";
	cin >> num_2;
	cout << "\n";

	FinalExam* fe = new FinalExam(50, num_2, num_1);

	fe->adjustScore();

	c.setPassFailExam(fe);

}

void showCourseResults(const CourseGrades& C) {

	cout << "COURSE REPORT\n";
	cout << "-------------\n";

	cout << C.getLab() << "\n";
	cout << C.getPassFailExam() << "\n";
	cout << C.getEssay() << "\n";
	cout << C.getFinalExam() << "\n";

}
