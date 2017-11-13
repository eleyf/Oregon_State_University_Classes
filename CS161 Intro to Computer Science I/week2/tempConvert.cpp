/**************************************************
**
**  Author: Frederick Eley
**  ONID: eleyf
**  Date: 1/12/16
**  Description: W2016 CS161 400 
**		 Assignment 2b
**		 This program converts	
**               Celsius temperatures to 
**               Fahrenheit temperatures.
**
***************************************************/


#include <iostream>
using namespace std;


int main()
{

    double  tempF,
	    tempC;


    // Prompt user for temperature in Celsius

    cout << "Please insert a Celsius temperature and press <enter>.";
    cout << endl;


    // Input value in to variable

    cin  >> tempC;
    cin.ignore();

 
    // Calculate Fahrenheit temperature

    tempF = (9.0/5 * tempC) + 32;


    // Print Fahrenheit temperature

    cout << "The equivalent Fahrenheit temperature is:" << endl;
    cout << tempF;
    cout << endl;

return 0;
}
