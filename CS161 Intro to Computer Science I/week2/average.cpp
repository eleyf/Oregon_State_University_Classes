/**************************************************
**
**  Author: Frederick Eley
**  ONID: eleyf
**  Date: 1/12/16
**  Description: CS191 400 Week 2 Assignment 2a
**              
**               This program asks the user for
**               5 numbers and prints out the
**               average.
**
*************************************************/


#include <iostream>
#include <iomanip>
using namespace std;


int main()
{

    double number1,
	   number2,
	   number3,
	   number4,
	   number5,
	   averageOfNumbers;


    // Prompting user for input

    cout << "Please enter 5 numbers, press enter after each:"; 
    cout << endl;


    // Inputting user numbers into variables

    cin  >> number1;
    cin.ignore();

    cin  >> number2;
    cin.ignore();

    cin  >> number3;
    cin.ignore();

    cin  >> number4;
    cin.ignore();

    cin  >> number5;
    cin.ignore();


    // Calculating average of all 5 numbers

    averageOfNumbers = (number1 + number2 + number3 + number4 + number5)/5;


    // Outputting calculation

    cout << "The average of those numbers is:" << endl;
    cout << averageOfNumbers << endl;

 
return 0;

}
