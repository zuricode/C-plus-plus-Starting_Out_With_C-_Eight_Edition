#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData {

	private:
		int customerNumber;
		bool mailingList;

	public:
		CustomerData() : PersonData() {	customerNumber = 0; mailingList = false; }
		CustomerData(string, string, string, string, string, string, string, int, bool);

		void setCustomerNumber(const int I) { customerNumber = I; }
		void setMailingList(const bool B) { mailingList = B; }

		int getCustomerNumber() const { return customerNumber; }
		bool getMailingList() const { return mailingList; }

		virtual void print(ostream&) const;
		virtual void enterData(istream&);

};

#endif