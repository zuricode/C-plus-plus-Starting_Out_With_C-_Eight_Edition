//13. Carpet Calculator
//
//The Westfield Carpet Company has asked you to write an application that calculates
//the price of carpeting for rectangular rooms.To calculate the price, you multiply
//the area of the floor (width * length) by the price per square foot of carpet.
//For example, the area of floor that is 12 feet longand 10 feet wide is 120 square
//feet.To cover that floor with carpet that costs $8 per square foot would cost $960.
//(12 X 10 X 8 = 960.)
//
//First, you should create a class named RoomDimension that has two FeetInches
//objects as attributes : one for the length of the room and one for the width. (You should
//use the version of the FeetInches class that you created in Programming Challenge 11
//with the addition of a multiply member function.You can use this function to calculate
//the area of the room.) The RoomDimension class should have a member function
//that returns the area of the room as a FeetInches object.
//
//Next, you should create a RoomCarpet class that has a RoomDimension object as an
//attribute. It should also have an attribute for the cost of the carpet per square foot.
//The RoomCarpet class should have a member function that returns the total cost of
//the carpet.
//
//Once you have written these classes, use them in an application that asks the user to
//enter the dimensions of a room and the price per square foot of the desired carpeting.
//The application should display the total cost of the carpet.

#include "RoomDimension.h"
#include "RoomCarpet.h"
#include <iomanip>

using namespace std;

int main() {

	RoomCarpet customer_1;

	cout << "=================================\n";
	cout << "13 - CARPET CALCULATOR PROGRAM\n";
	cout << "=================================\n";

	cout << "\n";

	customer_1.setRoomArea();

	cout << fixed << setprecision(2);
	cout << "Total area of carpet: " << customer_1.getRoomArea() << " sq ft.\n";
	cout << "\n";

	customer_1.setCost();	

	cout << "The cost of the carpet will be $" << customer_1.calculateCost() << "\n";
	cout << "\n";

}
