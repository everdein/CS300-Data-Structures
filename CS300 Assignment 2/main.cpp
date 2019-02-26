// Matthew Clark
// CS300 - Data Structures
// Assignment 2 - Flight Manifest

#include <iostream>
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"
using namespace std;

// Creates four linked list manifests to hold rider information.
OrderedLinkedList<Passenger> manifest100;
OrderedLinkedList<Passenger> manifest200;
OrderedLinkedList<Passenger> manifest300;
OrderedLinkedList<Passenger> manifest400;

// Creates object rider from Passenger.h file.
Passenger rider;

// Initializes methods outside of main.
void menuOperations();
string requestLastName();
string requestFirstName();
string requestAddress();
int requestPhoneNumber();
int requestFlightNumber();
void printManifest(int flightNumber);
void addRider(string firstName, string lastName, string address, int phoneNumber, int flightNumber);
void searchRider(string firstName, string lastName);
void deleteRider(string firstName, string lastName, int flightNumber);

// Main method calls the menu function.
int main()
{
	menuOperations();
	return 0;
}

// Executes add, search, delete, list and quit.
void menuOperations()
{
	// Declares variables.
	string firstName;
	string lastName;
	string address;
	int phoneNumber;
	int flightNumber;
	string decision;

	// While loop execute menuOperations.
	do {
		cout << "NASA SPACE MISSIONS" << endl;
		cout << "PLEASE CHOOSE AN OPERATION:" << endl;
		cout << "A(ADD) | S(SEARCH) | D(DELETE) | L(LIST) | Q(QUIT):" << endl;
		cin >> decision;
		transform(decision.begin(), decision.end(), decision.begin(), ::toupper);

		// Adds a rider to the manifest.
		if(decision == "A")
		{
			flightNumber = requestFlightNumber();
			firstName = requestFirstName();
			lastName = requestLastName();
			address = requestAddress();
			phoneNumber = requestPhoneNumber();
			addRider(firstName, lastName, address, phoneNumber, flightNumber);
		}

		//Searches for a rider on the manifest.
		if(decision == "S")
		{
			firstName = requestFirstName();
			lastName = requestLastName();
			searchRider(firstName, lastName);
		}

		// Deletes a contact from the manifest.
		if(decision == "D")
		{
			flightNumber = requestFlightNumber();
			firstName = requestFirstName();
			lastName = requestLastName();
			deleteRider(firstName, lastName, flightNumber);
		}

		// Lists all riders on the manifest.
		if(decision == "L")
		{
			flightNumber = requestFlightNumber();
			printManifest(flightNumber);
		}
		else
		{
			cout << "" << endl;
		}
	} while(decision != "Q");
}

// Requests riders flight number.
int requestFlightNumber()
{
	int flightNumber;
	cout << "ENTER FLIGHT NO#: (100, 200, 300 OR 400)" << endl;
	cin >> flightNumber;
	return flightNumber;
}

// Requests riders first name.
string requestFirstName() {
	string firstName;
	cout << "ENTER FIRST NAME:" << endl;
	cin >> firstName;
	transform(firstName.begin(), firstName.end(), firstName.begin(), ::toupper);
	return firstName;
}

// Requests riders last name.
string requestLastName()
{
	string lastName;
	cout<<"ENTER LAST NAME:"<<endl;
	cin >> lastName;
	transform(lastName.begin(), lastName.end(), lastName.begin(), ::toupper);
	return lastName;
}

// Requests riders address.
string requestAddress()
{
	string address;
	cout << "ENTER ADDRESS:" << endl;
	cin.ignore(INT_MAX, '\n');
	getline(cin,address);
	transform(address.begin(), address.end(), address.begin(), ::toupper);
	return address;
}

// Requests riders phone number.
int requestPhoneNumber()
{
	int phoneNumber;
	cout<<"ENTER PHONE NO#:"<<endl;
	cin>>phoneNumber;
	return phoneNumber;
}

// Prints the manifest.
void printManifest(int flightNumber)
{
	if(flightNumber == 100)
	{
		cout << manifest100;
		cout << "FLIGHT 100 - MANIFEST:" << endl << endl;
	}

	else if(flightNumber == 200)
	{
		cout << manifest200;
		cout << "FLIGHT 200 - MANIFEST:" << endl << endl;
	}

	else if(flightNumber == 300)
	{
		cout << manifest300 << endl;
		cout << "FLIGHT 300 - MANIFEST:" << endl << endl;
	}

	else if(flightNumber == 400)
	{
		cout << manifest400;
		cout << "FLIGHT 400 - MANIFEST:" << endl << endl;
	}
	else
	{
		cout << "THE FLIGHT NO# ENTERED DOESN'T EXIST, PLEASE TRY AGAIN." << endl << endl;
	}
}

// Adds rider last name, first name, address and phone number to the manifest.
void addRider(string lastName, string firstName, string address, int phoneNumber, int flightNumber)
{
	rider.setFirstName(firstName);
	rider.setLastName(lastName);
	rider.setAddress(address);
	rider.setPhoneNumber(phoneNumber);

	if(flightNumber == 100)
	{
		manifest100.insertAlphabetically(rider);
	}

	else if(flightNumber == 200)
	{
		manifest200.insertAlphabetically(rider);
	}

	else if(flightNumber == 300)
	{
		manifest300.insertAlphabetically(rider);
	}

	else if(flightNumber == 400)
	{
		manifest400.insertAlphabetically(rider);
	}
	else
	{
		cout << "FLIGHT NO# NOT VALID, PLEASE TRY AGAIN." << endl;
	}
}

void searchRider(string lastName, string firstName)
{
	rider.setFirstName(firstName);
	rider.setLastName(lastName);

	if(manifest100.search(rider)){
		cout << "FOUND ON FLIGHT MANIFEST 100." << endl;
	}
	else if(manifest200.search(rider)){
		cout << "FOUND ON FLIGHT MANIFEST 200." << endl;
	}
	else if(manifest300.search(rider)){
		cout << "FOUND ON FLIGHT MANIFEST 300." << endl;
	}
	else if(manifest400.search(rider)){
		cout << "FOUND ON FLIGHT MANIFEST 400." << endl;
	}
	else{
		cout << "PASSENGER NOT FOUND." << endl;
	}
}

void deleteRider(string lastName, string firstName, int flightNumber)
{
	rider.setFirstName(firstName);
	rider.setLastName(lastName);

	if(flightNumber == 100)
	{
		manifest100.deleteNode(rider);
	}

	else if(flightNumber == 200)
	{
		manifest200.deleteNode(rider);
	}

	else if(flightNumber == 300)
	{
		manifest300.deleteNode(rider);
	}

	else if(flightNumber == 400)
	{
		manifest400.deleteNode(rider);
	}
	else
	{
		cout << "FLIGHT NO# NOT VALID, PLEASE TRY AGAIN." << endl;
	}
}
