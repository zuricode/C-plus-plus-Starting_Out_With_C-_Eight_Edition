#ifndef COURSEGRADES_H
#define COURSEGRADES_H

#include "GradedActivity.h"

const int NUM_OF_ASSIGNMENTS = 4;

class CourseGrades {

private:
	GradedActivity* grades = nullptr;


public:
	CourseGrades() : GradedActivity() {
		grades = new GradedActivity[NUM_OF_ASSIGNMENTS];
	}

	~CourseGrades() {
		delete grades;
		grades = nullptr;
	}

	void setLab(GradedActivity*);
	void setPassFailExam(PassFailExam*);
	void setEssay(Essay*);
	void setPassFailExam(FinalExam*);

};

#endif