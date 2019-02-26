// Matthew Clark
// CS300 - Data Structures
// Assignment 1 - Phonebook

#include "contact.h"
#include <iostream>
#include <fstream>
using namespace std;

// Creates a phone book array with 200,000 indexes.
contact *phonebook = new contact[200000];

// The main function.
int main() {

	// Initializes variables.
	string firstName;
	string lastName;
	int phoneNumber;

	// Initializes file.
	string filename;
	filename = "phonebook.txt";
	ifstream file;
	file.open(filename);

	// Uploads the phonebook.txt file into the phone book array.
	// Each index holds the first name, last name and phone number of a contact.
	int index = 0;
	while(!file.eof()){
		file >> firstName >> lastName >> phoneNumber;
		phonebook[index].setFirstName(firstName);
		phonebook[index].setLastName(lastName);
		phonebook[index].setPhoneNumber(phoneNumber);
		index++;
	}

	// Asks the user what operations to perform.
	cout<<"Please choose an operation:"<<endl;
	cout<<"A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit):"<<endl;
	string decision;
	cin >> decision;
	transform(decision.begin(), decision.end(), decision.begin(), ::toupper); // Converts the users input to all caps.

	do{
		// Adds a contact to the end of the phone book array.
		if(decision == "A"){
			// Accepts users input for first name.
			string firstName;
			cout<<"Enter First Name:"<<endl;
			cin>>firstName;
			transform(firstName.begin(), firstName.end(), firstName.begin(), ::toupper); // Converts the users input to all caps.

			// Accepts users input for last name.
			string lastName;
			cout<<"Enter Last Name:"<<endl;
			cin>>lastName;
			transform(lastName.begin(), lastName.end(), lastName.begin(), ::toupper); // Converts the users input to all caps.

			// Accepts users input for phone number.
			int phoneNumber;
			cout<<"Enter Phone Number:"<<endl;
			cin>>phoneNumber;

			// Sets first name, last name and phone number to the first unused index of the phone book array.
			phonebook[index].setFirstName(firstName);
			phonebook[index].setLastName(lastName);
			phonebook[index].setPhoneNumber(phoneNumber);

			// Prints the phone book array.
			for(int i = 0; i < index + 1; i++){
				cout<<phonebook[i];
			} index++;
		}

		//Searches for a contact in the phone book array.
		if(decision == "S"){

			// Accepts users input for first name to compare against the phone book.
			string firstName;
			cout<<"Enter First Name:"<<endl;
			cin>>firstName;
			transform(firstName.begin(), firstName.end(), firstName.begin(), ::toupper); // Converts the users input to all caps.

			// Accepts users input for last name to compare against the phone book..
//			string lastName;
//			cout<<"Enter Last Name:"<<endl;
//			cin>>lastName;
//			transform(lastName.begin(), lastName.end(), lastName.begin(), ::toupper); // Converts the users input to all caps.

			// Starts clock to time search function.
			clock_t begin = clock();

			// Compares the users input against the phone book array and prints the phone book array.
			for(int j = 0; j < index; j++){
				if(phonebook[j].getFirstName().compare(firstName) == 0 /*&& phonebook[j].getLastName().compare(lastName) == 0*/){
					cout<<phonebook[j];
				}
			}

			// Ends clock to time search function and prints out time.
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << elapsed_secs << endl;
		}

		// Deletes a contact from the phone book array.
		if(decision == "D"){

			// Accepts users input for first name.
			string firstName;
			cout<<"Enter First Name:"<<endl;
			cin>>firstName;
			transform(firstName.begin(), firstName.end(), firstName.begin(), ::toupper); // Converts the users input to all caps.

			// Accepts users input for last name.
			string lastname;
			cout<<"Enter Last Name:"<<endl;
			cin>>lastName;
			transform(lastName.begin(), lastName.end(), lastName.begin(), ::toupper); // Converts the users input to all caps.

			// Initializes phone number variable.
			int phoneNumber;

			for(int i = 0; i < index; i++){
				if(phonebook[i].getFirstName().compare(firstName) == 0 && phonebook[i].getLastName().compare(lastName) == 0){
					phonebook[i].setFirstName(" ");
					phonebook[i].setLastName(" ");
					phonebook[i].setPhoneNumber(0);

					for(int j = i; j < index; j++){
						cout << phonebook[j].getFirstName() << " ";
						cout << phonebook[j].getLastName() << " ";
						cout << phonebook[j].getPhoneNumber() << " " << endl;
						firstName = phonebook[j + 1].getFirstName();
						lastName = phonebook[j + 1].getLastName();
						phoneNumber = phonebook[j + 1].getPhoneNumber();
						phonebook[j].setFirstName(firstName);
						phonebook[j].setLastName(lastName);
						phonebook[j].setPhoneNumber(phoneNumber);
					}
				}
			} index--;

			// Prints phone book array.
			for(int i = 0; i < index; i++){
				cout<<phonebook[i];
			}

		}

		// Lists all users in the phone book.
		if(decision == "L"){

			// Prints the phone book array.
			for(int i = 0; i < index; i++){
				cout<<phonebook[i];
			}
		}

		// Ask the user what operation to perform.
		cout << endl << "Please choose an operation:" << endl;
		cout << "A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit):" << endl;
		cin >> decision;
		transform(decision.begin(), decision.end(), decision.begin(), ::toupper); // Converts the users input to all caps.

	} while(decision != "Q"); // Program quits when the user chooses Q.

	return 0;
}
