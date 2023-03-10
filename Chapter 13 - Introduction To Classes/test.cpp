#include <iostream>

using namespace std;

class Yard {

private:
	int length, width;

public:
	Yard()
	{
		length = 0; width = 0;
	}
	void setLength(int len)
	{
		length = len;
	}
	void setWidth(int w)
	{
		width = w;
	}

};

int main() {

	int length;
	int width;

	const int YARD_SIZE = 3;

	Yard allotments[YARD_SIZE];

	for (int i = 0; i < YARD_SIZE; i++) {

		cout << "What is the length of yard #" << i + 1 << ": ";
		cin >> length;

		allotments[i].setLength(length);

		cout << "What is the width of yard #" << i + 1 << ": ";
		cin >> width;

		allotments[i].setWidth(width);

		cout << endl;

	}


}