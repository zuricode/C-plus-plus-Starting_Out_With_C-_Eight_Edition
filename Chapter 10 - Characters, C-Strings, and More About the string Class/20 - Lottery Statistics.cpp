/**
 *
 * 20. Lottery Statistics
 *
 *  To play the PowerBall lottery, you buy a ticket that has
 * five numbers in the range of 1-69, and a "PowerBall" number
 * in the range of 1-26. (You can pick the numbers yourself,
 * or you can let the ticket machine randomly pick them for you.)
 * Then, on a specified date, a winning set of numbers are randomly
 * selected by a machine. If a specified date, and winning set of
 * numbers are randomly selected by a machine. If your first five
 * numbers match the first five winning numbers in any order, and
 * your PowerBall number matched the winning PowerBall number, then
 * you win the jackpot which is a very large amount of money. If your
 * numbers match only some of the winning numbers, you win a lesser
 * amount, depending on how many of the winning numbers you have
 * matched.
 *
 * In the student sample programs for this book, you will find a file named pbnumbers.txt,
 * containing the winning lottery numbers that were selected between February 3, 2010
 * and May 11, 2016 (the file contains 654 sets of winning numbers). Here is an example of the first
 * few lines of the file's contents:
 * 17 22 36 37 52 24
 * 14 22 52 54 59 04
 * 05 08 29 37 38 34
 * 10 14 30 40 51 01
 * 07 08 19 26 36 15
 * and so on...
 *
 * Each line in the file contains the set of six numbers that were selected on a given date.
 * The numbers are separated by a space, and the last number in each line is the PowerBall
 * number for the day. For example, the first line in the file shows the numbers for February 3, 2010,
 * which are 17, 22, 36, 37, 52, and the PowerBall number 24.
 *
 * Write one or more programs that work with this file to perform the following:
 *
 * - Display the 10 most common numbers, ordered by frequency.
 * - Display the 10 least common numbers, ordered by frequency.
 * - Display the 10 most overdue numbers (numbers that haven't been
 *      drawn in a long time), ordered from most overdue to least overdue.
 * - Display the frequency of each number 1-69, and the frequency of each Powerball
 *      number 1-26.
 *
 **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


string generateTicket(const int, const int, const int, const int);
bool checkDuplicateNumber(int, vector<int>);
vector<int> stringToIntConversion(string);
vector<int> stringToIntConversion(vector<string>);
void displayTicketNumbers(vector<int>, string);
void displayVector(vector<string>, string);
void checkNumbers(vector<int>, vector<int>, int&, bool&, const int);
void drawResults(int, bool);

vector<string> importTicketData(const string);
void numberTally(vector<int>, const int, vector<int>&, vector<int>&);
void highToLowVector(vector<int>&, vector<int>&);
void lowToHighVector(vector<int>&, vector<int>&);

void int_swap(int&, int&);
void topTenNumbers(vector<int>, vector<int>);
void bottomTenNumbers(vector<int>, vector<int>);
void NumberFrequency(string, vector<int>, vector<int>);

void pbNumbers(vector<int>, vector<int>&);


int main() {
	
	srand(time(NULL));

	const int		SIZE = 6, MIN_NUM = 1, MAX_NUM = 69, MAX_POWERBALL = 26;
	const string	FILE = "C:\\Users\\Admin\\source\\repos\\Project2\\Project2\\C-plus-plus-Starting_Out_With_C-_Eight_Edition\\Chapter 10 - Characters, C-Strings, and More About the string Class\\pbnumbers.txt";

	string			myTicket, winningTicket;
	vector<string>	ticketData;
	vector<int>		my_ticket_numbers, winning_ticket_numbers, ticketDataAllInts, numbers, tally, pb_data, pb_numbers, pb_tally;
	int				matching_numbers = 0;
	bool			powerball = false;

	myTicket = generateTicket(SIZE, MAX_NUM, MIN_NUM, MAX_POWERBALL);
	winningTicket = generateTicket(SIZE, MAX_NUM, MIN_NUM, MAX_POWERBALL);
	my_ticket_numbers = stringToIntConversion(myTicket);
	winning_ticket_numbers = stringToIntConversion(winningTicket);

	cout << "Winning lottery ticket: " << winningTicket << endl;
	cout << "My lottery ticket: " << myTicket << endl << endl;

	displayTicketNumbers(winning_ticket_numbers, "Winning ticket");
	displayTicketNumbers(my_ticket_numbers, "My ticket");

	checkNumbers(my_ticket_numbers, winning_ticket_numbers, matching_numbers, powerball, SIZE);
	drawResults(matching_numbers, powerball);

	cout << endl;

	ticketData = importTicketData(FILE);

	//Convert all numbers in the ticketData string vector into individual integers within an int vector.
	ticketDataAllInts = stringToIntConversion(ticketData);

	numberTally(ticketDataAllInts, MAX_NUM, numbers, tally);

	topTenNumbers(numbers, tally);
	bottomTenNumbers(numbers, tally);
	NumberFrequency("Frequency of each number 1-69: ", numbers, tally);

	pbNumbers(ticketDataAllInts, pb_data);
	numberTally(pb_data, MAX_POWERBALL, pb_numbers, pb_tally);
	NumberFrequency("Frequency of Powerball numbers: ", pb_numbers, pb_tally);

	//displayVector(ticketData, "Imported ticket data");

}

string generateTicket(const int SIZE, const int MAX_NUM, const int MIN_NUM, const int MAX_POWERBALL) {

	string		myTicket = "", num_string;
	int			new_num;
	vector<int>	numbers;
	bool match;
			
	while (numbers.size() < SIZE) {

		if (numbers.size() != (SIZE - 1)) {
			new_num = rand() % MAX_NUM + MIN_NUM;
			match = checkDuplicateNumber(new_num, numbers);

			if (!match) {
				numbers.push_back(new_num);
				num_string = to_string(new_num);
				myTicket += num_string + " ";
			}
			
		}

		else {

			new_num = rand() % MAX_POWERBALL + MIN_NUM;
			match = checkDuplicateNumber(new_num, numbers);

			if (!match) {
				numbers.push_back(new_num);
				num_string = to_string(new_num);
				myTicket += num_string;
			}
			
		}
		
	}

	return myTicket;
	
}

bool checkDuplicateNumber(int num, vector<int> numbers) {

	bool match = false;

	for (int i = 0; i < numbers.size(); i++) {

		if (num == numbers[i]) {
			match = true;
			break;
		}

	}
	
	return match;

}

vector<int> stringToIntConversion(string ticket) {

	vector<int> numbers;
	string temp = "";

	for (int i = 0; i < ticket.length(); i++) {

		if (isdigit(ticket[i])) {
			temp += ticket[i];
		}
		if (isspace(ticket[i]) || i == ticket.length() - 1) {
			numbers.push_back(stoi(temp));
			temp = "";
		}

	}

	return numbers;

}

vector<int> stringToIntConversion(vector<string> list) {

	vector<int> numbers;
	string temp = "";

	for (int j = 0; j < list.size(); j++) {

		for (int i = 0; i < list[j].length(); i++) {

			if (isdigit(list[j][i])) {
				temp += list[j][i];
			}
			if (isspace(list[j][i]) || i == list[j].length() - 1) {
				numbers.push_back(stoi(temp));
				temp = "";
			}

		}

	}		

	return numbers;

}

void displayTicketNumbers(vector<int> numbers, string type) {

	cout << type << ": " << endl;

	for (int i = 0; i < numbers.size(); i++) {

		if (i != numbers.size() - 1) {
			cout << numbers[i] << endl;
		}
		else {
			cout << numbers[i] << " (Powerball)" << endl;
		}

	}

	cout << endl;

}

void checkNumbers(vector<int> myNumbers, vector<int> winningNumbers, int& matching_numbers, bool& powerball, const int SIZE) {

	for (int i = 0; i < SIZE; i++) {
		for (int j = i; j < SIZE; j++) {
			if (myNumbers[i] == winningNumbers[j]) {
				matching_numbers++;
			}
		}
	}

	if (matching_numbers == 5) {
		powerball = true;
	}

}

void drawResults(int matching_numbers, bool powerball) {
	
	cout << "LOTTERY RESULTS: " << endl;
	cout << "==================================" << endl;
	cout << "Matching numbers: " << matching_numbers << endl;

	if (powerball) {
		cout << "POWERBALL MATCH! YOU HAVE WON THE JACKPOT!!!" << endl;
	}

}

vector<string> importTicketData(const string FILE) {

	vector<string> ticketData;
	string line;

	ifstream file;

	file.open(FILE);

	if (file.fail()) {
		cout << "File could not open. Please correct the file location and restart the program." << endl;
		exit(EXIT_FAILURE);
	}

	while (getline(file, line)) {
		ticketData.push_back(line);
	}

	file.close();

	return ticketData;

}

void displayVector(vector<string> list, string type) {

	cout << type << ": " << endl << endl;

	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}

}

void numberTally(vector<int> list, const int NUM, vector<int>& numbers, vector<int>& tally) {

	int counter;

	for (int i = 1; i <= NUM; i++) {

		counter = 0;

		for (int j = 0; j < list.size(); j++) {

			if (i == list[j]) {
				counter++;
			}

		}

		tally.push_back(counter);
		numbers.push_back(i);

	}

}

void highToLowVector(vector<int>& numbers, vector<int>& tally) {

	int highest, number;

	for (int i = 0; i < tally.size() - 1; i++) {

		highest = tally[i];
		number = i;

		for (int j = i + 1; j < tally.size(); j++) {

			if (tally[j] > highest) {
				highest = tally[j];
				number = j;
			}

		}

		int_swap(tally[i], tally[number]);
		int_swap(numbers[i], numbers[number]);

	}

}

void lowToHighVector(vector<int>& numbers, vector<int>& tally) {

	int lowest, number;

	for (int i = 0; i < tally.size() - 1; i++) {

		lowest = tally[i];
		number = i;

		for (int j = i + 1; j < tally.size(); j++) {

			if (tally[j] < lowest) {
				lowest = tally[j];
				number = j;
			}

		}

		int_swap(tally[i], tally[number]);
		int_swap(numbers[i], numbers[number]);

	}

}

void int_swap(int& a, int& b) {

	int temp;
	temp = a;
	a = b;
	b = temp;

}

void topTenNumbers(vector<int> numbers, vector<int> tally) {

	highToLowVector(numbers, tally);

	cout << "Top 10 highest occuring numbers (by frequency): " << endl;
	cout << "====================================================================" << endl;
	cout << endl;

	cout << "Rank" << "\tNumber" << "\tFrequency" << endl << endl;
	
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ".\t" << numbers[i] << "\t" << tally[i] << endl;
	}

	cout << endl;

}

void bottomTenNumbers(vector<int> numbers, vector<int> tally) {

	lowToHighVector(numbers, tally);

	cout << "Top 10 lowest occuring numbers (by frequency): " << endl;
	cout << "====================================================================" << endl;
	cout << endl;

	cout << "Rank" << "\tNumber" << "\tFrequency" << endl << endl;

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ".\t" << numbers[i] << "\t" << tally[i] << endl;
	}

	cout << endl;

}

void NumberFrequency(string type, vector<int> numbers, vector<int> tally) {

	cout << type << endl;
	cout << "=================================" << endl;
	cout << endl;

	cout << "Number" << "\tFrequency" << endl << endl;

	for (int i = 0; i < tally.size(); i++) {
		cout << numbers[i] << "\t" << tally[i] << endl;
	}

	cout << endl;

}

void pbNumbers(vector<int> list, vector<int>& pb_numbers) {

	for (int i = 0; i < list.size(); i++) {

		if ((i + 1) % 6 == 0) {
			pb_numbers.push_back(list[i]);
		}

	}

}
