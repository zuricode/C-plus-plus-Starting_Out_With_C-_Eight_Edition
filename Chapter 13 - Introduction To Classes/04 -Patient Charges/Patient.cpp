#include "Patient.h"

Patient::Patient(string mFname, string mMname, string mLname,
	string mAddress, string mCity, string mState,
	string mZip, string mPhone_number, string mEmergency_name,
	string mEmergency_number) {

	first_name = mFname;
	middle_name = mMname;
	last_name = mLname;
	address = mAddress;
	city = mCity;
	state = mState;
	zip = mZip;
	phone_number = mPhone_number;
	emergency_name = mEmergency_name;
	emergency_number = mEmergency_number;

}

string Patient::getFirstName() const {
	return first_name;
}

void Patient::setFirstName(string mFname) {
	first_name = mFname;
}

string Patient::getMiddleName() const {
	return middle_name;
}

void Patient::setMiddleName(string mMname) {
	middle_name = mMname;
}

string Patient::getLastName() const {
	return last_name;
}

void Patient::setLastName(string mLname) {
	last_name = mLname;
}

string Patient::getAddress() const {
	return address;
}

void Patient::setAddress(string mAddress) {
	address = mAddress;
}

string Patient::getCity() const {
	return city;
}

void Patient::setCity(string mCity) {
	city = mCity;
}

string Patient::getState() const {
	return state;
}

void Patient::setState(string mState) {
	state = mState;
}

string Patient::getZIP() const {
	return zip;
}

void Patient::setZIP(string mZip) {
	zip = mZip;
}

string Patient::getPhoneNumber() const {
	return phone_number;
}

void Patient::setPhoneNumber(string mPhone_number) {
	phone_number = mPhone_number;
}

string Patient::getEmergencyName() const {
	return emergency_name;
}

void Patient::setEmergencyName(string mEmergency_name) {
	emergency_name = mEmergency_name;
}

string Patient::getEmergencyNumber() const {
	return emergency_number;
}

void Patient::setEmergencyNumber(string mEmergency_number) {
	emergency_number = mEmergency_number;
}
