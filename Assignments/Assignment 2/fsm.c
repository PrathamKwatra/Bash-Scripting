#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

/*********************************************************************************
*                              Assignment 2     											*
*                             Pratham Kwatra   												*
* This assignment focuses on using DFA to create something like a regX checker.  *
* The Program is able to do so for DFA graphs: don, calma, bar, and aldo.        * 
* The functions dedicated to DFA are composed of if-then-else statements mainly. *
* The program stops if a blank or EOF line is encountered in a file or STDIN.    *
*********************************************************************************/

//Returns the length of given string
int strLen(char *s);

//Follows the aldo DFA graph
int aldo(char *s);
//Follows the bar DFA graph
int bar(char *s);
//Follows the calma DFA graph
int calma(char *s);
//Follows the dol DFA graph
int dol(char *s);

//Checks if the string is valid message in aldo, bar, calma or dol.
//If it matches any of them it returns 0
int msgCheck(char *s);

//Reads the message from arg or file. Prints OK if message passes any of the DFA graph else FAIL
int main(int argc, char **argv)
{
	int EOF_NUMBER = -1;
	FILE* fp = NULL ;
	char* strIN = NULL ;
	size_t len = 0 ;
	//checking for file
	if( argc > 1 )
	{
		fp = fopen( argv[1], "r" ) ;

		if( fp == NULL )
		{
			perror( "Can not open input file for reading.\n" ) ;
			exit(1);
		}
	}
	else
	{
		fp = stdin ;
		EOF_NUMBER = 1;
	}
	//Reading from the input stream
	while( getline( &strIN, &len, fp ) > EOF_NUMBER )
	{
		strIN[ strLen(strIN)-1 ] = '\0';
		printf("%s %s\n", strIN,(msgCheck(strIN)==0) ? "OK" : "FAIL");
	}
	free( strIN );
	strIN = NULL;
	len = 0;

	return 0;
}

int msgCheck(char *s)
{
	if (aldo(s)==0 || bar(s)==0 || calma(s)==0 || dol(s)==0)
		return 0;
	else
		return 1;
}

int strLen(char *s)
{
	int cnt=0;
	char *t=s;
	while (*t != '\0')
	{
		cnt++; t++;
	}
	return cnt;
}

int aldo(char *s)
{
    int state=0, tempState=0;
    char *t=s;
    while (*t !='\0')
    {
       if (state==0) 
        {
            if (*t == 'A')
                tempState = 1;
            else
                return 1;
        }
        if (state==1)
        {
            if (isdigit(*t) != 0)
                tempState = 2;
            else 
                return 1;
        }
        if (state==2 && isdigit(*t) != 0)
            tempState=2;
        if (state==2 && isdigit(*t) == 0)
        {
            if (*t == 'F')
                tempState =3;
            else
                return 1;
        }
        if (state==3)
            return 1;
        state = tempState;
        t++;
    }
   if (state==3)
      return 0;
   return 1;
}

int bar(char *s)
{
	int state=0, tempState=0;
	char *t=s;
	while (*t!='\0')
	{
		if (state==0)
		{
			if (*t == 'B')
				tempState=1;
			else
				return 1;
		}
		if (state==1)
		{
			if (*t == 'H')
				tempState=2;
			else
				return 1;
		}
		if (state==2)
		{
			if (*t == 'G')
				tempState=3;
			else
				return 1;
		}
		if (state==3)
		{
			if (*t == 'X')
				tempState = 4;
			else
				return 1;
		}
		if (state==4)
		{
			if (*t == 'H')
				tempState=2;
			else
				return 1;
		}
		state=tempState;
		t++;
	}
	if (state==1 || state==3)
		return 0;
	else
		return 1;
}

int calma(char *s)
{
	char *t=s;
	int state=0, tempState=0, countT=0;
	while (*t != '\0')
	{
		if (state==0)
		{
			if (*t == 'C')
				tempState=1;
			else
				return 1;
		}
		if (state==1)
		{
			if (*t=='R')
				tempState=1;
			else
			{
				if (*t == 'T')
					{
						tempState=2;
						countT++;
					}
				else
					return 1;
			}
		}
		if (state==2)
		{
			if (*t=='R')
				tempState=2;
			else
			{
				if (*t=='T')
					{
						tempState=1;
						countT++;
					}
				else
					return 1;
			}
		}
		t++;
		state=tempState;
	}
	if (state==1)
		return 0;
	else
		return 1;
}

int dol(char *s)
{
	int state=0, tempState=0;
	char *t=s;
	while (*t !='\0')
	{
		if (state==0)
		{
			if (*t == 'D')
				tempState=1;
			else
				return 1;
		}
		if (state==1)
		{
			if (isdigit(*t) != 0)
				tempState=2;
			else
				return 1;
		}
		if (state==2)
		{
			if (isdigit(*t) != 0)
				tempState=3;
			else
				return 1;

		}
		if (state==3)
		{
			if (aldo(t)==0 || calma(t)==0)
				return 0;
			else
				return 1;
		}
		t++;
		state=tempState;
	}
	return 1;
}
