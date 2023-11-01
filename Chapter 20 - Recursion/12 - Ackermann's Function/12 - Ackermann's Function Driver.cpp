//12. Ackermann's Function
//
//Ackermann's Function is a recursive mathemical algorithm that can be used to test how well a 
//computer performs recursion. Write a function A(m, n) that solves Acerkamnn's Function. Use the 
//following logic in your function:
//
//If m = 0 then return n+1
//If n = 0 then reutrn A(m-1, 1)
//Otherwise, return A(m-1, A(m, n-1))
//
//Test your function in a driver program that displays the following values:
//A(0,0) A(0, 1) A(1, 1) A(1, 2) A(1, 3) A(2, 2) A(3, 2)

#include <iostream>

using std::cout;

int A(int, int);

int main() {

	cout << "=================================\n";
	cout << "20-12 ACKERMANN'S FUNCTION DRIVER\n";
	cout << "=================================\n";
	cout << "\n";

	cout << A(0, 0) << "\n";
	cout << A(0, 1) << "\n";
	cout << A(1, 1) << "\n";
	cout << A(1, 2) << "\n";
	cout << A(1, 3) << "\n";
	cout << A(2, 2) << "\n";
	cout << A(3, 2) << "\n";

	cout << "\n";
	cout << "Ending the program...\n";

}

int A(int m, int n) {

	if (m == 0) {
		return n + 1;
	}

	if (n == 0) {
		return A(m - 1, 1);
	}

	else {
		return A(m - 1, A(m, n - 1));
	}

}