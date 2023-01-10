#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string text = "abcdefgh";
	string text_2 = "xyz";

	cout << text.find(text_2, 0) << endl;

}