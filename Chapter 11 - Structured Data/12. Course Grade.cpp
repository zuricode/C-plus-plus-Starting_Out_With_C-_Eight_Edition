//12. Course Grade
//
//Write a program that uses a structure to store the following data :
//
//Member Name		Description
//Name			Student name
//Idnum			Student ID number
//Tests			Pointer to an array of test scores
//Average			Average test score
//Grade			Course grade
//
//The program should keep a list of test scores for a group of students.It should ask the
//user how many test scores there are to beand how many students there are.It should
//then dynamically allocate an array of structures.Each structure’s Tests member
//should point to a dynamically allocated array that will hold the test scores.
//
//After the arrays have been dynamically allocated, the program should ask for the ID
//numberand all the test scores for each student.The average test score should be calculated
//and stored in the average member of each structure.The course grade should
//be computed on the basis of the following grading scale :
//
//Average Test Grade		Course Grade
//91–100					A
//81–90						B
//71–80						C
//61–70						D
//60 or below				F
//
//The course grade should then be stored in the Grade member of each structure.Once
//all this data is calculated, a table should be displayed on the screen listing each student’s
//name, ID number, average test score, and course grade.
//
//Input Validation : Be sure all the data for each student is entered.Do not accept negative
//numbers for any test score.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Member {

	string name;
	int idnum{};
	double* tests = nullptr;
	double average{};
	char grade{};

};
 
double inputDouble(string);
double inputScore(string);
int inputInt(string);
string inputString(string);

Member* initStudents(int&);
void initTests(Member*, const int, int&);
void deletePointers(Member*, const int);
double averageTestScore(double[], int);
char getGrade(double);

void enterStudentData(Member*, const int, const int);
void displayStudentData(Member*, const int);

//void initArrays();

int main() {

	Member* students = nullptr;
	int no_of_tests, no_of_students;

	cout << endl;
	cout << "\t=========================" << endl;
	cout << "\t       COURSE GRADE      " << endl;
	cout << "\t=========================" << endl;
	cout << endl;


	students = initStudents(no_of_students);
	initTests(students, no_of_students, no_of_tests);

	cout << endl;

	enterStudentData(students, no_of_students, no_of_tests);

	cout << endl;

	displayStudentData(students, no_of_students);

	deletePointers(students, no_of_students);

}

double inputDouble(string request) {

	double num;

	cout << "\t" << request;

	while (!(cin >> num) || num < 0) {
		cout << "\tERROR: Value must be a double greater than 0. " << endl;
		cout << endl;
		cout << "\t" << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

double inputScore(string request, int max) {

	double num;

	cout << "\t" << request;

	while (!(cin >> num) || num < 0 || num > max) {
		cout << "\tERROR: Value must be a double greater than 0 and less than " << max << ". " << endl;
		cout << endl;
		cout << "\t" << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

int inputInt(string request) {

	int num;

	cout << "\t" << request;

	while (!(cin >> num) || num < 0) {
		cout << "\tERROR: Value must be a integer greater than 0. " << endl;
		cout << endl;
		cout << "\t" << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

string inputString(string request) {

	string text;
	bool isData = false;

	while (!isData) {

		cout << "\t" << request;
		getline(cin, text);

		if (text == "") {
			cout << "\tERROR: No data was entered. " << endl;
			cout << endl;
		}
		else {
			isData = true;
		}

	}

	return text;

}

Member* initStudents(int& no_of_students) {

	no_of_students = inputInt("How many students are taking the tests? ");

	return new Member[no_of_students];

}

void initTests(Member* students, const int no_of_students, int& no_of_tests) {

	no_of_tests = inputInt("How many tests were done? ");

	for (int i = 0; i < no_of_students; i++) {

		students[i].tests = new double[no_of_tests];
		
	}

}

void deletePointers(Member* students, const int no_of_students) {

	for (int i = 0; i < no_of_students; i++) {

		students[i].tests = nullptr;
		delete students[i].tests;

	}

	students = nullptr;
	delete students;

}

void enterStudentData(Member* students, const int no_of_students, const int no_of_tests) {

	for(int i = 0; i < no_of_students; i++) {

		students[i].name = inputString("Enter student #" + to_string(i + 1) + "'s name: ");
		students[i].idnum = inputInt("Enter student #" + to_string(i + 1) + "'s ID number: ");

		cout << endl;

		for (int j = 0; j < no_of_tests; j++) {

			students[i].tests[j] = inputScore("Enter " + students[i].name + "'s test #" + to_string(j + 1) + " score: ", 100);

		}

		students[i].average = averageTestScore(students[i].tests, no_of_tests);
		
		students[i].grade = getGrade(students[i].average);

		cout << endl;

	}

}

void displayStudentData(Member* students, const int no_of_students) {

	cout << "\tEXAMINATION RESULTS" << endl;
	cout << endl;
	cout << "\t" << left << setw(15) << "STUDENT NAME" << right << setfill(' ') << setw(15) << "ID NUMBER" << setw(25) << "AVERAGE TEST SCORE" << setw(25) << "COURSE GRADE" << endl;
	cout << "\t-----------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < no_of_students; i++) {

		cout << "\t" << left << setw(15) << students[i].name << right << setfill(' ') << setw(15) << students[i].idnum << setw(25) << students[i].average << setw(25) << students[i].grade << endl;

	}

	cout << "\t-----------------------------------------------------------------------------------" << endl;

	cout << endl;

}

double averageTestScore(double tests[],int no_of_tests) {

	double average = 0;

	for (int i = 0; i < no_of_tests; i++) {

		average += tests[i];

	}

	average /= no_of_tests;

	return average;

}

char getGrade(double average) {

	char grade;

	int int_average = static_cast<int>(average);

		if (int_average >= 91 && int_average <= 100) {
			grade = 'A';
		}
		else if (int_average >= 81 && int_average <= 90) {
			grade = 'B';
		}
		else if (int_average >= 71 && int_average <= 80) {
			grade = 'C';
		}
		else if (int_average >= 61 && int_average <= 70) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}

	return grade;

}