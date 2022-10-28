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
	
	 // Sort the elements of the array of pointers.
	 arrSelectSort(arrPtr, number_of_donations);
	
	 // Display the donations using the array of pointers. This
	 // will display them in sorted order.
	 cout << "The donations, sorted in ascending order are: \n";
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

	  int minIndex;
	  double minElem;
	 
		  for (int startScan = 0; startScan < (size - 1); startScan++) {

		  minIndex = startScan;
		  minElem = *(arr + startScan);

			for (int index = startScan + 1; index < size; index++) {

			  if (*(arr + index) < minElem) {
				  minElem = *(arr + index);
				  minIndex = index;
			  }

			}

		  *(arr + minIndex) = *( arr + startScan);
		  *(arr + startScan) = minElem;

		  }
 }
 	 
 void showArrPtr(double* arr, int size) {
		   
	 for (int count = 0; count < size; count++) {
		 cout << "$" << *(arr + count) << " ";
	 }
		  
		  cout << endl;

 }