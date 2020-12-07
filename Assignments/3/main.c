/*
	Assignment 3
	Pratham Kwatra
	CS 265

	Notes:
	Some things are repeated and a little bit over the top in terms of design,
	but the program gets the work done, for most of the cases. 
	Cases such as add <id>:9999999  would not work as qty is anm unsigned short.
	The only method to terminate the program is typing quit. If there is a forceful quit,
	data is not saved.
	The tmp file is not saved unless there is somekind of mishap. 
	Most of the main functions have been listed near the top along with their explainations.
*/


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

typedef struct itemNode itemNode ;

struct itemNode {
   char id[16] ;
   unsigned short qty ;
   char desc[31] ;
   itemNode *next ;
} ;
//GLOBAL DECLARATIONS 
char *DB = "inv.dat"; //Database
char DL = ':';//Custom delimiter

//This function assumes the Database DB is present in cwd and in the given format. 
//There will be undefined behaviour if DB is not present or in wrong format.
//it mainly uses a loop to parse over the file line by line till EOF.
itemNode *createFromFile();
//This is my own string copy function to work with : rather than spaces.
void strcopy(char s[], char d[]);
//This takes the head of the list and prints out the information in the nodes in a neat manner.
void print(itemNode *head);
//This function requires all three arguments to be present to work. It adds the given count
//in the given id's quantity (head->qty).
void add(itemNode *head, char *id,int count);
//Same as the add function but reduces the value of head->qty by the given quantity.
//Throws an error message if head->qty - count is a negative number
void removeQty(itemNode *head, char *id, int count);
//Quits the program
void quit();
//Writes the new data on the inv.dat file 
void writeFile(itemNode *head);
//Creates a temp file incase something goes wrong while writing the file.
int createTempFile(itemNode *head);
//Parses the given user input and checks the validity. 
int userInput(itemNode *head, char *buff);

int main()
{
	char *buff=NULL;
	size_t len;
    int state= 0;
    itemNode *head = createFromFile();
    printf("%% ");
	 //INPUT LOOP START
    while( state==0 && getline (&buff, &len, stdin) > -1)
    {
        state = userInput(head, buff);
        printf("%% ");

    }
	 free(buff);
	 buff = NULL;
	 //When the user quits this if-statement is executed and gives details about the FILE write. 
	 if ( createTempFile(head) == 0 )
		{
			printf("\n*temp created* *making the official copy*\n");
			writeFile(head);
		}
	else
	{
		printf("*write not successful* *temp file saved in /tmp*");
		writeFile(head);
	}	
	quit();
   return 0;
}

int userInput(itemNode *head, char *buff)
{
    char orig[101];
	 //stores the original buffer, since strtok changes the buff after each use. 
    strcpy(orig, buff);
    char *command = strtok(buff, " ");
    char *id = strtok(NULL, ":");
    char *cnt = strtok(NULL, ":");
    //not checking if cnt is a valid number since this check has not been mentioned in the assignment.
    if ( ( strcmp(command,"remove") == 0 ) || ( strcmp(command,"add") == 0 ) )
    {
    	if (id == NULL || cnt == NULL)
    	{
        puts("NAK Incorrect syntax.");
        return 0;
    	}
		//in most cases if the cnt is an alpha numeric this count will become 0, nothing will be added.
    	int count = atoi(cnt);
    	if ( strcmp(command, "remove") == 0 )
        removeQty(head, id, count);
    	else
        add(head, id, count);
    }
    else if ( strcmp(orig, "quit\n") == 0 || strcmp(command, "quit") == 0)
    {
    	 puts("ACK");
   	 return 1;
    }
    else if ( strcmp(orig, "print\n") == 0 || strcmp(command, "print") == 0)
    {  
		puts("ACK\n");
    	print(head);
    }
    else
    	puts("Unrecognised command");

    return 0;
}

itemNode *createFromFile()
{
    FILE *data=NULL ;
    itemNode *head= (itemNode*) malloc(sizeof(itemNode));
    itemNode *cur;
	 char *buff = NULL;
    size_t len;

    data = fopen(DB, "r");
    if (data == NULL)
    {
		printf("FILE %s not found/readable", DB);
      exit(1);
    }

    int state=0; char num[20];

	//This loop add the read information from buffer to the cur Node. 
    while ( getline( &buff, &len, data) != -1 )
    {
        if (state==0)
        {
            strcopy( buff, head->id );
            strcopy( buff, num);
            head->qty = atoi(num);
            strcpy( head->desc, buff );
            head->desc[strlen(buff)-1] = '\0';
            cur = head;
            cur->next = NULL;
            state = 1;
        }
        else
        {
            cur->next = (itemNode*) malloc(sizeof(itemNode));
            strcopy(buff, cur->next->id);
            strcopy(buff, num);
            cur->next->qty = atoi(num);
            strcpy(cur->next->desc, buff);
            cur->next->desc[strlen(buff)-1] = '\0';
            cur->next->next = NULL;

            cur = cur->next;
        }
    }
    
	 free(cur->next);
    cur->next = NULL;
    free(buff);
    buff = NULL;
    fclose(data);
    return head;
}

//This is my string copy function
void strcopy(char s[], char d[])
{
    int c=0, i=0;
    while (s[c] != DL)
    {
        d[c] = s[c];
        c++;
    }
    d[c] = '\0';
	 //this slices the string s
    strcpy(&s[0],&s[c+1]);
}

void print(itemNode *head)
{
    printf("   DESC                           QTY         ID\n");
    printf("-------------------------------  ----------  ----------------\n");
    while (head != NULL)
    {
        printf("%-31s  %10d   %-16s\n", head->desc, head->qty, head->id);
        head = head->next;
    }
}

void add(itemNode *head, char *id,int count)
{
    itemNode *someNode= head;
    int state=0;
    while (state==0 && someNode != NULL)
    {
	 	size_t ran = strlen(someNode->id);
      if (strncmp(someNode->id, id, ran) == 0)
      {
         state = 1;
      	break;
      }
        someNode = someNode->next;
    }
    if (state == 1)
	 {
    	puts("ACK");
      someNode->qty += count;
	 }
    if (state == 0)
        printf("NAK Unknown Item\n");
}

void removeQty(itemNode *head, char *id,int count)
{
    itemNode *someNode= head;
    int state=0;
    while (state==0 && someNode != NULL)
    {
		  size_t ran = strlen(someNode->id);
        if (strncmp(someNode->id, id, ran) == 0)
        {
        		state = 1;
           	break;
        }
        someNode = someNode->next;
    }
    if (state == 1)
        { 
            int someVal = someNode->qty - count;
            if (someVal <= 0)
                printf("NAK Insufficient Quantity\n");
            else
                {
                    puts("ACK");
                    someNode->qty -= count;
                }
        }
    if (state == 0)
        printf("NAK Unknown Item\n");
}


void quit()
{
    exit(0);
}

void writeFile(itemNode *head)
{
	FILE *fp;

	fp = fopen(DB, "w");
	while (head != NULL)
	{
		fprintf(fp, "%s:%d:%s\n", head->id, head->qty, head->desc);
		head = head->next;
	}

	fclose(fp);
}

int createTempFile(itemNode *head)
{
   char filename[] = "/tmp/inv.dat.XXXXXX"; // template for temp file.
   
	int fd = mkstemp(filename);
   
	if (fd == -1)
   {
       printf("Error on temp file creation");
       return 1;
   }

   char data[101];
   while (head != NULL)
   {
      sprintf(data, "%s:%d:%s\n",head->id, head->qty, head->desc);
      write(fd, data, sizeof(data));
      head = head->next;
   }
  
  //unlink(filename) this should have been used but i did not understnad the usage since the 
  //program worked without it. 
  close(fd);
 //If rename correctly then the file name is changed to DB and moved to cwd for overwriting.
 //Else it will be in the /tmp dir. 
  if (  rename(filename, DB) == 0 )
		return 0;
  return 1;
}



