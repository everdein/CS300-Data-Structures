// Matthew Clark
// CS300 - Data Structures
// Assignment 4 - Phonebook & Performance Comparison

#include <iostream>
#include "Contact.h"
using namespace std;

Contact::Contact(string firstName, string lastName, string phoneNumber)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
}

string Contact::getName()
{
	return firstName + " " + lastName;
}

string Contact::getInfo()
{
	return firstName + " " + lastName + " " + phoneNumber;
}
