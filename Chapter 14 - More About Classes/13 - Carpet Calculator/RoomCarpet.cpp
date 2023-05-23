#include "RoomCarpet.h"
#include "RoomDimension.h"
#include "FeetInches.h"

double RoomCarpet::calculateCost() const {

	double area;
	
	area = room.getAreaSqFt();

	return area * cost_per_sq_ft;

}