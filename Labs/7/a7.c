/*********************************************************
 * LenString.c - reads until blank line or EOF
  *
   *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lenstr(char str[])
{
	int cnt=0;
	while (str[cnt] != '\0')
		cnt++;

	return cnt;
}

void addStrings(char dest[], char src[])
{
	int lenDest=0, lenSrc=0, i=0;
	lenDest = lenstr(dest);
	lenSrc = lenstr(src);
	//lenDest--;
	for (i=0; i < lenSrc; i++)
	{
		dest[lenDest] = src[i];
		lenDest++;
	}
	dest[lenDest] = '\0';
}

int main()
{
	char random[100]="This is a ", string[20] = "Programmer's Den";
	addStrings(random, string);
	printf("String Additon: %s\n", random);

	return 0;
}

