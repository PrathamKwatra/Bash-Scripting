/*********************************************************
 * readlines.c - reads until blank line or EOF
 *
 *******************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double arithmeticMean(double arrAvg[], const size_t N)
{
	double sum, mean;
	for (size_t lenArr = 0; lenArr < N; ++lenArr)
		{
		sum += arrAvg[lenArr];
		//printf ("Number: %lf, Sum: %lf\n", arrAvg[lenArr], sum);
		}
	mean = sum / (double) N;
	//printf("Mean (from function) : %lf", mean);
	return mean;
}

int question1onHoldRN() {
	int cnt=0, tempI=0;
	long int i = 12312312312321312;
	char c[100], len;
	while (! (i == 0))
	{
		tempI = i%1000;
		if (tempI > 127)
			tempI = i%100;
		printf ("value of i: %d\n", tempI);
		len = tempI + '0';
		c[cnt] = len;
		printf ("value of c: %c \n", len);
		i /= 10;
		cnt ++;
	}
	puts(c);
	return 0;
}

int binSearch(int* integers, const size_t n, int target)
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
			return mid;
	}
	return n;
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


int *arrFind(int* integers, const size_t n, int target)
{
	int start, end;

	start = 0;
	end = n -1;
	while (start <= end)
	{
		if (! (*(integers + start) == target))
			start++;
		else
			return integers+start;
	}
	return NULL;
}



void capitalise(char* str)
{
	char newString;
	int cnt=0;
	while (str[cnt] != '\0')
	{  
		if ( isalpha( str[cnt]) && islower( str[cnt] ) ) 
		{
			newString = toupper( str[cnt] ); 
			str[cnt] = newString;
		}
		cnt++;
	}
																   
}

void int2string( int n, char answer[] )
{
	int len=0, i=n;
	char c;
	while (! (i == 0))
	{
		len++;
		i /= 10;
	}
	for (i = len-1; i >= 0; i--)
	{
		c = (char) (n%10) + '0';
		answer[i] = c;
		n /= 10;
	}
}


int main()
{
	double mean, min, max;
	char bas[]={'f','u','c','k','\0'};
	double randArr[] = {0, 1, 4, 10, 164, 2377, 5479, 576086, 2272746, 316107723};
	arrStats(randArr, 10, &mean, &max, &min);
	printf("Mean : %lf\tMax : %lf\tMin : %lf\n", mean, max, min);
//	printf ("Binary Search Result : %d", arrFind(randArr, 10, 2));
	int2string(231321321, bas);
	return 0;
}
