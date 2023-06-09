#include "TeamLeader.h"

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

TeamLeader::TeamLeader() : ProductionWorker() {
	monthly_bonus = 0;
	training_attended = 0;
}

TeamLeader::TeamLeader(string name, int number, string date, int s,
	double hpr, double mb, double ta) : ProductionWorker(name, number, date, s, hpr) {
	
	setMonthlyBonus(mb);
	setTrainingAttended(ta);

}

void TeamLeader::setMonthlyBonus(double mb) {

	if (mb < 0) {
		cout << "ERROR: Monthly bonus must be greater than or equal to 0.\n";
		cout << "\n";
		cout << "Monthly bonus: ";
		cin >> mb;
	}

	monthly_bonus = mb;

}

void TeamLeader::setTrainingAttended(int ta) {

	if (ta < 0) {
		cout << "ERROR: Hours of training attended must be greater than or equal to 0.\n";
		cout << "\n";
		cout << "Training attended: ";
		cin >> ta;
	}

	training_attended = ta;

}

int TeamLeader::getTrainingRemaining() const {

	int num = MIN_TRAINING_REQUIRED - training_attended;

	if (num < 0) {
		return 0;
	}
	else {
		return num;
	}

}

void TeamLeader::print(ostream& strm) const {

	ProductionWorker::print(strm);

	strm << "Training hours required: " << getTrainingRequired() << "\n";
	strm << "Training hours attended: " << getTrainingAttended() << "\n";
	strm << "Training hours remaning: " << getTrainingRemaining() << "\n";
	strm << "Monthly bonus: $" << fixed << setprecision(2) << getMonthlyBonus() << "\n";

}