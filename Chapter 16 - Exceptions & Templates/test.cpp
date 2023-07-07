#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;

char* allocMem(const int);

int main() {

	char* ptr = nullptr;
	int size = 17;

	try {
		ptr = allocMem(size);
		cout << "Memory for " << size << " char characters has been successfully allocated.\n";
		cout << "The memory address for the pointer is " << &ptr << "\n";
	}
	catch (string exc) {
		ptr = nullptr;
		cout << "There is no memory available to for " << size << "char characters.\n";
		cout << "The address of the pointer has been set to " << &ptr << "\n";
	}

	delete[] ptr;
	ptr = nullptr;

}

char* allocMem(const int SIZE) {

	char* mem = nullptr;

	mem = new char[SIZE];

	return mem;

}