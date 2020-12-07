#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/********************
*  Assignment 2     *
*  Pratham Kwatra   *
********************/

int aldo(char *s);
int bar(char *s);
int calma(char *s);
int dol(char *s);

int main()
{
	char *s = "A12321321323141244231F";
	printf("String S: %s\n", (aldo(s)==0) ? "OK" : "FAIL");
	return 0;
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
        //printf("*t : %c , tempState : %d, state : %d\n", *t, tempState, state);
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
      //printf("*t : %c , tempState : %d, state : %d\n", *t, tempState, state);
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
      //printf("*t : %c , tempState : %d, state : %d\n, countT: %d", *t, tempState, state, countT);
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
      //printf("*t : %c , tempState : %d, state : %d\n", *t, tempState, state);
		t++;
		state=tempState;
	}
	return 1;
}
