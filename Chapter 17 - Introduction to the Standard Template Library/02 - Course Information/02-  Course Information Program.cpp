//2. Course Information
//
//Write a program that creates a map cotaining course numbers and the room numbers of the rooms where the courses meet. 
//The map should have the following key-value pairs:
//
//-----------------------------------------------
//Course Number (Key)		Room Number (Value)
//-----------------------------------------------
//CS101						3004
//CS102						4501
//CS103						6755
//NT110						1244
//CM241						1411
//
//The program should also create a map containing course numbers and the names of the instructors that teach each course.
//The map should have the following key-value pairs:
//
//-----------------------------------------------
//Course Number (Key)		Instructor (Value)
//-----------------------------------------------
//CS101						Haynes
//CS102						Alvarado
//CS103						Rich
//NT110						Burke
//CM241						Lee
//
//The program should also create a map containing course numbersand the names of the instructors that teach each course.
//The map should have the following key - value pairs :
//
//-----------------------------------------------
//Course Number (Key)		Meeting Time (Value)
//-----------------------------------------------
//CS101						8:00 a.m.
//CS102						9:00 a.m.
//CS103						10:00 a.m.
//NT110						11:00 a.m.
//CM241						1:00 p.m.
//
//The program should let the user enter a course number, then it should display the course's room number, instructor and meeting time.
//

#include<map>
#include<iostream>
#include<iomanip>
#include<array>
#include<string>

using std::map;
using std::cin;
using std::cout;
using std::array;
using std::string;
using std::setw;
using std::left;

int main() {

	const int SIZE = 5;

	array<string, SIZE> courses{ "CS101", "CS102", "CS103", "NT110", "CM241" };
	array<int, SIZE> rooms {3004, 4501, 6755, 1244, 1411};
	array<string, SIZE> instructors { "Haynes", "Alvarado", "Rich", "Burke", "Lee" };
	array<string, SIZE> schedule{ "8:00 a.m.", "9:00 a.m.", "10:00 a.m.", "11:00 a.m.", "1:00 p.m." };

	map<string, int> roomNumbersMap;
	map<string, string> instructorsMap;
	map<string, string> scheduleMap;
	string course_input;
	bool search_bool = false;

	cout << "===============================\n";
	cout << "02 - COURSE INFORMATION PROGRAM\n";
	cout << "===============================\n";
	cout << "\n";

	cout << "COURSE NUMBERS\n";
	cout << "--------------\n";
	cout << "\n";

	for (auto s : courses) {
		cout << "\t* " << s << "\n";
	}

	cout << "\n";

	do {

		cout << "Enter your chosen course number: ";
		getline(cin, course_input);

		cout << "\n";

		array<string, SIZE>::iterator it;

		for (it = courses.begin(); it != courses.end(); it++) {

			if (*it == course_input) {
				search_bool = true;
			}

		}

		if (!search_bool) {
			cout << course_input << " is an invalid course number. Try again and enter a valid course number.\n";
			cout << "\n";
		}

	} while (!search_bool);


	for (int i = 0; i < SIZE; i++) {
		roomNumbersMap.emplace(courses[i], rooms[i]);
		instructorsMap.emplace(courses[i], instructors[i]);
		scheduleMap.emplace(courses[i], schedule[i]);
	}
	
	cout << left <<  setw(25) << "Course Number: " << course_input << "\n";
	cout << setw(25) << "Course Room Number: " << roomNumbersMap.at(course_input) << "\n";
	cout << setw(25) << "Course Instructor: " << instructorsMap.at(course_input) << "\n";
	cout << setw(25) << "Meeting Time: " << scheduleMap.at(course_input) << "\n";
	cout << "\n";

	cout << "Ending the program...\n";

}