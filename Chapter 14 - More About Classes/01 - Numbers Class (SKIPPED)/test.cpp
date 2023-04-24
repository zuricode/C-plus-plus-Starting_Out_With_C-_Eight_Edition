#include <iostream>

using namespace std;

class Rectangle {

private:
	int length;
	int width;

public:
	Rectangle() { length = 0; width = 0; }
	Rectangle(int l, int w) { length = l; width = w; }

	const Rectangle operator = (const Rectangle& r) {
		length = r.length;
		width = r.width;
		return *this;
	}

	Rectangle operator + (const Rectangle r) {
		Rectangle temp;

		temp.length = length + r.length;
		temp.width = width + r.width;
		return temp;
	}

	friend ostream &operator << (ostream &strm, const Rectangle &r) {
		strm << "This rectangle is " << r.length << " cm long and " << r.width << " cm wide.";
		return strm;
	}


	Rectangle operator ++ () {
		++length;
		++width;
		return *this;
	}

	Rectangle operator ++ (int) {
		Rectangle temp;
		temp.length = length;
		temp.width = width;
		++length;
		++width;
		return temp;
	}

};

int main() {

	int x = 1;

	Rectangle small(5, 6);
	Rectangle large(20, 10);
	Rectangle x_large;

	cout << small << "\n";
	cout << large << "\n";
	cout << endl;

	small = large;

	cout << small << "\n";
	cout << large << "\n";
	cout << endl;

	x_large = small + large;

	cout << x_large << "\n";
	cout << "\n";

	small = large = x_large;

	cout << small << "\n";
	cout << large << "\n";
	cout << x_large << "\n";
	cout << "\n";

	cout << ++x_large << "\n";
	cout << "\n";

	cout << x_large++ << "\n";
	cout << x_large << "\n";


}