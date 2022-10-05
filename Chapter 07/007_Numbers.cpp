#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {

	srand(time(NULL));

	ofstream outputFile;
	outputFile.open("C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\Chapter 07\\07_Numbers.txt");

	for (int i = 0; i < 50; i++) {		
		int num;
		num = rand() % 1000 + 1;
		outputFile << num << endl;
	}

	outputFile.close();

}