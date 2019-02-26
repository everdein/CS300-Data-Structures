// Matthew Clark
// CS300 - Data Structures
// Assignment 2 - Flight Manifest

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
using namespace std;

class Passenger
{
	public:
		const string& getAddress() const
		{
			return address;
		}

		void setAddress(const string& address)
		{
			this->address = address;
		}

		const string& getFirstName() const {
			return firstName;
		}

		void setFirstName(const string& firstName)
		{
			this->firstName = firstName;
		}

		const string& getLastName() const
		{
			return lastName;
		}

		void setLastName(const string& lastName)
		{
			this->lastName = lastName;
		}

		int getPhoneNumber() const
		{
			return phoneNumber;
		}

		void setPhoneNumber(int phoneNumber)
		{
			this->phoneNumber = phoneNumber;
		}

		friend ostream& operator<<(ostream& os, Passenger& p)
		{
			os << p.getLastName() << " " << p.getFirstName() << " " << p.getAddress() << " " << p.getPhoneNumber() << endl;
			return os;
		}

		friend bool operator==(Passenger& p1, Passenger& p2){
			if(p1.getFirstName()==p2.getFirstName() && p1.getLastName()==p2.getLastName())
			{
				return true;
			}
			return false;
		}

		friend bool operator!=(Passenger& p1, Passenger& p2)
				{
			if(p1.getFirstName()!=p2.getFirstName() && p1.getLastName()!=p2.getLastName())
			{
				return true;
			}
			return false;
		}

		friend bool operator>(Passenger& p1, Passenger& p2)
		{
			if(p1.getLastName()>p2.getLastName())
			{
				return true;
			}
			return false;
		}

		friend bool operator<(Passenger& p1, Passenger& p2)
		{
			if(p1.getLastName()<p2.getLastName())
			{
				return true;
			}
			return false;
		}
	private:
		string firstName;
		string lastName;
		string address;
		int phoneNumber;
};

#endif /* PASSENGER_H_ */
