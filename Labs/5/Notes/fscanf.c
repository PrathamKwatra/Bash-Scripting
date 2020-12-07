#include <stdio.h>
#include <string.h>

int main( int argc, char **argv )
{
	int theInt ;
	double theDouble ;
	char buff[20] ;  /* hold each word */

	fscanf( stdin, "%x %lf", &theInt, &theDouble ) ;
	printf( "got int: %d and double: %.2f\n", theInt, theDouble ) ;

	while( fscanf( stdin, "%19s", buff ) > 0 ) {
		printf( "word: %s\n", buff ) ;
	}
	
	return( 0 ) ;
}
