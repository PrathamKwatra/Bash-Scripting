#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void capitalise(char *str)
{
   //Initial
   char newString;
   int cnt=0;
   //loop to parse over the given string(or characters)
   while ( *(str+cnt) != '\0')
   {
      //Check Statement which only applies if the char is an alphabet and is a lower
      if ( isalpha( *(str +cnt)) && islower(  *(str+cnt) ) )
      {
         newString = toupper(  *(str+cnt) );
         //Swtiches the lower with upper
         *(str+cnt) = newString;
      }
      //keeps a count
      cnt++;
   }

}


int *arrFind(int* integers, const size_t n, int target)
{
   int start, end;

   start = 0;
   end = n -1;
   while (start <= end)
   {
      if (! (*(integers + start) == target))
         start++;
      else
         return integers+start;
   }
   return NULL;
}

int main()
{
  int elementFound;
  int intArr[3] = {1,2,3};
  elementFound = *arrFind(intArr, 3, 2);
  printf("Element Found %d", elementFound);

  return 0;
}
