// Matthew Clark
// CS300 - Data Structures
// Assignment 3.1 & 3.2 - Barbershop

#ifndef CUSTOMER_CPP_
#define CUSTOMER_CPP_

#include <iostream>
#include "Customer.h"
using namespace std;

// Handles customers first and last name.
Customer::Customer(string firstName, string lastName)
{
	this->firstName = firstName;
	this->lastName = lastName;
}

// Gets customers first and last name.
string Customer::getName()
{
	return firstName + " " + lastName;
}

#endif /* CUSTOMER_CPP_ */
