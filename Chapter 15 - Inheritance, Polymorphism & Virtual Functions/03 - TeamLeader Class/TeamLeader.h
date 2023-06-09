#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker {
	
private:
	double monthly_bonus;
	const int MIN_TRAINING_REQUIRED = 80;
	int training_attended;

public:
	TeamLeader();
	TeamLeader(string, int, string, int, double, double, double);

	void setMonthlyBonus(double);
	void setTrainingAttended(int);

	double getMonthlyBonus() const { return monthly_bonus; }
	int getTrainingRequired() const { return MIN_TRAINING_REQUIRED; }
	double getTrainingAttended() const { return training_attended; }
	int getTrainingRemaining() const;

	virtual void print(ostream& strm) const;

};

#endif