#ifndef PROCEDURE_H
#define PROCEDURE_H
#include<string>

using std::string;

class Procedure {

private:
	string name;
	string date;
	string practitioner;
	double cost;

public:
	Procedure(string, string, string, double);

	string getName() const;
	string getDate() const;
	string getPractitioner() const;
	double getCost() const;

	void setName(string);
	void setDate(string);
	void setPractitioner(string);
	void setCost(double);

};

#endif