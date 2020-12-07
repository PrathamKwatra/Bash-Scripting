/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *buff = NULL ;
	size_t len ;
	int i=0, cnt = 0 ;
	double sum=0, mean=0, stand=0; 
	float temp_float=0;
	float array[100];

	while( getline( &buff, &len, stdin ) > 1 )
	{
		sscanf( buff, "%f", &temp_float);
		array[cnt] = temp_float;
		cnt++;
	}

	printf( "\nEnd of input detected.  I read %d numbers.\n", cnt ) ;
	for (i=0; i < cnt; i++)
		mean += array[i];
	mean = mean/cnt; 
	for (i=0; i < cnt; i++)
		sum += ( (array[i] - mean) * (array[i] - mean) );
	sum = sum /cnt;
	stand = sqrt(sum) ; 

	printf("\nMean: %.2lf \t\t Standard Deviation: %.2lf\n", mean, stand);
	free( buff ) ;
	return 0 ;
}
