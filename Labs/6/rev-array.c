/*********************************************************
 * rev-array.c - reads and reverse
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *buff = NULL ;
	size_t len ;
	int i=0, cnt=0, rev_cnt=0;
	double temp_doub=0;
	double array[100];
	double rev_array[100];

	while( getline( &buff, &len, stdin ) > 1 )
	{
		sscanf( buff, "%lf", &temp_doub);
		array[cnt] = temp_doub;
		cnt++;
	}

	printf( "\nEnd of input detected.  I read %d numbers.\n", cnt ) ;

	for (i=cnt, rev_cnt=0; i > 0 && rev_cnt < 100; --i, rev_cnt++)
	{
		rev_array[rev_cnt] = array[i-1];
	//	printf ("\n%lf \t\t %lf\n", rev_array[rev_cnt], array[i-1]);
	}

	free( buff ) ;
	return 0 ;
}
