#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <iostream>
#include <string>


using std::string;
using std::getline;
using std::cin;
using std::cout;


class ParkedCar {

private:
	string make;
	string model;
	string colour;
	string license_number;
	int minutes_parked;

public:
	ParkedCar();																// Default Constructor
	ParkedCar(const string, const string, const string, const string);		// Constructor with arguments

	ParkedCar(const ParkedCar &);												// Copy constructor

	void setMake(const string S) { make = S; }									// Set make of the car, arguments
	void setMake() { getline(cin, make); }										// Set make of the car, data entry
	string getMake() const { return make; }										// Get make of the car

	void setModel(const string S) { model = S; }								// Set model of the car, arguments
	void setModel() { getline(cin, model); }									// Set model of the car, data entry
	string getModel() const { return model; }									// Get model of the car

	void setColour(const string S) { colour = S; }								// Set colour of the car, arguments
	void setColour() { getline(cin, colour); }									// Set colour of the car, data entry
	string getColour() const { return colour; }									// Get colour of the car

	void setLicenseNumber(const string S) { license_number = S; }				// Set license number of the car, arguments
	void setLicenseNumber() { getline(cin, license_number); }					// Set license number of the car, data entry
	string getLicenseNumber() const { return license_number; }					// Get license number of the car

	void increaseMinutesParked();												// Increase the number of minutes passed and display the length of stay thus far
	int getMinutesParked() const { return minutes_parked; }						// Get the amount of minutes the car has been parked

	const ParkedCar operator = (const ParkedCar&);

};

#endif