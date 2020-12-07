/*#!/usr/bin/tcc -run */
/* int_literals.c  -- Demonstrating octal and hex literals.
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
	short s ;
	int i ;

	i = 023 ;
	printf( "\nGiven i = 023, i is: %d\n", i ) ;

	i = 0x34 ;
	printf( "Given i = 0x34, i is: %d\n", i ) ;

	printf( "\n" ) ;

	s = 23l ;

	return( 0 ) ;
}

