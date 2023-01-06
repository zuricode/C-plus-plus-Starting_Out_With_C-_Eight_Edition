//3. Corporate Sales Data
// 
//Write a program that uses a structure to store the following data on a company
//division :
//Division Name(such as East, West, North, or South)
//First - Quarter Sales
//Second - Quarter Sales
//Third - Quarter Sales
//Fourth - Quarter Sales
//Total Annual Sales
//Average Quarterly Sales
// 
//The program should use four variables of this structure.Each variable should represent
//one of the following corporate divisions : East, West, North, and South.The
//user should be asked for the four quarters’ sales figures for each division.Each
//division’s totaland average sales should be calculatedand stored in the appropriate
//member of each structure variable.These figures should then be displayed on the
//screen.
// 
//Input Validation : Do not accept negative numbers for any sales figures.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int	DIVISIONS = 4;
const string	REGIONS[DIVISIONS]{ "East", "West", "North", "South" };

struct CompanyDivision {

	string		division_name;
	double		firstq_sales{};
	double		secondq_sales{};
	double		thirdq_sales{};
	double		fourthq_sales{};
	double		total_annual_sales{0};
	double		avgq_sales{};

};

double getFigure();
void getSales(CompanyDivision[]);
void calculateSales(CompanyDivision[], int);

int main() {

	CompanyDivision divisions[DIVISIONS];

	getSales(divisions);

}

double getFigure() {

	double num;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Amount cannot be less than 0. Re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}

void getSales(CompanyDivision d[]) {

	for (int i = 0; i < DIVISIONS; i++) {

		d[i].division_name = REGIONS[i];
		cout << d[i].division_name << " division: " << endl;
		cout << "-------------------" << endl;
		
		cout << "First-Quarter Sales: $";
		d[i].firstq_sales = getFigure();

		cout << "Second-Quarter Sales: $";
		d[i].secondq_sales = getFigure();

		cout << "Third-Quarter Sales: $";
		d[i].thirdq_sales = getFigure();

		cout << "Fourth-Quarter Sales: $";
		d[i].fourthq_sales = getFigure();

		cout << endl;

		calculateSales(d, i);

		cout << endl;

	}

}

void calculateSales(CompanyDivision d[], int num) {

	d[num].total_annual_sales += d[num].firstq_sales;
	d[num].total_annual_sales += d[num].secondq_sales;
	d[num].total_annual_sales += d[num].thirdq_sales;
	d[num].total_annual_sales += d[num].fourthq_sales;

	cout << "Total Annual Sales of the " << REGIONS[num] << " division: $" << fixed << setprecision(2) << d[num].total_annual_sales << endl;

	d[num].avgq_sales = d[num].total_annual_sales / DIVISIONS;
	cout << "Average Quarterly Sales of the " << REGIONS[num] << " division: $" << fixed << setprecision(2) << d[num].avgq_sales << endl;

}
