// Matthew Clark
// CS300 - Data Structures
// Assignment 3.1 & 3.2 - Barbershop

#ifndef BARBERSHOP_H_
#define BARBERSHOP_H_

#include <iostream>
#include "LinkedStack.h"
#include "Customer.h"

// Creates two linked stacks.
using namespace std;
class BarberShop
{
	LinkedStack<Customer> s1;
	LinkedStack<Customer> s2;

	public:
		void addCustomer(Customer&);
		Customer nextCustomer();
};

#endif /* BARBERSHOP_H_ */
