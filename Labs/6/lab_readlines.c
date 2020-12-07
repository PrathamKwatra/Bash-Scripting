/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *buff = NULL ;
	size_t len ;
	int i=0, cnt = 1 ;
	double sum=0, mean=0, stand=0; 
	float temp_float=0, max =0, min=0;
	
	printf("Please Enter a number --> ");
	getline(&buff, &len, stdin);
	sscanf(buff, "%f", &temp_float);
	sum = temp_float;
	max = temp_float;
	min = temp_float;
	printf("Please Enter a number --> ");

	while( getline( &buff, &len, stdin ) > 1 )
	{
		sscanf( buff, "%f", &temp_float);
		sum += temp_float;
		cnt++;
		if ( temp_float < min )
			min = temp_float;
		if ( temp_float > max )
			max = temp_float;
		printf("Please Enter a number --> ");
	}

	printf( "\nEnd of input detected.  I read %d numbers.\n", cnt ) ;
	mean = sum/cnt; 
	
	printf("\nMean: %.2lf \t\t Max: %.2lf \t\t Min: %.2lf\n", mean, max, min);
	free( buff ) ;
	return 0 ;
}
