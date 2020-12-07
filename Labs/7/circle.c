/*********************************************************
 * circle.c - calculates the area
  *
   *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//returns the area in double 
//I couldn't figure out how to get the defualt value of M_PI from math.h
double circleArea(double rad)
{
	double PI = 4 * atan( 1 );
	double area;
	area = rad*rad*PI;
	return area;
}

int main(int argc, char *argv[] )
{
	char *str;
	double rad;
	//Argument Check
	if ( !(argc > 2) )
	{
		fprintf(stderr, "Need 2 arguments, a name and a radius.\n");
		return 1;
	}
	
	//converting arg2 into a double
	rad = strtod(argv[2], &str);
	//printing the result
	printf("%s, your area is %.3e units square\n", argv[1], circleArea(rad));
	return 0;
}

