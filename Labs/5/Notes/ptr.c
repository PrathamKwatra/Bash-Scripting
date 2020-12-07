#include <stdio.h>

int main( int argc, char* argv[] )
{
	int i = 12 ;

	int *ip = &i ;

	printf( "The size of a pointer is %lu\n", sizeof( ip )) ;

	return( 0 ) ;
}
