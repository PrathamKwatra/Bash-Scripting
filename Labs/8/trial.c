#include <stdio.h>
#include <stdlib.h>


typedef struct sNode sNode ;

struct sNode
{
   int data ;
   sNode* next ;
};

struct time 
{
   int hr ;
   int min ;
   int sec ;
};

struct time sec2hms( int secs )
{
	struct time properTime;
	properTime.hr = secs / 3600;
	properTime.min = (secs % 3600) / 60;
	properTime.sec = (secs % 3600) % 60;
	printf("\nhrs:%d, min:%d, secs:%d\n", properTime.hr, properTime.min, properTime.sec);
	while (properTime.hr > 23)
		properTime.hr -= 24;
	printf("hrs:%d, min:%d, secs:%d\n", properTime.hr, properTime.min, properTime.sec);
	while (properTime.min > 59)
		properTime.min -= 60;
	printf("hrs:%d, min:%d, secs:%d\n", properTime.hr, properTime.min, properTime.sec);
	return properTime;
}

size_t listLength( const sNode *L )
{
	int cnt=0;
	sNode *cur = L;
	while (cur != NULL)
	{	
		cnt++;
		cur = cur->next;
	}
	return cnt;
}

sNode* listRev( sNode *L )
{
	sNode* old=NULL;
	sNode* cur= L;
	sNode* nextNode;

	while (cur != NULL)
	{
		nextNode = cur->next;
		cur->next = old;
		old = cur;
		cur = nextNode;
	}
	L = old;
	return L;
}

int main()
{
	struct time randTime=sec2hms(889271);
	printf("hrs:%d, min:%d, secs:%d\n", randTime.hr, randTime.min, randTime.sec);
	return 0;
}
