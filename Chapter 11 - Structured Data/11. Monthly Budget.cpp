//11. Monthly Budget
//
//A student has established the following monthly budget :
//
//Housing 500.00
//Utilities 150.00
//Household Expenses 65.00
//Transportation 50.00
//Food 250.00
//Medical 30.00
//Insurance 100.00
//Entertainment 150.00
//Clothing 75.00
//Miscellaneous 50.00
//
//Write a program that has a MonthlyBudget structure designed to hold each of these
//expense categories.The program should pass the structure to a function that asks the
//user to enter the amounts spent in each budget category during a month.The program
//should then pass the structure to a function that displays a report indicating the
//amount over or under in each category, as well as the amount over or under for the
//entire monthly budget.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct MonthlyBudget {

	double housing;
	double util;
	double h_expenses;
	double transport;
	double food;
	double medical;
	double insurance;
	double entertainment;
	double clothing;
	double misc;

};

const double	HOUSING = 500, UTIL = 150, H_EXPENSES = 65, TRANSPORT = 50, FOOD = 250,
				MEDICAL = 30, INSURANCE = 100, ENTERTAINMENT = 150, CLOTHING = 75, MISC = 50;

void mainDivider(string);
void softDivider(string);
void underOrOver(const double, double);
double enterExpense(string);

void expensesForm(MonthlyBudget&);
void subCategoryReport(string, const double, double, double&);
void expensesReport(MonthlyBudget);

int main() {

	const int	TYPES = 10;

	const string	expense_type[TYPES]{ "Housing", "Utilities", "Household Expenses", "Transport",
								"Food", "Medical", "Insurance", "Entertainment", "Clothing",
								"Miscellaneous" };

	MonthlyBudget month{};

	expensesForm(month);

	expensesReport(month);

}

void mainDivider(string title) {

	cout <<  title << endl;
	cout << "=======================" << endl;
	cout << endl;

}

void softDivider(string title) {

	cout << title << endl;
	cout << "-----------------------" << endl;

}

void underOrOver(const double BUDGET, double expense) {

	double num;

	num = expense - BUDGET;

	cout << fixed << setprecision(2);

	if (expense <= BUDGET) {
		cout << "$" << num << " UNDER budget.";
	}
	else {
		cout << "$" << num << " OVER budget.";
	}

}


double enterExpense(string expense_category) {

	double num;

	cout << expense_category;

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Expenses cannot be less than 0. " << endl;
		cout << endl;
		cout << expense_category;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

void expensesForm(MonthlyBudget &m) {

	mainDivider("MONTHLY EXPENSES FORM: ");

	cout << "Enter your expenses for the month." << endl;
	cout << endl;

	m.housing = enterExpense("Housing: $");
	m.util = enterExpense("Utilities: $");
	m.h_expenses = enterExpense("Household Expenses: $");
	m.transport = enterExpense("Transportation: $");
	m.food = enterExpense("Food: $");
	m.medical = enterExpense("Medical: $");
	m.insurance = enterExpense("Insurance: $");
	m.entertainment = enterExpense("Entertainment: $");
	m.clothing = enterExpense("Clothing: $");
	m.misc = enterExpense("Miscellaneous: $");

	cout << endl;

}

void subCategoryReport(string category, const double CATEGORY, double m_cat, double& total_expenses) {

	softDivider(category);
	cout << "Budget: $" << CATEGORY << endl;
	cout << "Actual Spend: $" << m_cat << endl;
	underOrOver(CATEGORY, m_cat);
	total_expenses += m_cat;
	cout << endl << endl;

}

void expensesReport(MonthlyBudget m) {

	double total_budget = HOUSING + UTIL + H_EXPENSES + TRANSPORT + FOOD + MEDICAL + INSURANCE + ENTERTAINMENT + CLOTHING + MISC;
	double total_expenses = 0;
	double budget_result;

	mainDivider("MONTHLY EXPENSES REPORT: ");

	cout << fixed << setprecision(2);
	
	subCategoryReport("Housing", HOUSING, m.housing, total_expenses);
	subCategoryReport("Utilities", UTIL, m.util, total_expenses);
	subCategoryReport("Household Expenses", H_EXPENSES, m.h_expenses, total_expenses);
	subCategoryReport("Transportation", TRANSPORT, m.transport, total_expenses);
	subCategoryReport("Food", FOOD, m.food, total_expenses);
	subCategoryReport("Medical", MEDICAL, m.medical, total_expenses);
	subCategoryReport("Insurance", INSURANCE, m.insurance, total_expenses);
	subCategoryReport("Entertainment", ENTERTAINMENT, m.entertainment, total_expenses);
	subCategoryReport("Clothing", CLOTHING, m.clothing, total_expenses);
	subCategoryReport("Miscellaneous", MISC, m.clothing, total_expenses);

	cout << "TOTAL MONTHLY BUDGET:   $" << total_budget << endl;
	cout << "TOTAL MONTHLY EXPENSES: $" << total_expenses << endl;
	cout << endl;

	budget_result = total_budget - total_expenses;

	cout << "You are $";

	if (budget_result < 0) {
		cout << budget_result << " OVER budget." << endl;
	}
	else if (budget_result == 0) {
		cout << "spot on with the budget!" << endl;
	}
	else {
		cout << budget_result << " UNDER budget." << endl;
	}

}
