//8. List Template
//
//Create a list class template based on the list class you created in the previous programming challenges.

#include "Numberlist.h"

int main() {

	cout << "==========================\n";
	cout << "18-08 LIST TEMPLATE DRIVER\n";
	cout << "==========================\n";
	cout << "\n";

	NumberList<int> list_int;
	list_int.insertNode(5);
	list_int.insertNode(3);
	list_int.insertNode(4);
	list_int.insertNode(2);
	list_int.insertNode(0);

	NumberList<double> list_double;
	list_double.insertNode(1.4);
	list_double.insertNode(1.234);
	list_double.insertNode(1.5954);
	list_double.insertNode(1.0234238);
	list_double.insertNode(1.22243);

	NumberList<string> list_string;
	list_string.insertNode("natives");
	list_string.insertNode("africa");
	list_string.insertNode("rules");
	list_string.insertNode("life");
	list_string.insertNode("full");
	list_string.insertNode("belly");

	list_int.print("INT LIST");
	list_double.print("DOUBLE LIST");
	list_string.print("STRING LIST");

}