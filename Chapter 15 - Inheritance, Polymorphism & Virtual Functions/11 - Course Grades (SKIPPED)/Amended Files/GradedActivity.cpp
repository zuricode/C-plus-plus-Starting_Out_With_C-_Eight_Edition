#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\11 - Course Grades\\Amended Files\\GradedActivity.h"

#include <iomanip>

using std::left;
using std::setw;


//******************************************************
// Member function GradedActivity::getLetterGrade      *
//******************************************************

char GradedActivity::getLetterGrade() const
{
   char letterGrade; // To hold the letter grade
   
   if (score > 89)
      letterGrade = 'A';
   else if (score > 79)
      letterGrade = 'B';
   else if (score > 69)
      letterGrade = 'C';
   else if (score > 59)
      letterGrade = 'D';
   else
      letterGrade = 'F';
   
   return letterGrade;
}

void GradedActivity::print(ostream& strm) const {

}

ostream& operator << (ostream& strm, const GradedActivity& G) {
    
    strm << left;
    G.print(strm);
    strm << "Score: " << G.score << "\n";
    strm << "Grade: " << G.getLetterGrade() << "\n";

    return strm;

}