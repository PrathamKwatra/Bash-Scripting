/********************************************************************************
 * stack-ll.c -- implementation for stack functions (built over a linked list)
 *
 * Kurt Schmidt
 * NOV 2020
 *
 * gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0, on
 * GNU/Linux 4.15.0-117-generic x86_64
 *
 * EDITOR:  tabstop=2, cols=120
 *
 ********************************************************************************/

#include <assert.h>
#include <stdlib.h>

#include "stack-ll.h"


void init( stack* s )
{
	sNode *p;
	p->next = NULL;
	s->head = p;
	//Does this make sense?
	//return ;
}

void kill( stack* s )
{
	sNode *p = s->head, *q ;
	while( p != 0 ) 
	{
		q = p->next ;
		free( p ) ;
		p = q ;
	}
}

_Bool isEmpty( const stack* s ) 
{
	if (s->head = NULL)
		return true ;
	else 
		return false;
}

void push( stack* s, ELEM i ) 
{
	sNode *p;
	p->ELEM = i;
	p->next = s->head;
	s->head = p;
	//return ;
}

ELEM pop( stack* s ) 
{
	ELEM toReturn = s->head->ELEM;
	s->head = s->head->next;
	return  toReturn;
}

