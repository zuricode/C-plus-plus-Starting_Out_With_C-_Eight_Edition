#ifndef CAR_H
#define CAR_H

#include<string>

using namespace std;

class Car {

private:

	int year;
	string make;
	int speed;

public:
	Car(int, string);
	int getYear() const;
	string getMake() const;
	int getSpeed() const;
	void accelerate();
	void brake();

};

#endif