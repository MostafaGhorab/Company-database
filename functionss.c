#include "header.h"


node *head=NULL ;
node *newNode = NULL;







///****************************************************   ADD FUNCTION  ****************************************************
 void ADD (void)
{
    FILE *fp;

    u8 i=0;
    u8 flag = 0;
    //node *newNode;
    newNode = (node*)malloc(sizeof(node)) ;

///****************************************************GETTING THE Name OF THE EMPLOYEE****************************************************
        do
        {
            i=0;

        printf("Enter Employee's name *first letter should be in upper case*: ");
        scanf("%[^\n]",newNode->name);

         while (newNode->name[i] != '\0')
         {

             if (!(newNode->name[0] >= 'A'&& newNode->name[0] <= 'Z' ))
             {
                 printf("ERROR! first letter is not capital!\n");
                 getchar();
                 break;

             }
             if ( ( newNode->name[i] >= 'a'&& newNode->name[i] <= 'z' ) || (newNode->name[i] >= 'A'&& newNode->name[i] <= 'Z' ) || (newNode->name[i] == ' ' )  )
                i++;
             else
             {
                 printf("ERROR! NAME MUST BE STRING ONLY!\n");
                 getchar();
                 break;


             }
             if (newNode->name[i] == '"')
             {
                 printf("ERROR! NAME MUST BE STRING ONLY BUT NOT \"!\n");
                 getchar();
                 break;

             }





         }

         }while (i<strlen (newNode->name ));
          printf("%s\n",newNode->name);

          getchar();

///****************************************************GETTING THE phone Number OF THE EMPLOYEE****************************************************
 do
        {
            i=0;

        printf("Enter Employee's phone number: ");
        scanf("%[^\n]",newNode->num);

         while (newNode->num[i] != '\0')
         {
             if ( ( newNode->num[i] >= '0'&& newNode->num[i] <= '9' )    )
                i++;
             else
             {
                 printf("ERROR! PHONE NUMBER MUST BE DIGIT NUMBERS EACH BETWEEN 0-9 ONLY!\n");
                 getchar();
                 break;


             }


         }
         }while (i<strlen (newNode->num ) );
          printf("%s\n",newNode->num);

          getchar();

 ///****************************************************GETTING THE Email OF THE EMPLOYEE****************************************************
 int x=0;
 do
        {
            i=0;

           // x=0;
            if (flag != 2 &&flag !=0 && flag!=99 && x!=0 )
            {
                 printf("ERROR! E_MAIL FORMAT ERROR!\n");
                 getchar();

            }
            flag = 0;
            x=0;

        printf("Enter E-mail as the following fortmat: somthing@webiste.com: ");
        scanf("%[^\n]",newNode->mail);

         if (   ! ( ((newNode->mail[0] >='a') && (newNode->mail[0] <= 'z') ) || ((newNode->mail[0] >='A') && (newNode->mail[0] <= 'Z')) ) )
             {
                 flag = 99;
                 printf("ERROR! E_MAIL MUST START WITH STRING!\n");
                 getchar();

             }

             else
             {

         while (newNode->mail[i] != '\0')
         {


            if (newNode->mail[i] == '@' || flag ==1 )
            {
                if (newNode->mail[i] == '@' && flag!=1 )
                {
                    if (  ! (newNode->mail[i+1] >='a') && (newNode->mail[i+1] <= 'z')   )
                    {
                        flag = 99;
                        printf("ERROR! String missing !\n");
                  //getchar();
                break;
                    }
                flag ++;
                x=1;
                // x++;
                }
                else if (newNode->mail[i] == '.' && newNode->mail[i+1] == 'c' && newNode->mail[i+2] == 'o' && newNode->mail[i+3] == 'm' )
                flag ++;
                else { }




            }
            if (newNode->mail[i] == ' ' || newNode->mail[i] == '"'  )
            {
                flag = 99;
                printf("ERROR! E_MAIL MUST NOT CONTAIN SPACES OR DOUBLE QOUTES !\n");
                  getchar();
                break;

            }


            i++;
         }
         if (x==0)
         {
             printf("ERROR! E_MAIL FORMAT ERROR!\n");
                 getchar();

         }
             }
         }while (flag >= 99 || flag !=2  );
          printf("%s\n",newNode->mail);

          getchar();

 ///****************************************************GETTING THE birth date OF THE EMPLOYEE****************************************************
 u8 year [10] ;
 u8 month [10];
 u8 day [10];
 u8 count =0;
 u8 spaces =0;
 u32 yearDec;
 u32 monthDec;
 u32 dayDec;
 const char characterr[2] = {'/','\0'};

 do
        {
            i=0;
            spaces =0;
            count =0;
            if (flag ==1)
            {
                printf("ERROR! PLEASE FOLLOW THE GIVEN FORMAT!\n");
                 getchar();

            }
            flag =0;

        printf("Enter Employee's birth date in the following arrangement ' Day month year ' with space between them : ");
        scanf("%[^\n]",newNode->date);
        if (strlen (newNode->date  ) >10 )
        {
            printf("ERROR!\n");
            flag =1;
        }
        else
        {

         while (newNode->date[i] != '\0')
         {
             if (newNode->date[i] == ' ')
             {
                 spaces ++;
                 i++;
                continue;
             }
            if (newNode->date[i] >= '0' && newNode->date[i] <='9')
            {


            }
            else
            {
            flag = 1;
           //printf("ERROR! DATE MUST BE NUMBERS ONLY!\n");
            break;
            }

            i++;
         }

        }
        if(spaces<2)
            flag =1;
        if (flag ==0)
        {

    char* token = strtok(newNode->date, " ");  //to validate each part alone

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
            if (count ==0)
            strcpy (day,token);
            else if (count ==1)
            strcpy (month,token);
            else if (count ==2)
            strcpy (year,token);
            else
            {
                printf("error!\n");
            }
        //printf("%s\n", token);
        count ++;
        token = strtok(NULL, " ");
    }
   // printf("string are : %s %s %s \n",year,month,day);
    ///****************************************checking for year ranges****************************************************
      /*  if (year[0]==1 && year[1]==9 && ( year[2] >= '5' || year[2] <= '9')  )
        {
                if ( year[2] == '5' && year[3] !='9' )
                {
                    flag =1;
                }
                if ( year[2] == '9' && year[3] >'6' )
                {
                    flag =1;
                }
        }
        else flag =1;*/
       yearDec = stringToDecimal(year);
       monthDec = stringToDecimal(month);
       dayDec = stringToDecimal(day);
      // printf("neww %d %d %d ", yearDec,monthDec,dayDec );
      if (yearDec<1959 || yearDec> 1996)
      {
          flag =1;
          printf("ERROR!YEAR SHOULD BE BETWEEN 1959 and 1996!\n");
      }
        if (monthDec<1 || monthDec> 12)
      {
          flag =1;
          printf("ERROR!MONTHS SHOULD BE BETWEEN 1 and 12!\n");
      }
      if (dayDec<1 || dayDec> 31)
      {
          flag =1;
      }
      if( (monthDec==4 || monthDec == 6 || monthDec == 9 || monthDec == 11 ) && dayDec==31 )
      {

            flag =1;
        }
        if (monthDec == 2)
        {
           if (leapYear(yearDec))
           {
               printf("LEAP YEAR!\n");
               if (dayDec>29)
               {
                printf("LAST DAY IN FEBRUARY IS 29!\n");
                flag = 1;
               }
           }
           else  //not leap returned value is zero
           {
                printf("NOT LEAP YEAR!\n");
               if (dayDec>28)
               {
                printf("LAST DAY IN FEBRUARY IS 28!\n");
                flag = 1;
               }
           }
        }


    }



         }while (flag ==1);
         ///concatenation of the final string in the format of d/m/y
         strcpy (newNode->date,day);
         strcat(newNode->date,characterr);
         strcat(newNode->date,month);
         strcat(newNode->date,characterr);
         strcat(newNode->date,year);
         printf("%s\n",newNode->date);
         // printf("date contains nw%s\n",newNode->date);
         getchar();

///**************************************************** GETTING THE JOB TITLE OF THE EMPLOYEE**************************************
        u8 ch;
        u8 arr[1000];
        u8 found = 0;
        u32 m=0;
        do
      {
        printf("Enter Employee's job title: ");
        scanf("%[^\n]",newNode->job);
        printf("%s\n",newNode->job);
        fp = fopen("company.txt", "r"); // read mode
       if (fp == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }

      // printf("\nThe contents of %s file are:\n", fileName);


    m=0;
    found =0;
      while((ch = (fgetc(fp))) != '^')
	   {
	       arr[m] = ch;
	       m++;

	   }
	   arr[m] = '\0';
	  // printf("%s",arr);
	   char* token = strtok(arr, "\n");  //to validate each part alone

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
        {
          if( !(strcmpi(token,newNode->job)) )
          {
              found =1;
          }

        token = strtok(NULL, "\n");
    }
    if (found ==0)
    {
        printf("ERROR! PLEASE Enter one of job titles' in companies's database,\n");
        getchar();
    }
      }while (found==0);
     getchar();
///*******************************************************NODE APPENDING***************************************************************
    newNode->next = NULL;
    node*Temp;


     Temp = head;


    if (Temp==NULL) ///first NODE
    {

       head = newNode;
      // printf("first node\n");


    }
    else if ((Temp ->next) == NULL) ///second node
    {

    head-> next = newNode;


    }
    else ///appending new nodes
    {


        while (Temp->next != NULL)
    {
        Temp = Temp->next;

    }
    (Temp->next) = newNode;

    }


}

///*******************************************************LOAD FUNCTION*****************************************************
 void LOAD (void)
 {
        FILE *fp;
        u8 fileName[20];
        u8 ch;
        u32 qoutes=0;
        u32 comma=0;
        u32 i =0;
        u8 fileContent [10000]={0};
        u32 counter =0;
        u32 j =0;

       // newNode = (node*)malloc(sizeof(node)) ;


       // printf("Enter name of the database file: ");
        //gets(fileName);
       ///gets can be used to get the name of file from the user
       fp = fopen("ba.txt", "r"); // read mode
       if (fp == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }

      // printf("\nThe contents of %s file are:\n", fileName);


      while((ch = (fgetc(fp))) != '^')
	   {


	       if (ch == '"')
           {
            qoutes ++;
            if( (qoutes%2) ==0  )
            {
                    fileContent[i] = '"';
                    i++;
            }




           }

            if( (qoutes%2) ==0  )
            {



            }
            else
            {
                 if (ch == ',')
                comma++;
                fileContent[i] = ch;
                i++;
            }

     //   printf("%c",ch);




	   }



     fileContent[i] = '\0';

      if( (comma%4)!= 0  )
       {
           printf("\nERROR!FIELDS ERROR PLEASE CHECK YOUR FILE!\n");
          // printf("%d",comma);
           return 0;
       }


    //printf("%s\n", fileContent);
    fclose(fp);
    i=0;
    qoutes = 0;


    while (fileContent[i] != '\0')
    {
        if (fileContent[i]  == '"')
        {
            qoutes ++;
            if( (qoutes%2) !=0  )
            {

                j=0;
                newNode =  addNode();
              // printf("***NEW Employee IS ADDED***\n");
                counter =0;


            }
            else
            {
                     newNode->job[j] = '\0' ;
            }
        }
        else if (fileContent[i] == ',')
        {
              counter ++;
             if (counter ==1)
            {

                newNode->name[j] = '\0' ;

            }

            else if (counter ==2)
            {
                 newNode->num[j] ='\0' ;
            }
            else if (counter ==3)
            {
                 newNode->mail[j] ='\0' ;
            }
            else if (counter ==4)
            {
                 newNode->date[j] = '\0' ;
            }

            else
            {
            printf("validation ERROR");
            return 0;
            }


            j =0;

        }
        else
        {
            if (counter ==0)
            {

                newNode->name[j] = fileContent[i] ;
              //  printf("%c", newNode->name[j]);

            }

            else if (counter ==1)
            {
                 newNode->num[j] = fileContent[i] ;
                 //printf("%c", newNode->num[j]);
            }
            else if (counter ==2)
            {
                 newNode->mail[j] = fileContent[i] ;
                 //printf("%c", newNode->mail[j]);
            }
            else if (counter ==3)
            {
                 newNode->date[j] = fileContent[i] ;
                 //printf("%c", newNode->date[j]);
            }
            else if (counter ==4)
            {
                 newNode->job[j] = fileContent[i] ;
                // printf("%c", newNode->job[j]);

            }
            else
            {
            printf("validation ERROR");
            return 0;
            }
            j++;


        }

         i++;


    }
    printf("FILE IS LOADED!,Employees names are: \n");
    printList();
//printf("\n\n%s %s %s %s %s\n\n",newNode->name,newNode->num,newNode->mail,newNode->job,newNode->date);



}

///*****************************************************DELETE FUNCTION************************************
u8 DELETE(void)
{

    node* temp = head;
    node* prev;
    u8 namee [20] ;
    printf("Enter the name of the Employee you wish to delete his/her data: ");
    gets(namee);


    if (temp != NULL && ! (strcmpi (namee, temp->name ) ) )
    {
        head = temp->next;
        free(temp);
       return 0;
    }


    while (temp != NULL && strcmpi (namee, temp->name ))
    {
        prev = temp;
        temp = temp->next;

    }


    if (temp == NULL)
    {
        printf("EMPLOYEE NOT FOUND!\n");
       return 0;
    }



    prev->next = temp->next;
    printf("\nDELETED!\n");

    free(temp);
    return 1;
}
///********************************************************SEARCH FUNC*******************************************
 void SEARCH (void)
 {

    node* Temp = head;
    u8 namee [20] ;
    printf("Enter the name of the Employee you wish to search for his/her data: ");
    gets(namee);

     if (Temp == NULL)
    {
        printf("List is empty");
        return 0;

    }
    //printf("%s",head->name);

     while ( Temp != NULL   )
     {

       if( !strcmpi (namee, Temp->name ) )
       {
   printf("\n\n\"%s,%s,%s,%s,%s\"\n\n",Temp->name,Temp->num,Temp->mail,Temp->date,Temp->job);
    break;
       }
     Temp =( Temp->next);
    }

      if (Temp == NULL)
    {
        printf("EMPLOYEE NOT FOUND!\n");
       return 0;
    }



 }
///******************************************************************MODIFY FUNC***********************************
 void MODIFY (void)
 {
    FILE *fp;
    u8 arr[1000];
    u8 ch;
    u8 flag =0;
    int m=0;
    int found =0;
    u32 i =0;
    node* Temp = head;
    u8 namee [20] ;
    u8 choice;
    printf("Enter the name of the Employee you wish to modify his/her data: ");
    gets(namee);

     if (Temp == NULL)
    {
        printf("List is empty");
        return 0;

    }
    //printf("%s",head->name);

     while ( Temp != NULL   )
     {

       if( !strcmpi (namee, Temp->name ) )
       {
           printf("To modify phone number press 1,for mail press 2, for job press 3: ");
           scanf("%d",&choice);
           getchar();
           switch (choice)
           {
           case 1 :
            do
        {
            i=0;

        printf("Enter Employee's new phone number: ");

        gets(Temp->num);

         while (Temp->num[i] != '\0')
         {
             if ( ( Temp->num[i] >= '0'&& Temp->num[i] <= '9' )    )
                i++;
             else
             {
                 printf("ERROR! PHONE NUMBER MUST BE DIGIT NUMBERS EACH BETWEEN 0-9 ONLY!\n");
                // getchar();
                 break;


             }


         }
         }while (i<strlen (Temp->num ) );
          //printf("%s\n",newNode->num);

         // getchar();


            break;

           case 2:
                do
        {
            i=0;
            if (flag != 2 &&flag !=0 && flag!=99)
            {
                 printf("ERROR! E_MAIL FORMAT ERROR!\n");
                // getchar();

            }
            flag = 0;

        printf("Enter new E-mail as the following fortmat: somthing@webiste.com: ");
       // getchar();
        gets(Temp->mail);

         if (   (Temp->mail[0] >='0') && (Temp->mail[0] <= '9')   )
             {
                 flag = 99;
                 printf("ERROR! E_MAIL MUST NOT START WITH NUMBER!\n");
                 //getchar();

             }

             else
             {

         while (Temp->mail[i] != '\0')
         {

            if (Temp->mail[i] == '@' || flag ==1 )
            {
                if (Temp->mail[i] == '@' && flag!=1 )
                flag ++;
                else if (Temp->mail[i] == '.' && Temp->mail[i+1] == 'c' && Temp->mail[i+2] == 'o' && Temp->mail[i+3] == 'm' )
                flag ++;
                else { }




            }
            if (Temp->mail[i] == ' ' || Temp->mail[i] == '"'  )
            {
                flag = 99;
                printf("ERROR! E_MAIL MUST NOT CONTAIN SPACES OR DOUBLE QOUTES !\n");
                  //getchar();
                break;

            }


            i++;
         }
             }
         }while (flag >= 99 || flag !=2 );
          printf("%s\n",Temp->mail);

          //getchar();
          break;

          case 3 :
           do
      {
        printf("Enter Employee's new job title: ");
        scanf("%[^\n]",Temp->job);
        printf("%s\n",Temp->job);
        fp = fopen("company.txt", "r"); // read mode
       if (fp == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }

      // printf("\nThe contents of %s file are:\n", fileName);


    m=0;
    found =0;
      while((ch = (fgetc(fp))) != '^')
	   {
	       arr[m] = ch;
	       m++;

	   }
	   arr[m] = '\0';
	  // printf("%s",arr);
	   char* token = strtok(arr, "\n");  //to validate each part alone

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
        {
          if( !(strcmpi(token,Temp->job)) )
          {
              found =1;
          }

        token = strtok(NULL, "\n");
    }
    if (found ==0)
    {
        printf("ERROR! PLEASE Enter one of job titles' in companies's database\n");
        getchar();
    }
      }while (found==0);
     getchar();
          break;


            default :
                {
                    printf("ERROR!,wrong choice");
                    return 0;

                }
           }

        printf("\n\n\"%s,%s,%s,%s,%s\"\n\n",Temp->name,Temp->num,Temp->mail,Temp->date,Temp->job);
    break;
       }
     Temp =( Temp->next);
    }

      if (Temp == NULL)
    {
        printf("EMPLOYEE NOT FOUND!\n");
       return 0;
    }





 }

///******************************************************************************SAVE FUNCTION*******************************************************
 void SAVE (void)
 {

       FILE *file_pointer;
       file_pointer = fopen("outputDataBase.txt","w+");
    node *Temp;
    Temp =head ;
int counter =0;
int i;
int j;

    node *temp;
    temp = head;

   // printf("%d",33);

   if (Temp == NULL)
    {
        printf("List is empty");
        return 0;

    }
    //printf("%s",head->name);
     while ( Temp != NULL   )
     {
         counter ++;
          Temp =( Temp->next);
          //printf("dd");
     }
     Temp = head;
     int choice;
     printf("To sort from A to Z press1 from Z to A press 2");
     scanf("%d",&choice);

    //printf("%s",head->name);
    printf("*************************IOT COMPANY***************************\n\n\n");

    if (choice ==1)
    {







    char ch = 'A';
  //  printf("\n name0 %c\n",Temp->name[0]);

    for(j=0;j<30;j++)

     {
        for(i=0;i<counter;i++)

             {

         if(Temp->name[0]==ch)
         {

            //ch = Temp->name[0];
              printf("\"%s,%s,%s,%s,%s\"\n\n",Temp->name,Temp->num,Temp->mail,Temp->date,Temp->job);
              fprintf(file_pointer,"\"%s,%s,%s,%s,%s\"\n\n",Temp->name,Temp->num,Temp->mail,Temp->date,Temp->job);


         }
         Temp = Temp->next;
           }
         ch++;
         Temp = head;

     }
    }
    else{

    char ch = 'Z';
  //  printf("\n name0 %c\n",Temp->name[0]);

    for(j=30;j>0;j--)

     {
        for(i=0;i<counter;i++)

             {

         if(Temp->name[0]==ch)
         {

            //ch = Temp->name[0];
              printf("\"%s,%s,%s,%s,%s\"\n\n",Temp->name,Temp->num,Temp->mail,Temp->date,Temp->job);
              fprintf(file_pointer,"\"%s,%s,%s,%s,%s\"\n\n",Temp->name,Temp->num,Temp->mail,Temp->date,Temp->job);


         }
         Temp = Temp->next;
           }
         ch--;
         Temp = head;

     }
    }











 }

 ///****************************************QUIT FUNCTION************************

 u8 QUIT (void)
 {
     u8 choice ;
     do
     {

     printf("To quit without saving press 1 to save then quit press 2: ");

     scanf("%d",&choice);

     switch (choice)
     {
     case 1: return 99;
     break;


     case 2:
        SAVE();
      //  Sort();
        return 99;
        break;

    default : choice = 0;


     }



     }while (choice==0);




 }

///******************************************************************SORT*****************************************
 void BSORT (void)
{

 node *Temp;
 node*temp;
node*Temp2;
Temp =head ;
int i=0;

int  counter = 0;
int j;
int ans;
printf("Please enter the sorting method\n");
	printf("for sorting from A to Z press 1\n");
	printf("for sorting from Z to A press 2 \n");
	printf("for sorting from youngest to oldest press 3\n");
	printf("for sorting from oldest to youngest press 4\n");
	scanf(" %c",&ans);
	while((ans>'4')||(ans<'1')) //checking that the ans is within the range
	{
		printf("INVALID INPUT,Please enter the sorting method\n");
		printf("1 sorting from A to Z\n");
		printf("2 sorting from Z to A\n");
		printf("3 sorting from youngest to oldest\n");
		printf("4 sorting from oldest to youngest\n");
		scanf(" %c",&ans);
	}
 if (Temp == NULL)
    {
        printf("List is empty");
        return 0;

    }
    //printf("%s",head->name);
     while ( Temp != NULL   )
     {
         counter ++;
          Temp =( Temp->next);
          //printf("dd");
     }
     Temp = head;


     while (Temp!=NULL)
     {
         //printf("\nyes\n");
         for (j=0;(j<=counter);j++)
         {
             if (Temp->next !=NULL)
             {

             Temp2 = Temp->next;
             }


        if ( Temp->name[0]<Temp2->name[0]  )
        {

           //temp = Temp;
           //Temp = Temp2;
           //Temp2 = temp;
            strcpy(temp->name,Temp->name);
            strcpy(Temp->name,Temp2->name);
            strcpy(Temp2->name,temp->name);

            strcpy(temp->date,Temp->date);
            strcpy(Temp->date,Temp2->date);
            strcpy(Temp2->date,temp->date);

            strcpy(temp->mail,Temp->mail);
            strcpy(Temp->mail,Temp2->mail);
            strcpy(Temp2->mail,temp->mail);

            strcpy(temp->job,Temp->job);
            strcpy(Temp->job,Temp2->job);
            strcpy(Temp2->job,temp->job);

   //    printf("elkber %s\n",Temp->name);
   //    printf("soghyar %s\n",temp->name);


        }
         }


     Temp =( Temp->next);
   i++;
    }
    SAVE();


//for (i=0;i<=size-1;i++)
//{
//    for (j=0;j<=size-1-i;j++)
//    {
//        if ( array[j]>array[j+1] )
//        {
//        temp = array[j];
//        array[j] = array[j+1];
//        array[j+1] = temp;
//        }
//    }
//}
//for (i=0;i<=size-1;i++)
//printf("%c ",array[i]);

//}


//    node*  searchID (linkedList *listt,u32 pID)
//    {
//    node *Temp;
//    Temp =( listt->head ) ;
//    if (Temp == NULL)
//    {
//        return NULL;
//    }
//
//     while ( Temp != NULL )
//     {
//
//
//    if ( (Temp->ID) == pID)
//
//    {
//
//
//        return Temp;
//    }
//     Temp =( Temp->next);
//    }
//
//     return NULL;
 }



//
//  void editNode ( node *patient_node,char pname[40],u32 page ,char pgender[10])
//{
//
//
//
//    strcpy(patient_node->name,pname);
//    patient_node->age = page ;
//    strcpy(patient_node->gender,pgender);
//
//
//
//}
//
//
//
//
//
///****************************************************EXTRA PRIVATE FUNCTIONS**************************************
node* addNode (void)


{
   // node *newNode;
    newNode = (node*)malloc(sizeof(node)) ;
    newNode->next = NULL;
    node*Temp;


     Temp = head;


    if (Temp==NULL) ///first NODE
    {

       head = newNode;
     // printf("first node\n");


    }
    else if ((Temp ->next) == NULL) ///second node
    {

    head-> next = newNode;


    }
    else ///appending new nodes
    {


        while (Temp->next != NULL)
    {
        Temp = Temp->next;

    }
    (Temp->next) = newNode;

    }


return newNode;

}









 u8 leapYear (u8 year)
 {


    if(year%4 == 0)
    {
        if( year%100 == 0)
        {

            if ( year%400 == 0)

                return 1;  //leap year
            else
                return 0;
        }
        else
                return 1; //leap year
    }
    else
                return 0;

    return 0;



 }


 u32 stringToDecimal (char arrayy[])
 {
     u32 dec=0;
     int i=0;
     for(i=0; i<strlen(arrayy); i++){
		dec = dec * 10 + ( arrayy[i] - '0' );
	}
	//printf("%d", dec);
	return dec;
 }


   void printList(void)
    {
    node *Temp;
    Temp =head ;
    if (Temp == NULL)
    {
        printf("List is empty");

    }
    //printf("%s",head->name);

     while ( Temp != NULL )
     {


    printf("%s\n",Temp->name);
     Temp =( Temp->next);
    }


      }

      void Sort(void)
{
	char ans;
	node*temp;
	node*temp2;
	temp=head;
	char*Job;
	FILE *fptr;
	node*ref[10]; //declared to save the addresses of each employee
	int day[10];
	int month[10];
	int year[10];
	int day2[10];
	int month2[10];
	int year2[10];
	int i,j,carry;
	int ListLength=0;

	 while ( temp != NULL   )
     {

          temp =( temp->next);
          ListLength++;
          //printf("dd");
     }
     temp = head;

	for(i=0;i<ListLength;i++) //saving all the address of all the employees
	{
	ref[i]=temp;
	temp=temp->next;
	}
	printf("Please enter the sorting method\n");
	printf("for sorting from A to Z press 1\n");
	printf("for sorting from Z to A press 2 \n");
	printf("for sorting from youngest to oldest press 3\n");
	printf("for sorting from oldest to youngest press 4\n");
	scanf(" %c",&ans);
	while((ans>'4')||(ans<'1')) //checking that the ans is within the range
	{
		printf("INVALID INPUT,Please enter the sorting method\n");
		printf("1 sorting from A to Z\n");
		printf("2 sorting from Z to A\n");
		printf("3 sorting from youngest to oldest\n");
		printf("4 sorting from oldest to youngest\n");
		scanf(" %c",&ans);
	}
	switch(ans)
	{
		case '1':
			for(i=0;i<ListLength-1;i++)
			{
				for(j=i+1;j<ListLength;j++)
				{
					if(*(ref[i]->name)>*(ref[j]->name))  //bubble sorting the addresses alphabteically according to the first character in the name field
					{
						temp2=ref[i];
						ref[i]=ref[j];
						ref[j]=temp2;
					}
				}
			}
			j=0;
			fptr=fopen("outputDataBase.txt","w");
			for(i=0;i<ListLength;i++)
			{
				fprintf(fptr,"\"");
				fprintf(fptr,"%s",ref[i]->name);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->num);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->mail);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->date);
				fprintf(fptr,",");
				for(j=0;j<(strlen(ref[i]->job));j++)
				{
					if(*(ref[i]->job+j)!='\n')
					fprintf(fptr,"%c",*(ref[i]->job+j));
				}
				fprintf(fptr,"\"");
				fprintf(fptr,"\n");
			}
			fclose(fptr);
		break;
		case '2':
			fptr=fopen("outputDataBase.txt","w");
			for(i=0;i<ListLength-1;i++) //saving all the address of all the employees
			{
				for(j=i+1;j<ListLength;j++)
				{
					if(*(ref[i]->name)<*(ref[j]->name))
					{
						temp2=ref[i];
						ref[i]=ref[j];
						ref[j]=temp2;
					}
				}
			}
			j=0;
			for(i=0;i<ListLength;i++)
			{
				fprintf(fptr,"\"");
				fprintf(fptr,"%s",ref[i]->name);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->num);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->mail);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->date);
				fprintf(fptr,",");
				for(j=0;j<(strlen(ref[i]->job));j++)
				{
					if(*(ref[i]->job+j)!='\n')
					fprintf(fptr,"%c",*(ref[i]->job+j));
				}
				fprintf(fptr,"\"");
				fprintf(fptr,"\n");
			}
			fclose(fptr);
		break;
		case '3':
			for(i=0;i<ListLength;i++)
			{
				day[i]=((*(ref[i]->date+0)-'0')*10)+(*(ref[i]->date+1)-'0');
				month[i]=((*(ref[i]->date+3)-'0')*10)+(*(ref[i]->date+4)-'0');
				year[i]=((*(ref[i]->date+6)-'0')*1000)+((*(ref[i]->date+7)-'0')*100)+((*(ref[i]->date+8)-'0')*10)+(*(ref[i]->date+9)-'0');
			}
			for(i=0;i<ListLength;i++) //sorting to the year
			{
				for(j=0;j<ListLength-i-1;j++)
				{
					if(year[j]<year[j+1])
					{
						carry=year[j];
						year[j]=year[j+1];
						year[j+1]=carry;
						temp2=ref[j];
						ref[j]=ref[j+1];
						ref[j+1]=temp2;
					}
				}
			}
			for(i=0;i<ListLength;i++) //sorting to the month
			{
				for(j=0;j<ListLength-i-1;j++)
				{
					if(year[j]==year[j+1])
					{
						if(month[j]<month[j+1])
						{
							carry=month[j];
							month[j]=month[j+1];
							month[j+1]=carry;
							temp2=ref[j];
							ref[j]=ref[j+1];
							ref[j+1]=temp2;
						}

					}
				}
			}
			for(i=0;i<ListLength;i++)//sorting to the date
			{
				for(j=0;j<ListLength-i-1;j++)
				{
					if((year[j]==year[j+1])&&(month[j]==month[j+1]))
					{
						if(day[j]<day[j+1])
						{
							carry=day[j];
							day[j]=day[j+1];
							day[j+1]=carry;
							temp2=ref[j];
							ref[j]=ref[j+1];
							ref[j+1]=temp2;
						}

					}
				}
			}
			j=0;
			fptr=fopen("outputDataBase.txt","w");
			for(i=0;i<ListLength;i++)
			{
				fprintf(fptr,"\"");
				fprintf(fptr,"%s",ref[i]->name);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->num);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->mail);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->date);
				fprintf(fptr,",");
				for(j=0;j<(strlen(ref[i]->job));j++)
				{
					if(*(ref[i]->job+j)!='\n')
					fprintf(fptr,"%c",*(ref[i]->job+j));
				}
				fprintf(fptr,"\"");
				fprintf(fptr,"\n");
			}
			fclose(fptr);
		break;
		case '4':
			for(i=0;i<ListLength;i++)
			{
				day2[i]=((*(ref[i]->date+0)-'0')*10)+(*(ref[i]->date+1)-'0');
				month2[i]=((*(ref[i]->date+3)-'0')*10)+(*(ref[i]->date+4)-'0');
				year2[i]=((*(ref[i]->date+6)-'0')*1000)+((*(ref[i]->date+7)-'0')*100)+((*(ref[i]->date+8)-'0')*10)+(*(ref[i]->date+9)-'0');
			}
			for(i=0;i<ListLength;i++) //sorting to the year
			{
				for(j=0;j<ListLength-i-1;j++)
				{
					if(year2[j]>year2[j+1])
					{
						carry=year2[j];
						year2[j]=year2[j+1];
						year2[j+1]=carry;
						temp2=ref[j];
						ref[j]=ref[j+1];
						ref[j+1]=temp2;
					}
				}
			}
			for(i=0;i<ListLength;i++) //sorting to the month
			{
				for(j=0;j<ListLength-i-1;j++)
				{
					if(year2[j]==year2[j+1])
					{
						if(month2[j]>month2[j+1])
						{
							carry=month2[j];
							month2[j]=month2[j+1];
							month2[j+1]=carry;
							temp2=ref[j];
							ref[j]=ref[j+1];
							ref[j+1]=temp2;
						}

					}
				}
			}
			for(i=0;i<ListLength;i++)//sorting to the date
			{
				for(j=0;j<ListLength-i-1;j++)
				{
					if((year2[j]==year2[j+1])&&(month2[j]==month2[j+1]))
					{
						if(day2[j]>day2[j+1])
						{
							carry=day2[j];
							day2[j]=day2[j+1];
							day2[j+1]=carry;
							temp2=ref[j];
							ref[j]=ref[j+1];
							ref[j+1]=temp2;
						}

					}
				}
			}
			j=0;
			fptr=fopen("outputDataBase.txt","w");
			for(i=0;i<ListLength;i++)
			{
				fprintf(fptr,"\"");
				fprintf(fptr,"%s",ref[i]->name);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->num);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->mail);
				fprintf(fptr,",");
				fprintf(fptr,"%s",ref[i]->date);
				fprintf(fptr,",");
				for(j=0;j<(strlen(ref[i]->job));j++)
				{
					if(*(ref[i]->job+j)!='\n')
					fprintf(fptr,"%c",*(ref[i]->job+j));
				}
				fprintf(fptr,"\"");
				fprintf(fptr,"\n");
			}
			fclose(fptr);
		break;
	}

}

