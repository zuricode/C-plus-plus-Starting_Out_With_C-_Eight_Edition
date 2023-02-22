#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct XYZ {
	char text[25];
	int num;
};

int main() {

	string location;
	fstream file;
	XYZ random_out;
	XYZ random_in;

	cin.get(random_out.text, 25);
	random_out.num = 567534654;

	location = "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 12 - Advanced File Operations\\ddfgdfgd.txt";

	file.open(location, ios::out | ios::binary);

	if (!file) {
		cout << "Error opening file." << endl;
		exit(EXIT_FAILURE);
	}
	else {
		file.write(reinterpret_cast<char*>(&random_out), sizeof(random_out));
	}

	file.close();

	file.open(location, ios::in | ios::binary);

	if (!file) {
		cout << "Error opening file." << endl;
		exit(EXIT_FAILURE);
	}
	else {
		file.read(reinterpret_cast<char*>(&random_in), sizeof(random_in));
	}

	cout << random_in.text << endl;
	cout << random_in.num << endl;

	file.close();	

}