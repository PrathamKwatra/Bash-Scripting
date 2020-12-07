
#include <stdio.h>

void mySc( char t[], char s[] )
{
	int i = -1 ;
	do {
		i += 1 ;
		t[i] = s[i] ;
	} while( s[i] != '\0' ) ;
}

int main( void )
{
	char first[20] = "Jadwiga" ;
	char other[20] = "Kurt" ;

	mySc( first, other ) ;

	printf( "After copy, first is: %s\n", first ) ;

	return 0 ;
}
