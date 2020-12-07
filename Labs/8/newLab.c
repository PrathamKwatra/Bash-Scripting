/**********************************************************************************
 * readPeople.c - Reads people (max 100), fills in array
 *
 * NOTES:
 *  - Input is:
 *    last
 *    first
 *    age
 *   , no blank lines.
 *	- Assume that input is valid (if you find a last name, then there are 2 more lines)
 *  - Input is terminated w/a blank line or EOF
 * 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char first[10] ;
	char last[20] ;
	int age ;
} person ;

	// reads people from file handle f, format described above
	// a must be large enough to hold all entries
void readPeople( person a[], FILE* f ) ;

	// Returns heap memory pointed to by elements of a
	// a is of size n
	// Elements point to a person, or are NULL
void freePeople( person* a, size_t n ) ;

int main( int argc, char **argv )
{
	FILE *fin = stdin ;

	person* team[100] = { NULL } ; /* rest are initialised to 0 */

	if( argc>1 ) {
		fin = fopen( argv[1], "r" ) ;
		if( fin == NULL ) {
			fprintf( stderr, "Couldn't open %s for reading.  Exiting. ", argv[1] )
			exit( 1 ) ;
		}
	}

	readPeople( team ) ;

	freePeople( team ) ;
	free( buff ) ;

	return 0 ;
}

void strcopy(char *first, char *second)
{
	int i ,cnt = 0;
	for (i = 0; *(first +i) != '\0'; ++i) 
	{
		*(second + i) = *(first + i);
		cnt++;
	}
	*(second + cnt) = '\0';

}

void readPeople( person* a[], FILE* f ) 
{
	char *buff = NULL ;
	size_t len ;
	size_t cnt = 0 ;

	while( getline( &buff, &len, f ) > 1 ) 
	{
		// We read a last name (with the newline)
		// - get memory for person
		// - append to array
		// - read next 2 lines, fill it in 
		a[cnt] = (*person) malloc (sizeof(person));
		strcpy(a[cnt]->last, buff);
		getline( &buff, &len, f );
		strcpy(a[cnt]->first, buff);
		getline( &buff, &len, f );
		a[cnt]->age = buff - '0';
		++cnt ;
	}
}

void freePeople( person* a, size_t n ) 
{
	// Do NOT assume array is dense.  Check every element
}

