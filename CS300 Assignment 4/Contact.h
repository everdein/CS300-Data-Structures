// Matthew Clark
// CS300 - Data Structures
// Assignment 4 - Phonebook & Performance Comparison

#ifndef CONTACT_H_
#define CONTACT_H_

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

class Contact
{
public:
	Contact(){};
	Contact(string, string, string);
	string getName();
	string getInfo();

	string getPhoneNumber() const {
		return phoneNumber;
	}

	void setPhoneNumber(int phoneNumber) {
		this->phoneNumber = phoneNumber;
	}

	// Friend function overloaded to print first name, last name and phone number.
	friend ostream& operator<<(ostream& os, Contact& c){
		os << c.getInfo() << endl;
		return os;
	}

	friend bool operator>(Contact& p1, Contact& p2)
	{
		if(p1.getName() > p2.getName())
		{
			return true;
		}
		return false;
	}

	friend bool operator<(Contact& p1, Contact& p2)
	{
		if(p1.getName() < p2.getName())
		{
			return true;
		}
		return false;
	}

	friend bool operator==(Contact& p1, Contact& p2)
	{
		if(p1.getName() == p2.getName())
		{
			return true;
		}
		return false;
	}

	friend bool operator<=(Contact& p1, Contact& p2)
	{
		if(p1.getName() <= p2.getName())
		{
			return true;
		}
		return false;
	}

	friend bool operator!=(Contact& p1, Contact& p2)
	{
		if(p1.getName() != p2.getName())
		{
			return true;
		}
		return false;
	}

private:
	string firstName;
	string lastName;
	string phoneNumber;
};



#endif /* CONTACT_H_ */
