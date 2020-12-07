#include <stdio.h>
#include <stdlib.h>

//Pratham Kwatra (section 3B)
//bill.c
int dollar_dist(int x) 
{
	int ten_x, five_x, one_x;
	printf("$20 bills: %4d\n", x/20);
	ten_x = x%20;
	printf("$10 bills: %4d\n", ten_x/10);
	five_x = ten_x%10;
	printf("$ 5 bills: %4d\n", five_x/5);
	one_x = five_x%5;
	printf("$ 1 bills: %4d\n", one_x);
	return 0;
	}


int main()
{
	char *buff = NULL ;
	size_t len = 0 , i = 0 ;
	int dollar;

	printf ("Enter a dollar Amount --> ");
	getline ( &buff, &len, stdin );
	sscanf ( buff, "%d", &dollar );
	dollar_dist(dollar);
	free ( buff );
	return 0 ;
}


