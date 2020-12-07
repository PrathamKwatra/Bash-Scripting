#include <stdio.h>
#include <stdlib.h>

//Pratham Kwatra (section 3B)
//6act.c
int star(int stars) 
{
	int x_num=0, num=1;
	//printf( "%d %d %d", stars, x_num, num);
	for (num=1; num <= stars; ++num)
	{
		for (x_num=num; x_num > 0; x_num--)
		{
			printf( "*" );
		}
		printf("\n");
	}
}

int rev_star(int stars)
{
	int space=stars, num=1, i , j;
	for (num=1; num <= stars; ++num)
	{
		for (i=space; i > 0; i-- )
			printf(" ");
		for (j=num; j > 0; j--)
			printf("*");
		space -= 1;
		printf("\n");
	}
}

int main()
{
	char *buff = NULL ;
	size_t len = 0 , i = 0 ;
	int givenNumber;
	printf ("Enter a number --> ");
	getline ( &buff, &len, stdin );
	sscanf ( buff, "%d", &givenNumber );
	//star(givenNumber);
	while ( givenNumber > 0) 
	{
		rev_star(givenNumber);
		printf ("Enter a number --> ");
		getline ( &buff, &len, stdin );
		sscanf ( buff, "%d", &givenNumber );
	}
	free ( buff );
	return 0 ;
}


