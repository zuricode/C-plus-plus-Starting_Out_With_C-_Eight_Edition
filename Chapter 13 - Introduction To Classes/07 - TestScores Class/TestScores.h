#ifndef TESTSCORES_H
#define TESTSCORES_H

class TestScores {

private:

	int first_score;
	int second_score;
	int third_score;

public:

	TestScores();

	void setFirstScore();
	void setSecondScore();
	void setThirdScore();

	int getFirstScore() const;
	int getSecondScore() const;
	int getThirdScore() const;

	double getAverageScore() const;

};

#endif