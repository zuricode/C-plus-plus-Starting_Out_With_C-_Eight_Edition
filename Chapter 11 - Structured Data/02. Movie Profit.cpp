//1. Movie Data
// 
//Write a program that uses a structure named MovieData to store the following information
//about a movie :
//Title
//Director
//Year Released
//Running Time(in minutes)
// 
//The program should create two MovieData variables, store values in their members,
//and pass each one, in turn, to a function that displays the information about the movie
//in a clearly formatted manner.
//
//2. Movie Profit
//Modify the Movie Data program written for Programming Challenge 1 to include two
//additional members that hold the movie’s production costs and first - year revenues.
//Modify the function that displays the movie data to display the title, director, release
//year, running time, and first year’s profit or loss.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct MovieData {

	string title, director;
	int year_of_release, running_time;
	double production_cost, first_year_revenue;

};

MovieData getMovieData();
void showNetIncome(double, double);
void showMovieData(MovieData);

int main() {

	MovieData movie1, movie2;

	movie1 = getMovieData();
	movie2 = getMovieData();

	showMovieData(movie1);
	showMovieData(movie2);

}

MovieData getMovieData() {

	MovieData m;

	cout << "What is the name of your movie: ";
	getline(cin, m.title);

	cout << "Who was the director of \"" << m.title << "\": ";
	getline(cin, m.director);

	cout << "What year was \"" << m.title << "\" released: ";
	cin >> m.year_of_release;

	cout << "What is the running time (in mins): ";
	cin >> m.running_time;

	cout << "What was the production cost: $";
	cin >> m.production_cost;

	cout << "How much revenue was generated in the first year of release: $";
	cin >> m.first_year_revenue;

	cin.ignore();

	cout << endl;

	return m;

}

void showNetIncome(double cost, double revenue) {
	
	double net_income = 0;
	net_income -= cost;
	net_income += revenue;

	cout << "Net Income:   $" << fixed << setprecision(1) << net_income / 1000000 << " mil " << endl;

}

void showMovieData(MovieData m) {

	cout << "Title:         " << m.title << endl;
	cout << "Director:      " << m.director << endl;
	cout << "Year Released: " << m.year_of_release << endl;
	cout << "Running Time:  " << m.running_time << " minutes" << endl;
	showNetIncome(m.production_cost, m.first_year_revenue);
	cout << endl;

}