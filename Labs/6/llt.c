//Lab 6
//Question 2.5
//Pratham Kwatra

#include <stdio.h>
#include <stdlib.h>

int star(int stars)
{
	int x_num=0, num=1;
	for (num=stars; num > 0; num--)
	{
		for (x_num=num; x_num > 0; x_num--)
		{
			printf( "*" );
		}
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
	star(givenNumber);
//	while ( givenNumber > 0) 
//	{
//		star(givenNumber);
//		printf ("Enter a number (0 to exit)--> ");
//		getline ( &buff, &len, stdin );
//		sscanf ( buff, "%d", &givenNumber );
//	}
	free ( buff );
	return 0 ;
}



