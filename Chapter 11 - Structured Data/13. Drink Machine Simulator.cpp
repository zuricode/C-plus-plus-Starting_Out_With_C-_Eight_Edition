//13. Drink Machine Simulator
//
//Write a program that simulates a soft drink machine.The program should use a structure
//
//that stores the following data :
//Drink Name
//Drink Cost
//Number of Drinks in Machine
//
//The program should create an array of five structures.The elements should be initialized
//with the following data :
//
//Drink Name		Cost	Number in Machine
//Cola			.75				20
//Root Beer		.75				20
//Lemon - Lime	.75				20
//Grape Soda		.80				20
//Cream Soda		.80				20
//
//Each time the program runs, it should enter a loop that performs the following steps :
//A list of drinks is displayed on the screen.The user should be allowed to either quit the
//program or pick a drink.If the user selects a drink, he or she will next enter the amount
//of money that is to be inserted into the drink machine.The program should display
//the amount of change that would be returned and subtract one from the number of
//that drink left in the machine.If the user selects a drink that has sold out, a message
//should be displayed.The loop then repeats.When the user chooses to quit the program
//it should display the total amount of money the machine earned.
//
//Input Validation : When the user enters an amount of money, do not accept negative
//values or values greater than $1.00.

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct Drink {

	string name;
	double cost;
	int number_in_machine;

};

double doubleTwoLimits(int, int, string);
bool yesOrNo(string);

void divider();

void initStock(Drink[], const int, const int);

int drinksMenu(Drink[], const int, const int, bool);
void displayDrinkInfo(Drink[], int);
void menuChoice(int);
void verifyPurchase(Drink[], int, bool&);
void showEarnings(Drink[], const int, const int, bool);

int main() {

	const int		TYPES_OF_DRINK = 5;
	const int		STOCK = 1;

	Drink drinks[TYPES_OF_DRINK]{ {"Cola", 0.75}, {"Root Beer", 0.75}, {"Lemon-Lime", 0.75}, {"Grape Soda", 0.80}, {"Cream Soda", 0.80} };

	int menu_choice;
	double balance = 0;
	bool buy_again;
	bool isSale = false;

	initStock(drinks, TYPES_OF_DRINK, STOCK);

	cout << endl;

	do {

		menu_choice = drinksMenu(drinks, TYPES_OF_DRINK, STOCK, isSale);

		divider();

		displayDrinkInfo(drinks, menu_choice);

		verifyPurchase(drinks, menu_choice, isSale);

		buy_again = yesOrNo("\tWould you like to purchase another drink (Y/N): ");

		divider();

	} while(buy_again);

	showEarnings(drinks, TYPES_OF_DRINK, STOCK, isSale);

	cout << "\tQuiting the program......" << endl;
	exit(EXIT_SUCCESS);

}

bool yesOrNo(string question) {

	char letter;

	cout << question;

	while (!(cin >> letter) || (letter != 'Y' && letter != 'y' && letter != 'N' && letter != 'n')) {
		cout << "\tERROR: Please answer with \"Y\", \"N\", \"y\", \"n\"." << endl;
		cout << endl;
		cout << question;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	letter = toupper(letter);

	if (letter == 'Y') {
		return true;
	}
	else {
		return false;
	}

}

int intTwoLimits(int min, int max, string request) {

	int num;

	cout << request;

	while (!(cin >> num) || num < min || num > max) {
		cout << "\tERROR: Value must be an integer between (and including) " << min << " and " << max << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

double doubleTwoLimits(int min, int max, string request) {

	double num;

	cout << request;

	while (!(cin >> num) || num < min || num > max) {
		cout << "\tERROR: Value must be an integer between (and including) " << min << " and " << max << "." << endl;
		cout << endl;
		cout << request;
		cin.clear();
		cin.ignore(1200, '\n');
	}

	cin.clear();
	cin.ignore(1200, '\n');

	return num;

}

void divider() {

	cout << endl;
	cout << left << setfill('*') << setw(90) << "\t" << endl;
	cout << setfill(' ') << endl;

}

void initStock(Drink drinks[], const int TYPES, const int STOCK) {

	for (int i = 0; i < TYPES; i++) {
		drinks[i].number_in_machine = STOCK;
	}

}

int drinksMenu(Drink drinks[], const int TYPES, const int STOCK, bool isSale) {

	int menu_choice;
	bool repeat;

	cout << "\t=============================" << endl;
	cout << "\t      BEVERAGE MACHINE       " << endl;
	cout << "\t=============================" << endl;
	cout << endl;

	do {

		repeat = false;

		cout << "\tDrinks: " << endl;
		cout << "\t" << endl;
		cout << "\t" << left << setfill(' ') << setw(10) << "No." << setw(15) << "Drink name" << setw(20) << "Stock " << endl;
		cout << setfill('-') << setw(50) << "\t" << endl;
		cout << setfill(' ');

		for (int i = 0; i < TYPES; i++) {

			cout << "\t" << i + 1 << setw(9) << ")" << setw(15) << drinks[i].name;

			if (drinks[i].number_in_machine == 0) {
				cout << setw(20) << "OUT OF STOCK!" << endl;
			}
			else {
				cout << setw(20) << drinks[i].number_in_machine << endl;
			}

		}

		cout << endl;

		menu_choice = intTwoLimits(0, 5, "\tChoose your drink (1-5) or enter \"0\" to quit the program: ");

		if (menu_choice != 0) {
			menu_choice -= 1;

			if (drinks[menu_choice].number_in_machine == 0) {
				cout << endl;
				cout << left << setfill('#') << setw(40) << "\t" << endl;
				cout << left << setfill(' ') << setw(40) << "\t" << endl;
				cout << "\tERROR: " << drinks[menu_choice].name << " is currently out of stock. " << endl;
				cout << left << setfill(' ') << setw(40) << "\t" << endl;
				cout << left << setfill('#') << setw(40) << "\t" << endl;
				repeat = true;
				cout << endl;
			}

		}
				
		else {

			cout << endl;

			showEarnings(drinks, TYPES, STOCK, isSale);

			cout << "\tQuiting the program......" << endl;
			exit(EXIT_SUCCESS);
		}

	} while (repeat);		

	cout << endl;

	return menu_choice;

}

void displayDrinkInfo(Drink drinks[], int menu_choice) {

	cout << fixed << setprecision(2);

	cout << "\tYou have selected: " << endl;
	cout << "\t---------------------------------" << endl;
	cout << "\t" << "Name:              " << drinks[menu_choice].name << endl;
	cout << "\t" << "Cost:              $" << drinks[menu_choice].cost << endl;
	cout << "\t" << "Amount in-stock:   " << drinks[menu_choice].number_in_machine << endl;
	cout << endl;

}

void menuChoice(int menu_choice) {

	menu_choice -= 1;

	switch (menu_choice) {

		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;

	}

}

void verifyPurchase(Drink drinks[], int menu_choice, bool &isSale) {

	double money;
	double balance = 0;
	bool isEnough = false;

	cout << fixed << setprecision(2);

	do {

		cout << "\tCurrent balance: $" << balance << endl;
		money = doubleTwoLimits(0, 1, "\tHow much will you put into the machine ($1.00 maximum): $");
		balance += money;

		cout << endl;

		if (balance >= drinks[menu_choice].cost) {
			isEnough = true;
			balance -= drinks[menu_choice].cost;
			drinks[menu_choice].number_in_machine--;
			isSale = true;

			cout << left << setfill('*') << setw(40) << "\t" << endl;
			cout << left << setfill(' ') << setw(40) << "\t" << endl;
			cout << "\t      D R I N K  D I S P E N S E D       " << endl;
			cout << left << setfill(' ') << setw(40) << "\t" << endl;
			cout << left << setfill('*') << setw(40) << "\t" << endl;

			cout << endl;

			cout << "\tYou have purchased 1x " << drinks[menu_choice].name << ". Thank you!" << endl;
			cout << "\tChange dispensed: $" << balance << endl;
			cout << "\t" << endl;
			cout << "\tPlease collect your drink and come again." << endl;

		}

		else {
			cout << "\tInsufficient funds! " << drinks[menu_choice].name << " costs $" << drinks[menu_choice].cost << " but your balance is $" << balance << "." << endl;
		}

		cout << endl;

	} while(!isEnough);
		
}

void showEarnings(Drink drinks[], const int TYPES, const int STOCK, bool isSale) {

	int amount_sold;
	double total = 0;

	if (isSale) {

		cout << "\tVENDING MACHINE EARNINGS" << endl;
		cout << "\t-------------------------------------------------------";
		cout << endl;

		cout << left << setw(20) << "\tDRINK" << setw(20) << "QUANTITY SOLD" << setw(20) << "EARNINGS" << endl;
		cout << endl;

		for (int i = 0; i < TYPES; i++) {
			amount_sold = STOCK - drinks[i].number_in_machine;

			if (amount_sold > 0) {
				total += amount_sold * drinks[i].cost;
				cout << "\t" << setw(20) << drinks[i].name << setw(20) << amount_sold << "$" << amount_sold * drinks[i].cost << endl;
			}

		}

		cout << "\t-------------------------------------------------------" << endl;
		cout << setw(41) << "\tTOTAL EARNINGS: " << "$" << total << endl;

	}
	else {
		cout << "\tNo sales were made from the vending machine." << endl;
	}
	
	

	cout << endl;

}