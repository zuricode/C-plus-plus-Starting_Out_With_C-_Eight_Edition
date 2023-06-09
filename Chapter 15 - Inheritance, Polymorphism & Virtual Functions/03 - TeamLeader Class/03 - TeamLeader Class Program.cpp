//3. TeamLeader Class
// 
//In a particular factory, a team leader is an hourly paid production worker who leads
//a small team.In addition to hourly pay, team leaders earn a fixed monthly bonus.
//Team leaders are required to attend a minimum number of hours of training per year.
//Design a TeamLeader class that extends the ProductionWorker class you designed in
//Programming Challenge 1. The TeamLeader class should have member variables for
//the monthly bonus amount, the required number of training hours, and the number of
//training hours that the team leader has attended.Write one or more constructors and
//the appropriate accessor and mutator functions for the class.Demonstrate the class by
//writing a program that uses a TeamLeader object.

#include "TeamLeader.h"
#include "ShiftSupervisor.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void setTeamLeaderDetails(TeamLeader&);
void showMonthlyPay(const TeamLeader& );

const double MONTHLY_BONUS = 500.00;

int main() {

	Employee employee;
	ProductionWorker worker;
	ShiftSupervisor leader_1;
	TeamLeader leader_2("Jordan B. Peterson", 90042, "05/07/2012", 2, 29.49, 120, MONTHLY_BONUS);
	
	cout << "=============================\n";
	cout << "15-03 TEAMLEADER CLASS PROGRAM\n";
	cout << "=============================\n";
	cout << "\n";

	cout << employee << "\n";
	cout << worker << "\n";
	cout << leader_1 << "\n";
	cout << leader_2 << "\n";

}

void setTeamLeaderDetails(TeamLeader& t) {

	string text;
	int num_i;
	double num_d;

	cout << "---------------------\n";
	cout << "Teamleader Data Entry\n";
	cout << "---------------------\n";
	cout << "\n";

	cout << "Name: "; 
	getline(cin, text);
	t.setName(text);

	cout << "Employee number: ";
	cin >> num_i;
	t.setNumber(num_i);
	cin.ignore();

	cout << "Date hired: ";
	getline(cin, text);
	t.setHireDate(text);

	cout << "Shift (1 = Day, 2 = Night): ";
	cin >> num_i;
	t.setShift(num_i);
	cin.ignore();

	cout << "Hourly pay rate: $";
	cin >> num_d;
	t.setHourlyPayRate(num_d);
	cin.ignore();

	cout << "Training hours attended: ";
	cin >> num_i;
	t.setTrainingAttended(num_i);
	cin.ignore();

	cout << "Monthly bonus: ";
	t.setMonthlyBonus(MONTHLY_BONUS);

}

void showMonthlyPay(const TeamLeader& T) {

	cout << left;

	cout << "-----------------------------------------\n";
	cout << "TeamLeader Details - " << T.getName() << "\n";
	cout << "-----------------------------------------\n";
	cout << "\n";
	cout << setw(30) << "Name: " << T.getName() << "\n";
	cout << setw(30) << "Employee number: " << T.getNumber() << "\n";
	cout << setw(30) << "Date hired: " << T.getHireDate() << "\n";
	cout << setw(30) << "Type of shifts: " << T.getShift() << "\n";
	cout << setw(30) << "Hourly pay rate: $" << fixed << setprecision(2) << T.getHourlyPayRate() << "\n";
	cout << setw(30) << "Training hours required: " << setprecision(0) << T.getTrainingRequired() << "\n";
	cout << setw(30) << "Training hours attended: " << T.getTrainingAttended() << "\n";
	cout << setw(30) << "Training hours remaining: " << T.getTrainingRemaining() << "\n";
	cout << setw(30) << "Monthly bonus: $" << setprecision(2) << T.getMonthlyBonus() << "\n";
	cout << "\n";	

}