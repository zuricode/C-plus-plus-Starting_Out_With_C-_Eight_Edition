//3. Punch Line
//
//Write a program that reads and prints a joke and its punch line from two different files.
//The first file contains a joke, but not its punch line.The second file has the punch line as
//its last line, preceded by “garbage.” The main function of your program should open the
//two filesand then call two functions, passing each one the file it needs.The first function
//should readand display each line in the file it is passed(the joke file).The second function
//should display only the last line of the file it is passed(the punch line file).It should find
//this line by seeking to the end of the fileand then backing up to the beginning of the last
//line.Data to test your program can be found in the joke.txt and punchline.txt files.

#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

void readAndDisplayJokeFile(ifstream &);
void displayPunchline(ifstream &);

int main() {

	ifstream joke;
	ifstream punchline;
	string joke_location;
	string punchline_location;
	string str;

	cout << "Where is the location of the joke file: ";
	getline(cin, joke_location);

	joke.open(joke_location, ios::in);

	if (!joke) {
		cout << "Could not open the joke file. Quiting the program...";
		exit(EXIT_FAILURE);
	}

	cout << endl;

	cout << "Where is the location of the punchline file: ";
	getline(cin, punchline_location);

	punchline.open(punchline_location, ios::in);

	if (!punchline) {
		cout << "Could not open the joke file. Quiting the program...";
		exit(EXIT_FAILURE);
	}

	cout << endl;

	readAndDisplayJokeFile(joke);
	displayPunchline(punchline);

}

void readAndDisplayJokeFile(ifstream& file) {

	string str;

	cout << "JOKE: " << endl;
	cout << endl;

	while (!file.eof()) {
		getline(file, str);
		cout << str << endl;
	}

}

void displayPunchline(ifstream& file) {

	char ch;
	long byte_pos = 0;

	while (!file.eof()) {
		file.get(ch);

		if (ch == '\n') {
			byte_pos = file.tellg();
		}

	}

	file.clear();

	file.seekg(byte_pos, ios::beg);

	cout << "Punchline: ";

	while (!file.eof()) {
		file.get(ch);
		cout << ch;
	}

	cout << endl;

}


