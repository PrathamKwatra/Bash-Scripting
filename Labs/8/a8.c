
#include <stdio.h>
#include <stdlib.h>

typedef struct sNode sNode ;

struct sNode{
   int data ;
   sNode *next ;
} ;

void printLL( sNode *l, FILE *fp )
{
   fprintf( fp, "<" ) ;
   while( l != NULL )
   {
      fprintf( fp, " %d", l->data ) ;
      l = l->next ;
   }
   fprintf( fp, " >" ) ;
}

sNode* removeOne( sNode *L, int t )
{
   sNode *p = L , *q = NULL ;
   //check for 1st node
   if (p->data == t)
      { 
          printf("\n%d\n", p->data);
          q = p->next;
          free(p);
          p = NULL;
          return q; 
      }
   q = p;
   p = p->next;
   while( p!=NULL )
   {
      if( p->data == t )
         q->next = p->next;
         free(p);
         p = NULL;
         return L ;
      q = p ;
      p = p->next ;
   }

   //if( p == NULL ) return NULL ;
   return NULL;
   // TODO:  unhook that element
}


int main(int argc, char* argv[])
{
    sNode *l = NULL , *t = NULL, *a = NULL;
    l = (sNode*) malloc( sizeof( sNode )) ;
    l->data = 13 ; l->next = NULL ; //Last One

    t = (sNode*) malloc( sizeof( sNode )) ;
    t->data = 12 ; t->next = l ; l = t ;
    
    a = (sNode*) malloc( sizeof( sNode )) ;
    a->data = 12 ; a->next = l ; l = a ;

    printLL(l, stdout);

    removeOne(l, 13);

    printLL(l, stdout);

    return 0;

}


