//1. Numbers Class
//
//Design a class Numbers that can be used to translate whole dollar amounts in the range
//0 through 9999 into an English description of the number.For example, the number
//713 would be translated into the string seven hundred thirteen, and 8203 would be
//translated into eight thousand two hundred three.The class should have a single integer
//member variable :
//
//int number;
//
//and a static array of string objects that specify how to translate key dollar amounts
//into the desired format.For example, you might use static strings such as
//
//string lessThan20[20] = { "zero", "one", ..., "eighteen", "nineteen" };
//string hundred = "hundred";
//string thousand = "thousand";
//
//The class should have a constructor that accepts a nonnegative integerand uses it to
//initialize the Numbers object.It should have a member function print() that prints
//the English description of the Numbers object.Demonstrate the class by writing a main
//program that asks the user to enter a number in the proper rangeand then prints out
//its English description.

#include <iostream>
#include <string>
#include "Numbers.h"

using namespace std;

const string UNITS[10]{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const string TENS[10]{ "", "ten", "twenty", "thrity", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
const string TEENS[10]{ "", "eleven", "twelve", "thirteen", "fourteen",
"fifteen", "sixteen", "seventeen", "eighteen", "ninteen" };
const string HUNDRED = "hundred";
const string THOUSAND = "thousand";

string convertToWords(int);

int main() {

	Numbers num;
	string words;

	words = convertToWords(num.getNum());

	cout << words << "\n";

}

string convertToWords(int rem_total) {

	string result = "";

	int thousands;
	int hundreds;
	int tens;
	int units;
	string temp;

		thousands = rem_total / 1000;
		rem_total %= 1000;

		hundreds = rem_total / 100;
		rem_total %= 100;

		tens = rem_total / 10;
		rem_total %= 10;

		units = rem_total;

		//THOUSANDS ------------------------>

		for (int i = 0; i < 10; i++) {
			if (thousands == i) {
				if (thousands == 0) {
					break;
				}
				else {
					result += UNITS[i] + " " + THOUSAND;
				}				
			}
		}

		//HUNDREDS ------------------------>

		for (int i = 0; i < 10; i++) {
			if (hundreds == i) {
				if (thousands == 0 && hundreds == 0) {
					break; 
				} else if (thousands == 0 && hundreds != 0) {
					result += UNITS[i] + " " + HUNDRED;
				} else if (thousands != 0 && hundreds == 0) {
					break;
				}
				else {
					result += ", " + UNITS[i] +  " " + HUNDRED;
				}
			}
		}

		//TENS ------------------------>

		for (int i = 0; i < 10; i++) {
			if (tens == i) {
				if (hundreds == 0 && tens == 0) {
					break;
				}
				else if (hundreds != 0 && tens == 0) {
					break;
				} else if (hundreds == 0 && (tens != 0 || tens != 1)) {
					result += " and " + TENS[i];
				}
				else if (hundreds != 0 && (tens == 0 || tens == 1)) {
					break;
				}
				else if (hundreds == 0 && (tens == 0 || tens == 1)) {
					break;
				}
				else if ((thousands != 0 || hundreds == !0) && (tens == 0 || tens == 1)) {
					break;
				}
				else {
					break;
				}

			}
		}

		//UNITS ------------------------>

		for (int i = 0; i < 10; i++) {
			if (units == i) {
				if (thousands == 0 && hundreds == 0) {
					if (tens == 1) {
						result += TEENS[i] + " ";
					}
					if (tens == 0) {
						result += UNITS[i] + " ";
					}
				} else if (thousands != 0 || hundreds != 0) {
					if (tens == 1 && units != 0) {
						result += " and " + TEENS[i] + " ";
					} else if (tens == 1 && units == 0) {
						result += " and ten ";
					}
					else if (tens == 0 && units != 0) {
						result += " and " + UNITS[i] + " ";
					}
					else if (tens == 0 && units == 0) {
						result += " ";
					}
				} if (tens != 0 && units == 0) {
					result += " ";
				}
				else if (units == 0) {
					result += " ";
				}
			}
		}


		result += "dollars";
		result[0] = toupper(result[0]);

	return result;

}
