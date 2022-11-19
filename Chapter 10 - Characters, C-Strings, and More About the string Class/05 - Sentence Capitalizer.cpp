#include <iostream>
#include <string>

using namespace std;

void capitalizeText(char*);
void capitalizeText(&string);


int main() {

	const int		SIZE = 101;
	string			text_string;
	char			text[SIZE];


	cout << "Enter your string (no more than " << SIZE << " characters): ";
	cin.getline(text, SIZE);

	cout << "Original: " << text << endl;

	capitalizeText(text);

	cout << "Capitalized: " << text << endl;

	cout << endl << endl;

	cout << "Enter your string (no more than " << SIZE << " characters): ";
	getline(cin, text_string);

	cout << "Original: " << text_string << endl;

	capitalizeText(text_string);

	cout << "Capitalized: " << text_string << endl;

	cout << endl;



}

void capitalizeText(char* ptr) {

	int i = 0;
	
	while (*(ptr + i) != '\0') {

		if (i == 0) {
			*(ptr + i) = toupper(*(ptr + i));
		}
		
		if ((*(ptr + i) == '.' || *(ptr + i) == '!' || *(ptr + i) == '?') && *(ptr + (i + 1)) != '\0') {
			*(ptr + (i + 2)) = toupper(*(ptr + (i + 2)));
		}

		i++;

	}

}

void capitalizeText(&string text) {

	for (int i = 0; i < text.size(); i++) {

				if (i == 0) {
					text[i] = toupper(text[i]);
				}

				if ((text[i] == '.' || text[i] == '!' || text[i] == '?') && text[i + 1] != '\0') {
					text[i + 2] = toupper(text[i + 2]);
				}

	}

}