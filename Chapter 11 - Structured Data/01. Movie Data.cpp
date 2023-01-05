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
////in a clearly formatted manner.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct MovieData {

	string title, director;
	int year_of_release, running_time;

};

MovieData getMovieData();
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

	cin.ignore();

	cout << endl;

	return m;

}

void showMovieData(MovieData m) {

	cout << "Title:         " << m.title << endl;
	cout << "Director:      " << m.director << endl;
	cout << "Year Released: " << m.year_of_release << endl;
	cout << "Running Time:  " << m.running_time << " minutes" << endl;

	cout << endl;

}