#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class PersonData {

	private:
		string lastName;
		string firstName;
		string address;
		string city;
		string state;
		string zip;
		string phone;

	public:
		PersonData();
		PersonData(string, string, string, string, string, string, string);

		void setLastName(const string S) { lastName = S; }
		void setFirstName(const string S) { firstName = S; }
		void setAddress(const string S) { address = S; }
		void setCity(const string S) { city = S; }
		void setState(const string S) { state = S; }
		void setZip(const string S) { zip = S; }
		void setPhone(const string S) { phone = S; }

		string getLastName() const { return lastName; }
		string getFirstName() const { return firstName; }
		string getAddress() const { return address; }
		string getCity() const { return city; }
		string getState() const { return state; }
		string getZip() const { return zip; }
		string getPhone() const { return phone; }

		virtual void print(ostream&) const;
		virtual void enterData(istream&);
		friend ostream& operator << (ostream&, const PersonData&);
		friend istream& operator >> (istream&, PersonData&);

};

#endif