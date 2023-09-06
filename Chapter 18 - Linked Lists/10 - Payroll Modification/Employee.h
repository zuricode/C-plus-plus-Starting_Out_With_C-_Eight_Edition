#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class ListNode {

public:
	int empId; 
	int hours;
	double payRate;
	double wages;
	ListNode* next;

	ListNode() { empID = 0; hours = 0; payRate = 0.0; wages = 0.0; next = nullptr; }

};

class Employee