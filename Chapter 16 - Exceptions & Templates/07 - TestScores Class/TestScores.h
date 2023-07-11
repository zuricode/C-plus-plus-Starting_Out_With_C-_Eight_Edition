#ifndef TESTSCORES_H
#define TESTSCORES_H

const int MIN_SCORE = 0;
const int MAX_SCORE = 100;

class TestScores {

private:
	int *scores;
	int arraysize;
	
public:
	TestScores(const int, const int*);					//Copy Constructor
	~TestScores();										//Destructor
		
	int getArraySize() const { return arraysize; }		//Return array size.
	double getAverage() const;							//Get average from all test scores.
		
		class BadSubscript {

		private:
			int badSubscript;
			int badScore;

		public:
			BadSubscript(const int bSub, const int bSco) { badSubscript = bSub;  badScore = bSco; }

			int getBadSubscript() const { return badSubscript; }
			int getBadScore() const { return badScore; }

		};

		int& operator[](const int&);

};

#endif