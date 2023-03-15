#ifndef PATIENT_H
#define PATIENT_H
#include<string>

using std::string;

class Patient {

private:

	string first_name, middle_name, last_name;
	string address, city, state, zip;
	string phone_number;
	string emergency_name, emergency_number;

public:

	Patient(string, string, string, string, string, string, string, string, string, string);

	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;
	string getAddress() const;
	string getCity() const;
	string getState() const;
	string getZIP() const;
	string getPhoneNumber() const;
	string getEmergencyName() const;
	string getEmergencyNumber() const;

	void setFirstName(string);
	void setMiddleName(string);
	void setLastName(string);
	void setAddress(string);
	void setCity(string);
	void setState(string);
	void setZIP(string);
	void setPhoneNumber(string);
	void setEmergencyName(string);
	void setEmergencyNumber(string);

};

#endif
