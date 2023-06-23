#ifndef COURSEGRADES_H
#define COURSEGRADES_H

#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\11 - Course Grades\\Amended Files\\GradedActivity.h"
#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\11 - Course Grades\\Amended Files\\PassFailExam.h"
#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\11 - Course Grades\\Amended Files\\FinalExam.h"
#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\06 - Essay Class\\Essay.h"

const int NUM_OF_ASSIGNMENTS = 4;

class CourseGrades {

private:
	GradedActivity* grades = new GradedActivity[NUM_OF_ASSIGNMENTS];

public:
	CourseGrades() {}
	~CourseGrades() { delete grades; grades = nullptr; }

	void setLab(GradedActivity*);
	void setPassFailExam(PassFailExam*);
	void setEssay(Essay*);
	void setPassFailExam(FinalExam*);

	GradedActivity getLab() const { return grades[0]; }
	GradedActivity getPassFailExam() const { return grades[1]; }
	GradedActivity getEssay() const { return grades[2]; }
	GradedActivity getFinalExam() const { return grades[3]; }

	int getNumOfAssignments() const { return NUM_OF_ASSIGNMENTS; }

};

#endif