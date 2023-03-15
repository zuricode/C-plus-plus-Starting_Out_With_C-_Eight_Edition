#include "Car.h"

Car::Car(int y, string m) {

	year = y;
	make = m;
	speed = 0;

}

int Car::getYear() const {
	return year;
}

string Car::getMake() const {
	return make;
}

int Car::getSpeed() const {
	return speed;
}

void Car::accelerate() {
	speed += 5;
}

void Car::brake() {
	speed -= 5;
}