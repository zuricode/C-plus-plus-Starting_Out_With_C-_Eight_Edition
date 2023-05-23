#ifndef ROOMCARPET_H
#define ROOMCARPET_H

class RoomCarpet {

private:
	RoomDimension room;
	double cost_per_sq_ft;

public:
	RoomCarpet() { cost_per_sq_ft = 0; }
	RoomCarpet(const double num) { cost_per_sq_ft = num; }

	double calculateCost() const;

};

#endif