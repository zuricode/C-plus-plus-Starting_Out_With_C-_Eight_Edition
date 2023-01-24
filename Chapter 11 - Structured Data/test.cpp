#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct HourlyPaid {
	double hours_worked;
	double hourly_rate;
};

struct Salaried {
	double salary;
	double bonus;
};

union Worker {
	HourlyPaid hp;
	Salaried sal;
};


int main() {

	Worker s;

}