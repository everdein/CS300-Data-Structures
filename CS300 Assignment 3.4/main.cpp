// Matthew Clark
// CS300 - Data Structures
// Assignment 3.4 - Reverse Digits

#include <iostream>
using namespace std;

void reverseDigits(int);

// Asks user to enter a number stores it in variable number.
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    reverseDigits(number);
}

// Reverses and prints the number entered by the user.
void reverseDigits(int number){
    cout << number%10;
    if (number > 9) {
        reverseDigits(number/10);
    }
}

