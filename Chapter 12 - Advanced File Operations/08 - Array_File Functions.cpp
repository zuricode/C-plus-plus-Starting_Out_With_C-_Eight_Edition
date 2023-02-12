//8. Array / File Functions
//
//Write a function named arrayToFile.The function should accept three arguments :
//the name of a file, a pointer to an int array, and the size of the array.The function
//should open the specified file in binary mode, write the contents of the array to the file,
//and then close the file.
//
//Write another function named fileToArray.This function should accept three arguments :
//the name of a file, a pointer to an int array, and the size of the array.The
//function should open the specified file in binary mode, read its contents into the array,
//and then close the file.
//
//Write a complete program that demonstrates these functions by using the arrayToFile
//function to write an array to a file, and then using the fileToArray function to read
//the data from the same file.After the data are read from the file into the array, display
//the array’s contents on the screen.

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void generateRandomNumbers(int* list, const int);
void showArrayContents(int *, const int);

int main() {

	srand(time(NULL));

	const int SIZE = 15;
	const string OUTPUT_LOCATION = "C:\\Users\\Admin\\Desktop\\output_loglog.txt";

	fstream file;
	
	int list_input[SIZE];
	int list_output[SIZE];

	generateRandomNumbers(list_input, SIZE);

	showArrayContents(list_input, SIZE);

	cout << "Exporting array to " << OUTPUT_LOCATION << " in binary mode..." << endl;
	cout << endl;

	file.open(OUTPUT_LOCATION, ios::out | ios::binary);

	if (file) {
		file.write(reinterpret_cast<char*>(list_input), sizeof(list_input));
	}
	else {
		cout << "Error opening file. Re-run the program and try again." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}

	file.close();

	cout << "Importing array from " << OUTPUT_LOCATION << " in binary mode to the memory..." << endl;
	cout << endl;

	file.open(OUTPUT_LOCATION, ios::in | ios::binary);

	if (file) {
		file.read(reinterpret_cast<char*>(list_output), sizeof(list_output));
	}
	else {
		cout << "Error opening file. Re-run the program and try again." << endl;
		cout << "Aborting the program..." << endl;
		exit(EXIT_FAILURE);
	}

	file.close();

	showArrayContents(list_output, SIZE);

}

void generateRandomNumbers(int* list, const int SIZE) {

	for (int i = 0; i < SIZE; i++) {
		*(list + i) = rand() % 100 + 1;
	}

}

void showArrayContents(int* list, const int SIZE) {

	cout << "Array contents: " << endl;
	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << i + 1 << ". " << *(list + i) << endl;
	}

	cout << endl;

}