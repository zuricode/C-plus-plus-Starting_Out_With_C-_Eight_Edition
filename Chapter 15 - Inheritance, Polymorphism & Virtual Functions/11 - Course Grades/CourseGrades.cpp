#include "CourseGrades.h"

void CourseGrades::setLab(GradedAcitivty* g) {
	grades[0] = g;
}

void CourseGrades::setPassFailExam(PassFailExam* p) {
	grades[1] = p;
}

void CourseGrades::setEssay(Essay* e) {
	grades[2] = e;
}

void CourseGrades::setPassFailExam(FinalExam* fe) {
	grades[3] = fe;
}

