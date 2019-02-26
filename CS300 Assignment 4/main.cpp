// Matthew Clark
// CS300 - Data Structures
// Assignment 4 - Phonebook & Performance Comparison

#include "BinarySearchTree.h"
#include "Contact.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

BinarySearchTree<Contact> phoneBook;

int main() {

	// Prompts user with program operations.
	cout << "Please choose an operation:" << endl;
	cout << "A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit):" << endl;
	string decision;
	cin >> decision;
	transform(decision.begin(), decision.end(), decision.begin(), ::toupper); // Converts the users input to all caps.

	// Declares count variable.
	int count = 0;

	do{
		
		// Adds a contact to the end of the phone book.
		if(decision == "A"){
			
			// Accepts users input for first name.
			string name, firstName, lastName, phoneNumber;
			cout << "Enter First and Last Name:" << endl;
			cin.ignore(INT_MAX, '\n');
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), ::toupper); // Converts the users input to all caps.

			// Checks for a space in string name variable.
			int y =0;
			for(int j = 0; j < name.length(); j++)
			{
				if(name[j] == ' ')
				{
					y++;
				}
			}

			// Checks if name formatting is correct.
			if(y != 1)
			{
				cerr << "Please check name formatting.";
			}
			else
			{
				for(int j = 0; j < name.length(); j++)
				{
					if(name[j] == ' ')
					{
						firstName.append(name.substr(0, j));
						lastName.append(name.substr(j + 1, name.length() - 1));
						break;
					}
				}
			}

			// Accepts users input for phone number.
			cout<<"Enter Phone Number:"<<endl;
			cin>>phoneNumber;

			// Sets first name, last name and phone number to the first unused node of the binary search tree.
			Contact person(firstName, lastName, phoneNumber);
			phoneBook.insert(person);
			
			// Counts added and loaded contacts.
			count++;

			// Prints contact count.
			cout << "Phone book has " << count << " contacts." << endl;
		}

		if(decision == "L")
		{
			string firstName, lastName, userInput, phoneNumber;
			cout << "Please enter phone book file name." << endl;
			cin >> userInput;
			string fileName = userInput;
			ifstream file;
			file.open(fileName);
			while(!file.eof())
			{
				file >> firstName >> lastName >> phoneNumber;
				Contact person(firstName, lastName, phoneNumber);
				phoneBook.insert(person);
				
				// Counts loaded contacts.
				count++;
			}
		}

		//Searches for a contact in the binary search tree.
		if(decision == "S"){

			string name, firstName, lastName, phoneNumber = " ";
			cout << "Enter First and Last Name:" << endl;
			cin.ignore(INT_MAX, '\n');
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), ::toupper); // Converts the users input to all caps.

			// Checks for a space in string name variable.
			int y = 0;
			for(int j = 0; j < name.length(); j++)
			{
				if(name[j] == ' ')
				{
					y++;
				}
			}

			// Checks if name formatting is correct.
			if(y != 1)
			{
				cerr << "Please check name formatting.";
			}
			else
			{
				for(int j = 0; j < name.length(); j++)
				{
					if(name[j] == ' ')
					{
						firstName.append(name.substr(0, j));
						lastName.append(name.substr(j + 1, name.length() - 1));
						break;
					}
				}
			}

			// Creates contact object.
			Contact person(firstName, lastName, phoneNumber);

			// Starts clock to time search function.
			/* clock_t begin = clock(); */
			
			// Compares the users input against the phone book.
			phoneBook.treeDataSearch(person);
			
			// Ends clock to time search function and prints out time.
		/*	clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << elapsed_secs << endl; */
		}

		// Prints all contacts in the phone book.
		if(decision == "P"){
			phoneBook.inOrder();

			// Prints contact count.			
			cout << "Phone book has " << count << " contacts." << endl;
		}

		// Prints all ancestor nodes until user input is found.
		if(decision == "F")
		{
			string name, firstName, lastName, phoneNumber = " ";
			cout << "Enter First and Last Name:" << endl;
			cin.ignore(INT_MAX, '\n');
			getline(cin, name);
			transform(name.begin(), name.end(), name.begin(), ::toupper); // Converts the users input to all caps.

			// Checks for a space in string name variable.
			int y =0;
			for(int j = 0; j < name.length(); j++)
			{
				if(name[j] == ' ')
				{
					y++;
				}
			}

			// Checks if name formatting is correct.
			if(y != 1)
			{
				cerr << "Please check name formatting.";
			}
			else
			{
				for(int j = 0; j < name.length(); j++)
				{
					if(name[j] == ' ')
					{
						firstName.append(name.substr(0, j));
						lastName.append(name.substr(j + 1, name.length() - 1));
						break;
					}
				}
			}

			// Creates contact object.
			Contact person(firstName, lastName, phoneNumber);

			// Compares the users input against the phone book and prints the binary search tree.
			phoneBook.treeDataFilter(person);
		}

		// Ask the user what operation to perform.
		cout << endl << "Please choose an operation:" << endl;
		cout << "A(Add) | L(Load) | S(Search) | P(Print) | F(Filter) | Q(Quit):" << endl;
		cin >> decision;
		transform(decision.begin(), decision.end(), decision.begin(), ::toupper); // Converts the users input to all caps.

	} 
	
	// Program quits when the user chooses Q.
	while(decision != "Q");

	return 0;
}