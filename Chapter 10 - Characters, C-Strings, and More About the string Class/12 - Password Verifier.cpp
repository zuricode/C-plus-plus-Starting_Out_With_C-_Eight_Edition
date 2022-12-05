//12. Password Verifier
//Imagine you are developing a software package that requires users to enter their own
//passwords.Your software requires that users’ passwords meet the following criteria :
//• The password should be at least six characters long.
//• The password should contain at least one uppercase and at least one lowercase letter.
//• The password should have at least one digit.
//Write a program that asks for a passwordand then verifies that it meets the stated
//criteria.If it doesn’t, the program should display a message telling the user why.

#include <iostream>

const int	MIN_LENGTH = 6, SPACE = 51;

using namespace std;

void password();

int main() {

	password();

}

void password() {

	char input[SPACE];

	int upper_count = 0, lower_count = 0, digit_count = 0, i = 0;

	cout << "Enter a password " << MIN_LENGTH << " characters long and has at least one lowercase character, one uppercase character and one digit." << endl;
	cout << "Password: ";

	cin.getline(input, SPACE);

	if (strlen(input) < MIN_LENGTH) {
		cout << "Password length is " << strlen(input) << " characters long. Please enter at least " << MIN_LENGTH << " long." << endl;
		exit(EXIT_FAILURE);
	}

	while (*(input + i) != '\0') {

		if (isupper(*(input + i))) {
			upper_count++;
		}

		else if (islower(*(input + i))) {
			lower_count++;
		}

		else if (isdigit(*(input + i))) {
			digit_count++;
		}

		i++;

	}

	if (upper_count > 0 && lower_count > 0 && digit_count > 0) {
		cout << "You have entered you password successfully." << endl;
		exit(EXIT_SUCCESS);
	}
	else {
		cout << "You have not entered your password correctly. Please re-run the program remember to include at least one lowercase character, one uppercase character and one digit." << endl;
		exit(EXIT_FAILURE);
	}

}