#include <stdio.h>
#include <stdlib.h>
//Pratham Kwatra (section 3B)
//ipay.c
int create_bill(double bill) {
	double tax, tip;
	tax = bill*0.07;
	tip = bill*.22;
	printf("Subtotal\n");
	char fmt[] = "%-12s:  $%2.2lf\n" ;
	printf ( fmt, "\tBill", bill);
	printf ( fmt, "\ttax", tax);
	printf ( fmt, "\t22% tip", tip); 
	printf ( fmt, "\tTotal", bill+tip+tax);

	return 0;
	}


int main(int argc, char *argv[])
{
	char *buff = NULL ;
	size_t len = 0 , i = 0 ;
	double bill;
	if ( argc == 2) {
		sscanf(argv[1], "%lf", &bill);
	}
	else {
		printf ("Please provide an amount --> ");
		getline( &buff, &len, stdin ) ;
		sscanf( buff, "%lf", &bill ) ;
		}
	create_bill(bill);
	return 0 ;
}

