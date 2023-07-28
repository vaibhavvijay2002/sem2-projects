/********************************************
Project Name:CUSTOMER BILLING SYSTEM
Author: Varun, Tushar , Vaibhav 
Source filename:customer.c
Date: 27-Jun-2021
*********************************************/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "header.h"

int t=0;
int k=0;
int ba=0;
int ti=0;
extern int n; // defined in billing

//This will create records in records.txt
void create()
{
	int i=0;
	FILE *fp;
	//here, we store all records
	fp=fopen("Records.txt","w");
	if(fp==NULL)
	{
		printf("Error while trying to open records.txt file \n");
	}
	//fprintf(fp,"productno\tProductName\tQuantity\tPrice\t");
	
	//printf("\t");
	printf("Enter the Number of Records:");
	scanf("%d",&n);
	printf("\n");
	FILE *fpq;
	fpq=fopen("Quantity.txt","w");
	fprintf(fpq,"%d",n);
	fclose(fpq);
	
	//get the records
	while(i<n)
	{
	    printf("\t");
		printf("Enter Product Code:");
		scanf("%d",&item.productno);
		printf("\t");
		printf("Enter Product Name:");
		scanf("%s",item.productname);
		printf("\t");
		printf("Enter Quantity:");
		scanf("%d",&item.quantity);
		printf("\t");
		printf("Enter Price:");
		scanf("%d",&item.price);
		printf("\n");
		i++;
		//printf("%d\t%s\t%d\t%d\t",item.productno,item.productname,item.quantity,item.price);
		//getch();
		fprintf(fp,"%d\t%s\t%d\t%d\t",item.productno,item.productname,item.quantity,item.price);
	}
	fclose(fp);
	printf("\t");
	printf("Records are Created");
	printf("\n");
	printf("\n");
}

//billing i.e you are buying a product
void bill()
{
	int na=0;  //used for product number in scanf function
	int qty_requested=0;	/**/
	int cont=0;
	int k=0;
	int r=0;
	int w=0;
	int ch=0;
	int l=0;	
	int bi=0;
	int ln=0;
    printf("\t");
	
	shopagain : 
	printf("Enter the Product Number:");
	scanf("%d",&na);
	printf("\n");
	
	FILE *fp;
	fp=fopen("Records.txt","r");
	
	FILE *fptr;
	fptr=fopen("temp.txt","w");
	
	while(!(feof(fp)))
	{
		l++;
		fscanf(fp,"%d",&item.productno);
		fscanf(fp,"%s",item.productname);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		
		//printf ("%d %s %d %d",item.productno,item.productname,item.quantity, item.price);
		
		// product number matches
		if(item.productno == na)
		{
			printf("Enter the Quantity:");
			scanf("%d",&qty_requested);
			
			//check for item quantity requested less than available qty
			if(qty_requested <= item.quantity)
			{
				cst[ti].productno=item.productno;
				strcpy(cst[ti].productname,item.productname);
				cst[ti].quantity=qty_requested;
				cst[ti].price=item.price;

				item.quantity=item.quantity-qty_requested;
				ti++;
				//printf ("matching record %d", ti);

				//write record to temp.txt
				fprintf(fptr,"%d\t",item.productno);
				fprintf(fptr,"%s\t",item.productname);
				fprintf(fptr,"%d\t",item.quantity);
				fprintf(fptr,"%d\t",item.price);

			}
			else
			{
				printf("Sorry Out of Stock\n");
				bi++;
			}
		} 
		else
		{
			//write record to temp.txt
			cont++;
			//printf ("not matching record %d", cont);
			fprintf(fptr,"%d\t",item.productno);
			fprintf(fptr,"%s\t",item.productname);
			fprintf(fptr,"%d\t",item.quantity);
			fprintf(fptr,"%d\t",item.price);
			//continue;
		}
		
	}
	
	if(l==cont)
		printf("Error:Choose Proper Product Number\n");
	
	fclose(fptr);
	fclose(fp);
//move from temp to records.txt
	remove("Records.txt");
	rename("temp.txt","Records.txt");
	remove("temp.txt");

	printf("\t Do you Want to Shop More:\n \t Press 1 for More\n \t Press 2 to Exit");
	scanf("%d",&k);
	if(k==1)
	{
		goto shopagain;
	}
}

//DISPLAYS THE PRODUCTS
void display()
{
	int nk=0;
	FILE *fp;

	//printf("%d no of records \n",n);

	fp=fopen("Records.txt","r");
	if(feof(fp))
	{
		printf("Error in Opening Files\n");
	}
	printf("\t");
	printf("==============================================================\n");
	printf("\t");
	printf("Product Number\tProduct Name\tQuantity\tPrice\t\n");
	printf("\t");
	printf("==============================================================\n");
	while(nk<n)
	{
		//if quantity is zero
		if(n==0)
		{
			printf("\t");
			printf("Sorry ! Everything sold out...");
			printf("\n");
			break;
		}

		nk++;
		fscanf(fp,"%d\n",&item.productno);
		fscanf(fp,"%s\n",item.productname);
		fscanf(fp,"%d\n",&item.quantity);
		fscanf(fp,"%d\n",&item.price);
		printf("\n\t%14d\t%8s\t%8d\t%d\n",item.productno,item.productname,item.quantity,item.price);
		printf("\n");
	}
	fclose(fp);
}
void edit()
{
	FILE *fp;
	FILE *fptr;
	FILE *fpk;
	int h;
	int found=0;
	int ka=0;
	int p;
	fp=fopen("Records.txt","r");
	fptr=fopen("temp1.txt","w");
	fpk=fopen("temp2.txt","w");
	printf("\t");
	printf("Enter the Product Number to Delete: ");
	scanf("%d",&h);
	printf("\n");
	p=n;
	while(!(ka==p))
	{
		ka++;
		fscanf(fp,"%d",&item.productno);
		if(item.productno==h)
		{
			found=1;
			fscanf(fp,"%s",item.productname);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			n--;
			printf("\t");
			printf("Product has been Successfully Deleted\n");
		}
		else
		{
			fscanf(fp,"%s",item.productname);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			fprintf(fptr,"%d\t%s\t%d\t%d\t",item.productno,item.productname,item.quantity,item.price);
		}
	}
	fprintf(fpk,"%d",n);
	fclose(fpk);
	fclose(fptr);
	fclose(fp);
	if(found==0)
	{
	    printf("\t");
		printf("Product no Found");
		printf("\n");
		printf("\n");
	}
	remove("Quantity.txt");
	rename("temp2.txt","Quantity.txt");
	remove("Records.txt");
	rename("temp1.txt","Records.txt");
}

void invoice()
{
	int j;
	int o;
	float gt=0;
	if(ti==0)
	{
		printf("There are No Products in your Cart");
		printf("\n");
	}
	printf("\n\n");
	printf("****************************INVOICE**************************");
	printf("\n\n");
	printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
	printf("*************************************************************\n");
	for(o=0;o<ti;o++)
	{
		cst[o].amount=0;
		cst[o].amount=((cst[o].price)*(cst[o].quantity));
		gt=gt+cst[o].amount;
	}
	for(j=0;j<ti;j++)
	{
		printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",cst[j].productno,cst[j].productname,cst[j].price,cst[j].quantity,cst[j].amount);
	}
	printf("\nAmount Payable:%f",gt);
	printf("\n");
	printf("Thank you for Shopping");
	printf("\n");
	printf("Visit Again");
	printf("\n");
}

void mdelete()
{
	int i=0;
	int j=0;
	int f=0;
	int g=0;
	int ag=0;
	int aj=0;
	char ab[100];
	FILE *fw;
	FILE *fq;
	printf("\t");
	printf("Enter the Product Number to be Deleted:");
	scanf("%d",&f);
	printf("\n");
	for(i=0;i<ti;i++)
	{
		if(cst[ti].productno==f)
		{
			aj=cst[i].quantity;
			printf("\t");
			printf("Product Deleted Successfully");
			printf("\n");
		}
		continue;
		cstr[g].productno=cst[i].productno;
	  	strcpy(cstr[g].productname,cst[i].productname);
	  	cstr[g].quantity=cst[i].quantity;
	  	cstr[g].price=cst[i].price;
	  	g++;
	}
	for(j=0;j<g;j++)
	{
		cst[j].productno=cstr[j].productno;
 	 	strcpy(cst[j].productname,cstr[j].productname);
	  	cst[j].quantity=cstr[j].quantity;
	  	cst[j].price=cstr[j].price;
	}
	ti=g;
	printf("\n%d",aj);
	fq=fopen("shop.txt","r");
	fw=fopen("temp4.txt","w");
	for(j=0;j<n;j++)
	{
		fscanf(fq,"%d",&item.productno);
		fscanf(fq,"%s",item.productname);
		fscanf(fq,"%d",&item.quantity);
		fscanf(fq,"%d",&item.price);
		if(item.productno==f)
		{
		    ag=aj+item.quantity;
            fprintf(fw,"%d\t%s\t%d\t%d\t",item.productno,item.productname,ag,item.price);
        }
        else
        {
        	fprintf(fw,"%d\t%s\t%d\t%d\t",item.productno,item.productname,item.quantity,item.price);
        }
	}
	fclose(fq);
	fclose(fw);
	remove("Records.txt");
	rename("temp4.txt","Records.txt");
}

void mdisplay()
{
	int i;
	int j;
	int o;
	printf("================================================================================\n");
	printf("product number\t|product name\t|quantity\t|price\t\n");
	printf("================================================================================\n");
	for(o=0;o<ti;o++)
	{
		printf("%14d\t|%12s\t|%6d\t|%6d\n",cst[o].productno,cst[o].productname,cst[o].quantity,cst[o].price);
	}
}

void csearch(char b[])
{
	char a[11];
	FILE*f2=fopen("customer.txt","r");
	printf("\tEnter the customer phone no: \n");
	printf("\n");
	printf("\t");
	scanf("%s",a);
	while(!feof(f2))
	{
		char name[50],add[100], no[11];
		fscanf(f2,"%s\t%s\t%s\n",name,no,add);
		if(strcmp(a,no))
		{
			strcpy(b, name);
			break;
		}
	}
	fclose(f2);
	//return name1;
}

void registerUser(char f[])
{
	//char name1[50];
	FILE*f1=fopen("customer.txt","a");
	struct customer_details nc;

	printf("\tEnter the customers name:\n");
        printf("\n");
	printf("\t");
	scanf("%s",nc.customer_name);
	//fflush(stdin);
	strcpy(f, nc.customer_name);


	printf("\tEnter the customers phone number:\n");
        printf("\n");
	printf("\t");
	scanf("%s",&nc.customer_phno);
	//fflush(stdin);

	printf("\tEnter the customer's city or place:\n");
        printf("\n");
	printf("\t");
	scanf("%s",nc.address);
	//fflush(stdin);

	printf("=============================================================================================\n");
	fprintf(f1,"\t%s\t%s\t%s\n",nc.customer_name,nc.customer_phno,nc.address);
	printf("==================Thank you for registering as our new customer==============================\n");
	fclose(f1);

}
