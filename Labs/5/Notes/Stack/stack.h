/* stack.h - Interface for an array-based stack of integers
 *
 * Kurt Schmidt
 * 3/2018
 *
 * gcc 5.4.0 20160609 on
 * Linux 4.13.0-32-generic
 *
 * EDITOR:  tabstop=2 cols=120
 */

#ifndef __KS_STACK_
#define __KS_STACK_

#include <stdbool.h>

typedef struct sNode sNode ;

struct sNode
{
	int data ;        /* The data, the payload */
	sNode* next ;
}  ;

	/* wrapper, contains the stack */
typedef struct
{
	sNode* head ;
}
	stack_t ;

typedef stack_t* Stack ;

	/* Returns new (empty) stack */
Stack stack_init() ;

	/* Returns true if Stack S is empty */
bool is_empty( Stack S ) ;

	/* Pushes x onto Stack S */
void push( Stack S, int x ) ;

	/* Returns element at top of Stack S
	 * Behavior undefined if stack is empty. */
int pop( Stack S ) ;

	/* Should be called when done w/stack */
void kill( Stack S ) ;

#endif /* __KS_STACK_ */

