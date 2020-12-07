//Lab 6
//Question 2.6)
//Pratham Kwatra


#include <stdio.h>
#include <stdlib.h>
int rev_star(int stars)
{
	int space=stars, num=1, i , j;
	for (num=stars; num > 0; --num)
	{
		for (i=stars; i <= space; i++ )
			printf(" ");
		for (j=num; j > 0; j--)
			printf("*");
		space += 1;
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
	rev_star(givenNumber);
//	while ( givenNumber > 0) 
//	{
//		rev_star(givenNumber);
//		printf ("Enter a number(Press 0 to exit) --> ");
//		getline ( &buff, &len, stdin );
//		sscanf ( buff, "%d", &givenNumber );
//	}
	free ( buff );
	return 0 ;
}



