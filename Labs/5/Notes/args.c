/* args.c  -- Iterating over cmd-line arguments in C
 *
 * Kurt Schmidt
 * OCT 2019
 *
 * tcc version 0.9.27 (x86_64 Linux)
 *
 * EDITOR:  tabstop=2, cols=120
 *
 */

#include <stdio.h>

int main( int argc, char **argv )
{
	int i ;

	printf( "\nHello, folks.  Here are the args:\n" ) ;

	for( i=0; i<argc; ++i )
		printf( "  %2d  %s\n", i, argv[i] ) ;
	
	return( 0 ) ;
}
