#include <stdio.h>
#include <stdlib.h>
//Pratham Kwatra (section 3B)
//sscanf.c

int main() {
	char *buff = NULL ;
	size_t len = 0 , i = 0 ;
	int age ;
	double loc ;
	char first[10], last[20] ;
	printf( "Enter your name (first last) => " ) ;
	getline( &buff, &len, stdin ) ;
	sscanf( buff, "%s %s", first, last ) ; //////////////
	printf( "%s, enter your age => ", first ) ;
	getline( &buff, &len, stdin ) ;
	sscanf( buff, "%d", &age ) ; //////////////
	printf( "%s, enter a float => ", first ) ;
	getline( &buff, &len, stdin ) ;
	sscanf( buff, "%lf", &loc ) ; //////////////
	printf( "\n%s, you are %d, located at %.2f .\n\n", first, age, loc ) ;
	free( buff ) ; // Give back memory getline borrowed
	return 0 ;
}

