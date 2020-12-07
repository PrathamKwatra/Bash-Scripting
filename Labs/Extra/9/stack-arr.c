/********************************************************************************
 * stack-arr.c -- implementation for stack functions (built over an array)
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

#include "stack-arr.h"


const int CAP = 100 ;


void init( stack* s )
{
	s->size = 0 ;
	s->cap = CAP ;
}

_Bool isEmpty( const stack* s ) 
{
	return s->size == 0 ;
}

void push( stack* s, ELEM i ) 
{
	assert( s->size < s->cap ) ;
	s->arr[ s->size ] = i ;
	s->size += 1 ;
}

ELEM pop( stack* s ) 
{
	assert( s->size > 0 ) ;
	s->size -= 1 ;
	return s->arr[ s->size ] ;
}

