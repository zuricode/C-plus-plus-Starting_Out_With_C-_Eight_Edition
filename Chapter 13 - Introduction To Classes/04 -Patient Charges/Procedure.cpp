#include "Procedure.h"

Procedure::Procedure(string mName, string mDate, string mPractitioner, double mCost) {

	name = mName;
	date = mDate;
	practitioner = mPractitioner;
	cost = mCost;

}

string Procedure::getName() const {
	return name;
}

void Procedure::setName(string mName) {
	name = mName;
}

string Procedure::getDate() const {
	return date;
}

void Procedure::setDate(string mDate) {
	date = mDate;
}

string Procedure::getPractitioner() const {
	return practitioner;
}

void Procedure::setPractitioner(string mPractitioner) {
	practitioner = mPractitioner;
}

double Procedure::getCost() const {
	return cost;
}

void Procedure::setCost(double mCost) {
	cost = mCost;
}