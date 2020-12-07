/******************************************************************
 * sNode.c - implementation for the sNode type and some supporting functions
 *
 * Kurt Schmidt
 * Oct 2019
 *
 * EDITOR:  tabstop=2, cols=80
 ******************************************************************/
 
#include <stdlib.h>


void freeList( sNode *p )
{
	sNode *q = NULL ;

	while( p != NULL )
	{
		q = p->next ;
		free( p ) ;
		p = q ;
	}

}

sNode* generateRandomList( int length ) 

#endif  /* __KS_SNODE_H_ */
