#include<fstream>
#include<iostream>


using namespace std;

int main() {

	fstream dataFile("info.dat", ios::out | ios::binary);

	struct Date
	{
		int month;
		int day;
		int year;
	};

	Date dt = { 4, 2, 98 };
	dataFile.write(reinterpret_cast<char *>(&dt), sizeof(dt));

}