/********************************************
Project Name:CUSTOMER BILLING SYSTEM
Author: Varun
        Tushar 
Source filename:billingsystem.c
Date: 27-Jun-2021
*********************************************/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "header.h"

int n=0; //used in Quantity and Records.txt

int main()
{
	char ch,password[10],name1[50];
	char q[10]="demo12"; // password for admin
	int s=0;
	int y=0;
	int w=1;
	int i,h;
	FILE *fpe;
	
	//HAS TOTAL QUANTITY IN HERE
	fpe=fopen("Quantity.txt","r");
	fscanf(fpe,"%d",&n);
	fclose(fpe);
	
	// GENERAL DISPLAY
	printf("\n");
	printf("************************************************************************************************************************");
	printf("\n");
	printf("*****************************************    WELCOME TO PES BILLING SYSTEM**********************************************");
	printf("\n");
	printf("\t                               YOU ARE LUCKY TO BE SHOPPING HERE");
	printf("\n\n");
	printf("\t\t\tPlease note that all the Product's Price are Discounted and are Genuine");
	printf("\n");
	printf("\t\t\t\t\t");
    printf("      TOTAL ITEMS AVALAILABLE FOR SALE: %d\n",n);
	printf("\n");
	printf("************************************************************************************************************************");
    
	//REPEAT HERE IF INVALID PASSWORD
	q: printf("\n\t");
    printf("****************************");
    printf("\n");
    printf("\t");
    printf("Please Select an Option: ");
    printf("\n");
    printf("\t");
    printf("****************************");
    printf("\n");
    printf("\t");
	printf("01. ADMINISTRATOR");
	printf("\n\t");
	printf("02. CUSTOMER");
	printf("\n\t");
	printf("03. EXIT");
	printf("\n");
	printf("\n\t");
	printf("Please Enter an Option: ");
	scanf("%d",&s);

	switch(s)
	{
	          case 1: printf("\tEnter Password:\t");
              //GET PASSWORD 
			  for(i=0;i<6;i++)
              {
				  ch = getch();
				  password[i] = ch;
				  ch = '*' ;
     			  printf("%c",ch);
			  }
              password[i]='\0';
              if(strcmp(password,q))
              {
                  printf("\n\t");
				  printf("Wrong Password Please Try Again");
				  printf("\n\n");
				  goto q;
			 }
             else
			   //CONTINUE  ADMIN MENU 
               goto l3;
		   
               l3: printf("\n\t");
               printf("Access Granted\n");
               printf("\n\n");
               printf("\t");
               printf("****************************");
               printf("\n");
               printf("\t");
               printf("Please Select an Option: ");
               printf("\n");
               printf("\t");
               printf("****************************");
               printf("\n");
		       printf("\t01.CREATE");
		       printf("\n\t");
		       printf("02.DELETE/MODIFY");
		       printf("\n\t");
		       printf("03.DISPLAY");
		       printf("\n\t");
		       printf("04.MAIN MENU");
		       printf("\n");
		       printf("\n");
		       printf("\t");
		       printf("Please Enter an Option: ");
		        scanf("%d",&y);
		        switch(y)
		        {
        			case 1:create();
        			      goto q;
  			      case 2:edit();
  			             goto q;
                  case 3:display();
                         goto q;
                  case 4: goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         break;

       case 2: printf("\t 1) Old customer\n\t 2) New customer\n");
               printf("\n");
               printf("\t");
               scanf("%d",&h);
               switch(h)
               {
                   case 1: csearch(name1);
                           break;
                   case 2: registerUser(name1);
                           break;
                   default : goto q;
               }		
	       printf("\n");
               printf("\t");
               printf("****************************");
               printf("\n");
               printf("\t");
               printf("Plese Select an Option: ");
               printf("\n");
               printf("\t");
               printf("****************************");
               printf("\n");
               printf("\t");
               printf("01.BILL");
               printf("\n\t");
               printf("02.INVOICE");
               printf("\n\t");
               printf("03.DISPLAY");
               printf("\n\t");
               printf("04.MYCART");
               printf("\n\t");
               printf("05.MAIN MENU");
               printf("\n\t");
               printf("06.DELETE ITEMS IN CART\n");
               printf("\n\t");
               printf("Please Enter an Option: ");
               scanf("%d",&y);
               printf("\n");
               switch(y)
		        {
                    case 1 : bill();
        		     goto q;

                    case 2 : invoice();
                             goto q;

                    case 3 : display();
                             goto q;

                    case 4 : mdisplay();
                             goto q;

                    case 5 : goto q;

                    case 6 : mdelete();
                             goto q;

                    default : printf("Error\n");
                              goto q;
        		}
		         break;
      case 3: printf("\t Thank you for shopping. Hope to see you again !!!\n");
      break;
      default : printf("INVALID INPUT\n");
      break;
	}
}

