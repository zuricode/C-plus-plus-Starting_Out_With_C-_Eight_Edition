#include "PassFailActivity.h"

//******************************************************
// Member function PassFailActivity::getLetterGrade    *
// This function returns 'P' if the score is passing,  *
// otherwise it returns 'F'.                           *
//******************************************************

char PassFailActivity::getLetterGrade() const
{
   char letterGrade;
   
   if (score >= minPassingScore)
      letterGrade = 'P';
   else 
      letterGrade = 'F';
      
   return letterGrade;
} 

void PassFailActivity::print(ostream& strm) const {

    strm << "Grade: " << getLetterGrade() << "\n";

}