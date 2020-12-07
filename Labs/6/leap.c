/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int leap_yes(int year)
{
	if (year%100 == 0)
	{ 
		if (year%400 == 0) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	else	
	{
		if (year%4 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}


int main()
{
	char *buff = NULL ;
	size_t len ;
	int leap;
	printf ("Please enter a year --> ");
	while ( getline( &buff, &len, stdin ) > 1 )
	{
		sscanf( buff, "%d", &leap);
	 	leap_yes(leap);
		printf ("Please enter a year --> ");
	}

	return 0;
}
