#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
	FILE *fp = NULL ;
	char buff[100] ;

	if( argc > 1 ) 
	{
		fp = fopen( argv[1], "r" ) ;

		if( fp == NULL )
		{
			perror( "Can not open input file for reading.\n" ) ;
			exit( 1 ) ;
		}
	}
	else
		fp = stdin ;

	while( fgets( buff, 100, fp ))
	{
		len =  strlen( buff )-1 
		if( buff[len] == '\n' ;
			buff[ len ] = '\0' ;
		printf( "%lu chars at %p: %s\n", strlen(buff), buff, buff ) ;
	}
	
	return( 0 ) ;
}
