#include <iostream>
#include <iomanip>

using namespace std;

const double		LABOUR_PER_HOUR{ 25.00 },
					_8HOURS_AND_PAINT{ 110.00 };

double				rooms,
					paint_price_gallon,
					wall_space,
					total_wall_space{};

double InputValidation(double, int);
double Rooms();
double WallSpace(double);
double PaintPrice();
void JobReport();

int main() {

	rooms = Rooms();
	total_wall_space = WallSpace(rooms);
	paint_price_gallon = PaintPrice();	

	JobReport();

}

double InputValidation(double num, int limit) {

	while (!(cin >> num) || num < limit) {
		cout << "Error: Value must a number greater than " << limit << ". Please re-enter your value: ";
		cin.clear();
		cin.ignore(1200, '\n');
	}

	return num;

}	

double Rooms() {

	cout << "\nHow many rooms will you paint: ";

	return InputValidation(rooms, 1);

}

double WallSpace(double Rooms) {
	
	cout << endl;

	if (rooms == 1) {

		cout << "What is the total wall space of room #" << rooms << " (in sq feet) : ";
		total_wall_space = InputValidation(total_wall_space, 0);

	}
	else {

		for (int i = 1; i <= Rooms; i++) {

			cout << "What is the total wall space of room #" << i << " (in sq feet): ";
			wall_space = InputValidation(wall_space, 0);
			total_wall_space += wall_space;

		}

	}

	return total_wall_space;

}

double PaintPrice() {

	cout << "\nWhat is the price of the paint per gallon: $";

	return InputValidation(paint_price_gallon, 10);

}

void JobReport() {

	cout << "\nPAINT JOB";
	cout << "\n------------------------";
	cout << endl;

	double	gallons_required = total_wall_space / _8HOURS_AND_PAINT,
		labour_hours_required = (total_wall_space / _8HOURS_AND_PAINT) * 8,
		paint_price_total = paint_price_gallon * gallons_required,
		labour_charges = labour_hours_required * LABOUR_PER_HOUR,
		job_total_cost = paint_price_total + labour_charges;

	cout << fixed << setprecision(2);
	cout << "\nThe number of gallons of paint required: " << gallons_required;
	cout << "\nThe hours of labor required: " << labour_hours_required;
	cout << "\nThe cost of the paint: $" << paint_price_total;
	cout << "\nThe labor charges: $" << labour_charges;
	cout << "\nThe total cost of the paint job: $" << job_total_cost;

	cout << endl << endl;

}
