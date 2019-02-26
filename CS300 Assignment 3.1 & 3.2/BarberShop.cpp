// Matthew Clark
// CS300 - Data Structures
// Assignment 3.1 & 3.2 - Barbershop

#include "BarberShop.h"

// Adds customer to linked stack.
void BarberShop::addCustomer(Customer& customer)
{
    if(s1.isEmpty())
    {
        s1.push(customer);
    }
    else
    {
        while(!s1.isEmpty())
        {
            Customer temp = s1.pop();
            s2.push(temp);
        }
        s1.push(customer);
        while(!s2.isEmpty())
        {
            Customer temp = s2.pop();
            s1.push(temp);
        }
    }
}

// Pops current customer and shows next customer in line.
Customer BarberShop::nextCustomer()
{
    if(s1.isEmpty())
    {
        cout << "There are no customers in line!" << endl;
    }
    else
    {
        return s1.pop();
    }
}
