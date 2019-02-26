// Matthew Clark
// CS300 - Data Structures
// Assignment 3.3 - Large Addition

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    // creating stacks
    LinkedStack<int> linkedStack1;
    LinkedStack<int> linkedStack2;
    LinkedStack<int> linkedStack3;

    // creating input strings
    string firstLargeNumber;
    string secondLargeNumber;

    // getting input strings
    cout << "Enter a very large number: ";
    cin >> firstLargeNumber;
    cout << "Enter a very large number: ";
    cin >> secondLargeNumber;

    // comparing size of strings and adding extra 0's
    if (firstLargeNumber.length() > secondLargeNumber.length())
    {
        int difference;
        for (difference = 0; difference < firstLargeNumber.length() - secondLargeNumber.length(); difference++)
        {
        }
        for (int i = 0; i < difference; i++)
        {
            int z = 0;
            linkedStack2.push(z);
        }
    	}
    else if (secondLargeNumber.length() > firstLargeNumber.length())
    	{
        int difference;
        for (difference = 0; difference < secondLargeNumber.length() - firstLargeNumber.length(); difference++)
        {
        }
        for (int i = 0; i < difference; i++)
        {
            int z = 0;
            linkedStack1.push(z);
        }
    }

    // putting strings into linkedstacks
    int t;
    for (int i = 0; i < firstLargeNumber.length(); i++)
    {
        t = firstLargeNumber[i] - 48;
        linkedStack1.push(t);
    }
    for (int i = 0; i < secondLargeNumber.length(); i++)
    {
        t = secondLargeNumber[i] - 48;
        linkedStack2.push(t);
    }

    // doing math wizardry
    // temp carries the 1
    int temp;
    int sum;
    while (!linkedStack1.isEmpty() && !linkedStack2.isEmpty())
    {
        if (temp > 0)
        {
            sum = temp;
        }
        else
        {
            sum = 0;
        }
        temp = 0;
        // always adds sum- if a 1 was carried sum = 1, otherwise it defaults to 0
        sum = linkedStack1.pop() + linkedStack2.pop() + sum;
        if (sum > 9)
        {
            temp = 1;
            sum = sum - 10;
        }
        linkedStack3.push(sum);
        // to carry last 1 (so case 500+500=000 instead of 500+500=1000)
        if(linkedStack1.isEmpty() && linkedStack2.isEmpty() && temp > 0)
        {
            linkedStack3.push(temp);
        }
    }

    // printing out sum
    // lots of spaces to align numbers
    cout << "Sum is:                    ";
    while (!linkedStack3.isEmpty())
    {
        cout << linkedStack3.pop();
    }

    return 0;
}
