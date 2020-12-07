#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Pratham Kwatra (section 3B)
//string_formatting.c
int main()
{
	double pi = 4 * atan( 1 ) ;
	double rt2 = pow( 2.5e6, 1.0/3 ) ;
	double phi = ( 1 + sqrt( 5 )) / 2 ;
	char fmt[] = "%-12s:%9.4f\n" ;
	printf( fmt, "Pi", pi ) ;
	printf( fmt, "2.5e6^(1/3)", rt2 ) ;
	printf( fmt, "Phi", phi ) ;
	return 0 ;
}
