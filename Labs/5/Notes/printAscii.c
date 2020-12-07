#include <stdio.h>

int main( int argc, char *argv[] ) {
	int c;

	for( c=(int)'S' ; c<=(int)'k'; ++c ) {
		printf( "ASCII value = %3d,"
			"Character = %c\n", c , (char)c );
	}

	return(0);
}
