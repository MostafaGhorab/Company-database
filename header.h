#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;


typedef struct nodeee
{
    char name[20];
    char num [15];
    char mail [100];
    char date [20];
    char job[20];
    struct node *next;
}node;

///MAIN FUNCTIONS

 void ADD (void) ;

 void LOAD (void) ;

 u8 DELETE (void);

 void SEARCH (void);

 void MODIFY (void);

 void SAVE (void);

 u8 QUIT (void);

 void Sort(void);
 //void print (node *lisst);
// node* searchID (linkedList *listt,u32 pID);
 //void editNode ( node* patient_node,char pname[40],u32 page ,char pgender[10]);
///EXTRA PRIVATE FUNCTIONS
node* addNode (void);
u8 leapYear (u8 year); ///BONUS FUNCTION CHECK FOR LEAP YEARS
u32 stringToDecimal (char arrayy[]) ; ///CHANGES THE STRING NUMBERS INTO DECIMAL TO PERFORM OPEARTIONS ON THEM
void printList(void); ///validation function
 void BSORT (void);




#endif // HEADER_H_INCLUDED


