#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H
#include "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 15 - Inheritance, Polymorphism & Virtual Functions\\11 - Course Grades\\Amended Files\\GradedActivity.h"

class PassFailActivity : public GradedActivity
{
protected:
   double minPassingScore;    // Minimum passing score.
public:
   // Default constructor
   PassFailActivity() : GradedActivity()
      { minPassingScore = 0.0; }
   
   // Constructor
   PassFailActivity(double mps) : GradedActivity()
      { minPassingScore = mps; }

   // Mutator
   void setMinPassingScore(double mps)
      { minPassingScore = mps; }

   // Accessors
   double getMinPassingScore() const
      { return minPassingScore; }
   
   virtual char getLetterGrade() const;

   virtual void print(ostream&) const;
};
#endif