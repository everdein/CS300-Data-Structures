// Matthew Clark
// CS300 - Data Structures
// Assignment 3.1 & 3.2 - Barbershop

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
using namespace std;

// Gets customer name.
class Customer
{
	string firstName;
	string lastName;

	public:
		Customer(){}
		Customer(string = "", string = "");
		string getName();
};

#endif /* CUSTOMER_H_ */
