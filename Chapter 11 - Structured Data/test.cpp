#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string text = "abcdefghdfghjgdsertfguhjgfdsghjgfds";
	string text_2 = "e";

	cout << text.find(text_2, 0) << endl;

}