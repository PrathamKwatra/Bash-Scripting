/******************************************************************
 * sNode.h - i/f for the sNode type and some supporting functions
 *
 * Kurt Schmidt
 * Oct 2019
 *
 * EDITOR:  tabstop=2, cols=80
 ******************************************************************/
 
#ifndef __KS_SNODE_H_
#define __KS_SNODE_H_

#include <stdlib.h>

typedef struct sNode sNode ;

struct sNode
{
	int i ;
	sNode *next ;
} ;

	/* given a pointer to a linked list, frees the sNodes in the list */
void freeList( sNode *p ) ;

	/* Generates a random list of integers 0<i<100 from the heap 
	   Call srand48() to seed */
sNode* generateRandomList( int length ) ;

#endif  /* __KS_SNODE_H_ */
