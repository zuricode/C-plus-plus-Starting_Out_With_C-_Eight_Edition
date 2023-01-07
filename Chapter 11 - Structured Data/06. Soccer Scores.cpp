//6. Soccer Scores
//
//Write a program that stores the following data about a soccer player in a structure :
//
//Player’s Name
//Player’s Number
//Points Scored by Player
//
//The program should keep an array of 12 of these structures.Each element is for a different
//player on a team.When the program runs it should ask the user to enter the data
//for each player.It should then show a table that lists each player’s number, name, and
//points scored.The program should also calculateand display the total points earned by
//the team.The numberand name of the player who has earned the most points should
//also be displayed.
//
//Input Validation : Do not accept negative values for players’ numbers or points scored.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Player {

	string		name;
	int			number{};
	double		points{};

};

int inputInt();
double inputDouble();
void getPlayerData(Player[], const int);
void showPlayerData(Player[], const int);
void getPointsData(Player[], const int, double&, string&, double&, int&);
void showPointsData(double, string, double, int);

int main() {

	const int	AMOUNT = 3;

	Player		team[AMOUNT];
	double		total_points = 0, highest_points;
	string		top_scorer_name;
	int			num_of_top_scorer;

	getPlayerData(team, AMOUNT);
	showPlayerData(team, AMOUNT);
	getPointsData(team, AMOUNT, total_points, top_scorer_name, highest_points, num_of_top_scorer);
	showPointsData(total_points, top_scorer_name, highest_points, num_of_top_scorer);

}

int inputInt() {

	int num;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Value must be an integer greater than 0. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

double inputDouble() {

	double num;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Value must be a double greater than 0. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void getPlayerData(Player p[], const int AMOUNT) {

	cout << "Enter player data." << endl;
	cout << endl;

	for (int i = 0; i < AMOUNT; i++) {

		cout << "PLAYER #" << i + 1 << endl;
		cout << "-----------" << endl;

		cout << "Name: ";
		getline(cin, p[i].name);

		cout << "Number: ";
		p[i].number = inputInt();

		cout << "Points scored: ";
		p[i].points = inputDouble();

		cin.ignore();


		cout << endl;

	}

}

void showPlayerData(Player p[], const int AMOUNT) {

	cout << fixed << setprecision(1) << left;

	cout << "TABLE OF PLAYER DATA" << endl;
	cout << "===================================================" << endl;
	cout << endl;
	cout << setw(30) << "Name" << setw(15) << "Player No." << setw(15) << "Points" << endl;
	cout << endl;
	
	for (int i = 0; i < AMOUNT; i++) {
		cout << setw(30) << p[i].name << setw(12) << "#" << p[i].number << setw(10) << p[i].points << endl;
	}

	cout << endl;

}

void getPointsData(Player p[], const int AMOUNT, double& total_points, string& top_scorer_name, double& highest_points, int& num_of_top_scorer) {

	top_scorer_name = p[0].name;
	highest_points = p[0].points;
	num_of_top_scorer = p[0].number;


	for (int i = 0; i < AMOUNT; i++) {

		total_points += p[i].points;

		if (p[i].points > highest_points) {
			highest_points = p[i].points;
			top_scorer_name = p[i].name;
			num_of_top_scorer = p[i].number;
		}

	}

}

void showPointsData(double total_points, string top_scorer_name, double highest_points, int num_of_top_scorer) {

	cout << "Total Points Scored: " << total_points << endl;
	cout << "Top Scorer: " << top_scorer_name << endl;
	cout << "Top Scorer Player Number: " << num_of_top_scorer << endl;
	cout << "Points Scored By " << top_scorer_name << ": " << highest_points << endl;

}
