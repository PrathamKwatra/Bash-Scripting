#include <stdio.h>

//Group Members
//Pratham Kwatra (section 3B)
//Isamu Mclean Isozaki
//Adrienne Lhuc Reyes Estrella
//Chris Gautreau

int main()
{
	//reading the inputs
	double rad;
	double height;
	double pi = 3.14159;
	printf( "\nEnter the radius (meters)\n");
	scanf( "%lf", &rad);
	printf( "\nEnter the height (meters)\n");
	scanf( "%lf", &height );
	//calculating the volume 
	double volume; 
	volume = pi*height*rad*rad;
	printf("\nvolume is %.2f\n",volume);

   return 0 ;
}
