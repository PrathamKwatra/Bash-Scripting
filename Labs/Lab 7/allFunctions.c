#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 int arrFind(int* integers, const size_t n, int target)
 {
    int start, end, mid;

    start = 0;
    end = n -1;
    while (start <= end)
    {
       mid = (start + end) / 2;
       if (*(integers + mid) > target)
          end = mid - 1;
       else
          if ( *(integers + mid) < target )
             start = mid + 1;
       else
          return *(integers+mid);
    }
 }

//function calculates statistics for a double type array. It expects 5 arguments.
 void arrStats(double* doubArray, const size_t N, double *mean, double *max, double *min)
 {
    //initializing variables sum and setting max and min to zero.
    double sum;
    *max = *doubArray; *min = *doubArray;

    //for loop to iterate over the array and calculating max and min.
    for (size_t i=0; i<N; i++)
       {
          sum += *(doubArray+i);
          if ( *max < *(doubArray+i) )
             *max = *(doubArray+i);
          if ( *min > *(doubArray+i) )
             *min = *(doubArray+i);
       }
    //calculating mean
    *mean = sum / (double) N;
 }


 void int2string( int n, char answer[] )
 {
	printf("Value of n: %ld\n", n);
    int len=0, i=n;
    char c;
    while (! (i == 0))
       {
          len++;
          i /= 10;
          //printf("%ld\n", i);
       }
//    //printf("Count: %d\n", len);
//    for (i = len-1; i >= 0; i--)
//    {
//      c = (char) (n%10) + '0';
//       answer[i] = c;
//       n /= 10;
//    }
// }

// void capitalise(char* str)
// {
//   char newString;
//   int cnt=0;
//   while (str[cnt] != '\0')
//   {  
//     if ( isalpha( str[cnt]) && islower( str[cnt] ) ) 
//     {
//       newString = toupper( str[cnt] ); 
//       str[cnt] = newString;
//     }
//     cnt++;
//   }
// }
// int try()
// {
//    double mean, max, min;
//    double randArr[] = {5, 6, 4};
//    //printf ("Binary Search Result : %d\n",    arrFind(randArr, 10, 2));
//    arrStats(randArr, 3, &mean, &max, &min);
//    printf("Mean:\t%lf, Max:\t%lf, Min:\t%lf", mean, max, min);
//    return 0;
// }

// //Binary Search algorithm for finding a target in a given array of integers
// int binSearch(int* integers, const size_t n, int target)
// {
//    //Initializing Parameters
//    int start, end, mid;

//    start = 0;
//    end = n -1;

//    //Loop to check the array for target
//    while (start <= end)
//    {
//       mid = (start + end) / 2;
//       if (*(integers + mid) > target)
//          end = mid - 1;
//       else
//          if ( *(integers + mid) < target )
//             start = mid + 1;
//       else
//          //returns the position of element when target found
//          return mid;
//    }
//    //printf("element not found");
//    //returning the number of elements are //per the instructions.
//    return n;
// }
