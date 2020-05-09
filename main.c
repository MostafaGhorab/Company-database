
#include "header.h"
void main(void)
{
 u8 choice = 0;
 //LOAD();
 //Sort();
 //printList();

 do
 {
     printf("\n***********************************WELCOME**********************************\n\n");
     printf("1-Add New Employee \t2-Load Employees data from database file\n");
     printf("3-Delete Employee  \t4-Save Employees data\n");
     printf("5-Search           \t6-Modify Employees data\n");
     printf("7-Quit\n");
     printf("please enter your choice from 1 to 7: ");
     scanf("%d",&choice);
     getchar();
     switch (choice)
     {
     case 1 :
        ADD();
        break;

    case 2 :
        LOAD();
        break;

    case 3 :
         DELETE()  ;
        break;

    case 4 :
        SAVE();
       // Sort();
        break;

    case 5 :
        SEARCH();
        break;

    case 6 :
        MODIFY();
        break;


    case 7 :
        QUIT();

        choice = 99;
        break;
    default :
        {
            printf("ERROR PLEASE ENTER NUMBER FOR 1 TO 7!\n");
        }




     }






 }while (choice !=99) ;









}
