#include "RoomCarpet.h"
#include "RoomDimension.h"
#include "FeetInches.h"

double RoomCarpet::calculateCost() {

	double area;
	
	area = room.getAreaSqFt();

	return area * cost_per_sq_ft;

}

double RoomCarpet::getRoomArea() {

	return room.getAreaSqFt();

}


void RoomCarpet::setRoomArea() {

	room.setLengthAndWidth();

}

void RoomCarpet::setCost() {

	double num;

	cout << "Enter the cost of a square foot of your chosen carpet: $";

	while (!(cin >> num) || num < 0) {
		cout << "ERROR: Cost cannot be a negative value.\n";
		cout << "\n";
		cout << "Cost: $";
		cin >> num;
	}
	
	cost_per_sq_ft = num;

	cout << "\n";


}