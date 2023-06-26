//12. Ship, CruiseShip, and CargoShip Classes
//
//Design a Ship class that has the following members :
//
//	• A member variable for the name of the ship(a string)
//	• A member variable for the year that the ship was built(a string)
//	• A constructorand appropriate accessorsand mutators
//	• A virtual print function that displays the ship’s nameand the year it was built.
//
//Design a CruiseShip class that is derived from the Ship class.The CruiseShip class
//should have the following members :
//
//	• A member variable for the maximum number of passengers(an int)
//	• A constructorand appropriate accessorsand mutators
//	• A print function that overrides the print function in the base class.The CruiseShip
//	class’s print function should display only the ship’s nameand the maximum number
//	of passengers.
//Design a CargoShip class that is derived from the Ship class.The CargoShip class
//should have the following members :
//
//	• A member variable for the cargo capacity in tonnage(an int).
//	• A constructorand appropriate accessorsand mutators.
//	• A print function that overrides the print function in the base class.The CargoShip
//	class’s print function should display only the ship’s nameand the ship’s cargo capacity.
//
//Demonstrate the classes in a program that has an array of Ship pointers.The array
//elements should be initialized with the addresses of dynamically allocated Ship,
//CruiseShip, and CargoShip objects. (See Program 15 - 14, lines 17 through 22, for an
//	example of how to do this.) The program should then step through the array, calling
//	each object’s print function.

#include "CruiseShip.h"
#include "CargoShip.h"

int main() {

	const int NUMBER_OF_SHIPS = 3;

	Ship *ships[NUMBER_OF_SHIPS] {
		new Ship("H.M.S Windrush", "1952"),
		new CruiseShip("Titanic", "1932", 5000),
		new CargoShip("Cargo Express", "1986" , 450)
	};

	cout << "==================================================\n";
	cout << "15-12 SHIP, CRUISESHIP & CARGOSHIP CLASSES PROGRAM\n";
	cout << "==================================================\n";
	cout << "\n";

	cout << "List of ships\n";
	cout << "-------------\n";
	cout << "\n";

	for (int i = 0; i < NUMBER_OF_SHIPS; i++) {
		cout << *ships[i] << "\n";
	}

	delete ships[0];
	delete ships[1];
	delete ships[2];

}