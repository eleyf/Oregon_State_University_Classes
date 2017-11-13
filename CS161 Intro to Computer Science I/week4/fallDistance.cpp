/*****************************************************************
**
**	Author: Frederick Eley
**	ONID:	eleyf
**	Date:	1/24/16
**	Description:  CS161 400 W2016
**				  Assignment 4.a
**			This project only contains the definition of a
**			function that determines the distance an object
**			has fallen due to gravity in a specific time
**			period.
**			
*****************************************************************/


/*****************************************************************
**
**	This function calculates and returns the distance
**	an object has fallen due to gravity in a specific time period.
**	It receives the time in seconds as a parameter.
**
******************************************************************/

double fallDistance(double timeInSeconds)
{
	double distance;

	distance = .5 * 9.8 * timeInSeconds * timeInSeconds;

	return distance;

}
