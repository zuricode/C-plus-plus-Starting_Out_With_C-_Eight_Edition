#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

#include <iostream>

using std::istream;
using std::ostream;

// GradedActivity class declaration

class GradedActivity
{
protected:
   double score;   // To hold the numeric score
public:
   // Default constructor
   GradedActivity()
      { score = 0.0; }

   // Constructor
   GradedActivity(double s)
      { score = s; }

   // Mutator function
   void setScore(double s) 
      { score = s; }
   
   // Accessor functions
   double getScore() const
      { return score; }
   
   virtual char getLetterGrade() const;

   virtual void print(ostream&) const;

   friend ostream& operator << (ostream&, const GradedActivity&);

};
#endif 