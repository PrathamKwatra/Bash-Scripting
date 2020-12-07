/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {
	  int i=5, j=12, k=-13, z=0;
	    int array[9] = {j < i, ! j < i , (! j) < i , i + j , !i + j , !!i + !j , j && k , i && j || z, i && ( j || z ) };
		 for(int i = 0; i<9; i++) 
				{ 
							if(array[i]) {
											puts("T"); 
											     //printf("%d\n",array[i]);
												  		} else {
																		puts("F"); 
																		      //printf("%d\n", array[i]);
																				    }
																					   } 
																						  return 0;
}
