/* stack.c - Implementation for an array-based stack of integers
 *
 * Kurt Schmidt
 * 3/2018
 *
 * gcc 5.4.0 20160609 on
 * Linux 4.13.0-32-generic
 *
 * EDITOR:  tabstop=2 cols=120
 */

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"


	/* Helper function.  Not part of the interface 
	 * Doubles the capacity of the array  */
bool grow( stack_t* S )
{
	/* Stack implemented as a linked list.  Nothing to do. */
	
	return( true ) ;
}


stack_t* stack_init()
{
	return( NULL ) ;
}

	/* returns true if Stack is empty */
bool is_empty( stack_t* S ) 
{
	return( S->head == NULL ) ;
}

void push( stack_t* S, int x )
{
	/* TODO  wrap x in a stack_t,
	 * insert at beginning of list */
}


int pop( stack_t* S ) 
{
		/* TODO  Remove node at beginning of list, return to heap
		 * return the integer it contains */
}


void kill( stack_t* S )
{
	/* TODO - free each of the sNodes, *and* 
	 * the stack_t object   */
}

