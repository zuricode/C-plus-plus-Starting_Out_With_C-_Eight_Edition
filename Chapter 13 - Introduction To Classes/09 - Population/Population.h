#ifndef POPULATION_H
#define POPULATION_H
#include <string>

using std::string;

class Population {

private:
	string name;
	int population;
	int births;
	int deaths;

public:
	Population();

	void setName();
	void setPopulation();
	void setBirths();
	void setDeaths();

	string getName();
	int getPopulation();
	int getBirths();
	int getDeaths();

	double birthRate();
	double deathRate();

};

#endif