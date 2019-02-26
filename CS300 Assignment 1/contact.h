// Matthew Clark
// CS300 - Data Structures
// Assignment 1 - Phonebook

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
using namespace std;

class contact
{
public:
	string getFirstName() const {
		return firstName;
	}

	void setFirstName(string firstName) {
		this->firstName = firstName;
	}

	string getLastName() const {
		return lastName;
	}

	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	int getPhoneNumber() const {
		return phoneNumber;
	}

	void setPhoneNumber(int phoneNumber) {
		this->phoneNumber = phoneNumber;
	}

	// Friend function overloaded to print first name, last name and phone number.
	friend ostream& operator<<(ostream& os, contact& c){
		os << c.getFirstName() << " " << c.getLastName() << " " << c.getPhoneNumber() << endl;
		return os;
	}

private:
	string firstName;
	string lastName;
	int phoneNumber;

};



#endif /* CONTACT_H_ */
