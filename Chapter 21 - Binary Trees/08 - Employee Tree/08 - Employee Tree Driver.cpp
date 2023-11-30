//8. Employee Tree
//
//Design an EmployeeInfo class that holds the following employee information:
//
//Employee ID Number : an integer
//Employye Name : a string
//
//Next, use the template you designed in Porgramming Challenge 1 (Binary Tree Template) to implement
//a binary tree whose nodes hold an instance of the EmployeeInfo class.The nodes should be sorted
//on the Employee ID number.
//
//Test the binary tree by inserting nodes with the following information.
//
//Employee ID Number			Name
//----------------------------------------------------
//1021						John Williams
//1057						Bill Witherspoon
//2487						Jennifer Twain
//3769						Sophia Lancsater
//1017						Debbie Reece
//1275						George McMullen
//1899						Ashley Smith
//4218						Josh Plemmons
//----------------------------------------------------
//
//Your program should allow the user to enter an ID number, then search the tree for the number.If
//the number is found, it should display the employee's name. If the node is not found, it should 
//display a message indicating so.

#include "EmployeeTree.h";

int main() {

	cout << "==========================\n";
	cout << "21-08 EMPLOYEE TREE DRIVER\n";
	cout << "==========================\n";
	cout << "\n";

	EmployeeTree<EmployeeInfo> tree;
	EmployeeInfo worker_1(832, "Morson Schapiro");
	EmployeeInfo worker_2(9324, "Akala");
	EmployeeInfo worker_3(86, "PLO Lumumba");
	EmployeeInfo worker_4(103, "Cheik Anta Diop");

	cout << "Worker #1: " << worker_1 << "\n";
	cout << "Worker #2: " << worker_2 << "\n";
	cout << "Worker #3: " << worker_3 << "\n";
	cout << "Worker #4: " << worker_4 << "\n";
	cout << "\n";

	EmployeeInfo worker_5;
	cin >> worker_5;

	tree.insert(worker_3);
	tree.insert(worker_1);
	tree.insert(worker_5);
	tree.insert(worker_4);
	tree.insert(worker_2);
	
	tree.search();

	tree.remove(103);

	tree.displayInOrder();

	cout << "Ending the program...\n";

}