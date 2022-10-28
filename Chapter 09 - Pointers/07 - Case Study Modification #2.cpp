// This program shows the donations made to the United Cause
 // by the employees of CK Graphics, Inc. It displays
 // the donations in order from lowest to highest
 // and in the original order they were received.

 #include <iostream>

 using namespace std;

 // Function prototypes
 int intValidation();
 double doubleValidation();
 double* allocateMemory(int);
 void enterDonations(double*, int);
 void arrSelectSort(double*, int);
 void showArrPtr(double*, int);

 int main() {

	int number_of_donations;
	
	cout << "Please enter the amount of donations received: ";
	number_of_donations = intValidation();

	double* arrPtr = allocateMemory(number_of_donations);

	enterDonations(arrPtr, number_of_donations);		
	
	arrSelectSort(arrPtr, number_of_donations);	

	cout << "The donations, sorted in descending order are: \n";
	showArrPtr(arrPtr, number_of_donations);
	
	delete[] arrPtr;
	arrPtr = nullptr;

	return 0;
 
 }

 int intValidation() {

	 int num;

	 while (!(cin >> num) || num < 0)
		 cout << "ERROR: Value must be an integer greater than 0. Re-enter your value: ";
		 cin.clear();
		 cin.ignore(1200, '\n');

	 return num;

 }

 double doubleValidation() {

	 double num;

	 while (!(cin >> num) || num < 0)
		 cout << "ERROR: Value must be an integer greater than 0. Re-enter your value: ";
	 cin.clear();
	 cin.ignore(1200, '\n');

	 return num;

 }

 double* allocateMemory(int size) {

	 return new double[size];

 }

 void enterDonations(double* ptr, int size) {

	 for (int i = 0; i < size; i++) {
		 cout << "Enter donation #" << i + 1 << ": $";
		 *(ptr + i) = doubleValidation();
	 }

	 cout << endl;

 }

 void arrSelectSort(double* arr, int size) {

	  int maxIndex;
	  double maxElem;
	 
		  for (int startScan = 0; startScan < (size - 1); startScan++) {

		  maxIndex = startScan;
		  maxElem = *(arr + startScan);

			for (int index = startScan + 1; index < size; index++) {

			  if (*(arr + index) > maxElem) {
				  maxElem = *(arr + index);
				  maxIndex = index;
			  }

			}

		  *(arr + maxIndex) = *( arr + startScan);
		  *(arr + startScan) = maxElem;

		  }
 }
 	 
 void showArrPtr(double* arr, int size) {
		   
	 for (int count = 0; count < size; count++) {
		 cout << "$" << *(arr + count) << " ";
	 }
		  
		  cout << endl;

 }