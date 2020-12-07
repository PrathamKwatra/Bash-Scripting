#include <stdio.h>

int main( int argc, char **argv )
{
	FILE *fp = NULL ;
	char *buff = NULL ;
	size_t len = 0 ;

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

	while( getline( &buff, &len, fp ) != -1 )
	{
		buff[ strlen( buff )-1 ] = '\0' ;
		printf( "%lu chars at %p: %s\n", len, buff, buff ) ;
	}
	
	return( 0 ) ;
}
