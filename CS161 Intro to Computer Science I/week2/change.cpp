/****************************************************
**
**  Author: Frederick Eley 
**  ONID: eleyf
**  Date: 1/12/16
**  Description: W2016 CS161 400
**		 Assignment 2c
**
**		 This program ask for number of cents
**               and outputs how many of each type
**               of coin.
**
*****************************************************/

#include <iostream>
using namespace std;


int main()
{
    int total,
	numberOfQuarters,
	numberOfDimes,
	numberOfNickels,
	numberOfPennies;


    // Prompt user for amount of change

    cout << "Please enter an amount in cents less than a dollar, ";
    cout << "and press <enter>."; 
    cout << endl;


    // Input amount into variable

    cin  >> total;
    cin.ignore();


    // Calculate number of each type of coin

    numberOfQuarters = total/25;
    total %= 25;

    numberOfDimes = total/10; 
    total %= 10;

    numberOfNickels = total/5;
    total %= 5;

    numberOfPennies = total;


    // Output calculations

    cout << "Your change will be:" << endl;
    cout << "Q: " << numberOfQuarters << endl;
    cout << "D: " << numberOfDimes << endl;
    cout << "N: " << numberOfNickels << endl;
    cout << "A: " << numberOfPennies << endl;


return 0;
}
