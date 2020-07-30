#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int z=1;
struct node *start;
struct node
{
    struct node *next;
    int c_no,p,del;
    char firstName[10];
    char lastName[10];
    char Address[20];
    float previousamount;
    float presentamount;
    struct node *prev;
};

void edit(int cno)
{

	char fn[10],ln[10],addr[20];
	float currentbalance,removebalance;
	struct node *ptr;
	ptr=start;
       while(ptr->c_no!=cno)
       {
       ptr=ptr->next;
       }
	printf("Fill up the following: \n");
	flushall();
	printf("First Name: ");
	scanf("%s",&fn);
	printf("Last Name: ");
	scanf("%s",&ln);
	puts(ln);
	puts(fn);
	printf("Address: ");
	 gets(addr);
	 y:
	  printf("Previous amount: ");
	  scanf("%f",&currentbalance);
	  printf("Present amount: ");
	  scanf("%f",&removebalance);
	  if(removebalance<currentbalance)
	  {
	  printf("\nInvalid amount entered enter again\n");
	  goto y;
	  }

	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->firstName[10]=fn[10];
	ptr->lastName[10]=ln[10];
	ptr->Address[20]=addr[20];
	ptr->previousamount=currentbalance;
	ptr->presentamount=removebalance;
	ptr->p=0;


}
void create()
{
	struct node *temp,*ptr;
	struct node bill;
	int num,h;
	char fn[10],ln[10],addr[20];
	float currentbalance=0,removebalance;
	do
	{
	printf("\nEnter 1 to enter a user\nor 2 to stop adding\n");
	scanf("%d",&h);
	 switch(h)
	 {
	   case 1:
	   {
	  printf("Fill up the following details: \n");
	  flushall();
	  printf("First Name: ");
	  gets(fn);
	  printf("Last Name: ");
	  gets(ln);
	  puts(ln);
	  puts(fn);
	  printf("Address: ");
	  gets(addr);
	  d:
	  printf("enter the balance: ");
	  scanf("%f",&currentbalance);
	  printf("enter the amount to remove: ");
	  scanf("%f",&removebalance);
	  if(removebalance<currentbalance)
	  {
	  printf("\nInvalid balance entered\nremovebalance cannot be greatrer than currentbalance\n enter again\n");
	  goto d;
	  }
	  if(start==NULL)
	  {
			temp=(struct node*)malloc(sizeof(struct node));
			temp->prev=NULL;
			temp->c_no=z;
			printf("\nCustomer number is %d\n",z);
			z++;
			temp->firstName[10]=fn[10];
			temp->lastName[10]=ln[10];
			temp->Address[20]=addr[20];
			temp->previousamount=currentbalance;
			temp->presentamount=removebalance;
			temp->p=0;
			temp->del=0;
			temp->next=NULL;
			start=temp;
		}
		else
		{
			ptr=start;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->c_no=z;
			printf("\nCustomer number is %d\n",z);
			z++;
			temp->firstName[10]=fn[10];
			temp->lastName[10]=ln[10];
			temp->Address[20]=addr[20];
			temp->p=0;
			temp->del=0;
			temp->previousamount=currentbalance;
			temp->presentamount=removebalance;
			while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next=temp;
			temp->prev=ptr;
			temp->next=NULL;
		}}break;
		case 2:
		break;
		default:
		printf("Invalid input\n");
		break;
	      }	}while(h!=2);

   }
void delete_(int cno)
{
	struct node *ptr;

    if(cno>z)
     {
      printf("User doesnt exist\n");
    }
   else
   {
	ptr=start;
	while(ptr->c_no!=cno)
	ptr=ptr->next;
    ptr->del=1;
    }

}

void withdraw(int cno)
{ int bc;
   struct node *ptr;
	if(cno<=z)
	{
	ptr=start;
	while(ptr->c_no!=cno)
	ptr=ptr->next;
	}
    else if(cno>z)
     {
      printf("User doesnt exist\n");
     }
    else
    {

     printf("\nCustomer no.- %d\n",ptr->c_no);
		flushall();
		printf("Name-");
		puts(ptr->firstName);
		printf(" ");
		puts(ptr->lastName);
		printf("\nAddress-\n");
		puts(ptr->Address);
		printf("current balance%f",ptr->previousamount);
	       // puts(ptr->previousamount);
      z:
      printf("enter the amount to withdraw");
      scanf("%d",&bc);
      if(ptr->previousamount<bc)
      {
       printf("your account has low balancen enter again");
       goto z;
      }
      else
       {
         ptr->previousamount=ptr->previousamount-bc;
        printf("current balance=%f",ptr->previousamount);
       }  
      }
 }

void display(int cno)
{       int dc;
	struct node *ptr;
	if(cno<=z)
	{
	ptr=start;
	while(ptr->c_no!=cno)
	ptr=ptr->next;
	}
    if(cno>z)
     {
      printf("User doesnt exist\n");
    }
    else if(ptr->del==1)
    {
    printf("User subscription terminated \nto subscribe again press 1  else press 2\n");
    scanf("%d",&dc);
    if(dc==1)
    {
    ptr->del=0;
    printf("User subscription revoked");
    }

    }
   else
{
		printf("\nCustomer no.- %d\n",ptr->c_no);
		flushall();
		printf("Name-");
		puts(ptr->firstName);
		printf(" ");
		puts(ptr->lastName);
		printf("\nAddress-\n");
		puts(ptr->Address);

		if(ptr->p==0)
		{
		printf("\nBill is not paid\n");
		}
		else
		{
		printf("\nBill is paid\n");
		}

}}

void insert_end()
{
	struct node *ptr,*temp;

	char fn[10],ln[10],addr[20];
	float currentbalance,removebalance;
	printf("Fill up the following: \n");
	flushall();
	printf("First Name: ");
	gets(fn);
	printf("Last Name: ");
	gets(ln);
	puts(ln);
	puts(fn);
	printf("Address: ");
	 gets(addr);
	 k:
	  printf("enter the amount to deposit in bank ");
	  scanf("%f",&currentbalance);
	  printf("Present amount: ");
	  scanf("%f",&removebalance);
if(currentbalance<removebalance)
	  {
	  printf("\nInvalid amount entered \nprevious amount cannot be greater than present amount\nenter again\n");
	  goto k;
	  }



	temp=(struct node*)malloc(sizeof(struct node));
	temp->c_no=z;
	printf("\nCustomer number is %d\n",z);
	z++;
	temp->firstName[10]=fn[10];
	temp->lastName[10]=ln[10];
	temp->Address[20]=addr[20];
	temp->p=0;
	temp->del=0;
	temp->previousamount=currentbalance;
	temp->presentamount=removebalance;

	ptr=start;
	while(ptr->next!=NULL)

		ptr=ptr->next;
		ptr->next=temp;
		temp->next=NULL;
}
int main()
{       struct node bill,*ptr;
	int ch,x,cno,q,dc;
	clrscr();
	printf("BANK MANAGEMENT SYSTEM\n");
	printf("Create a Database\n\n");
	create();
	do
	{     printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n1.Already a customer\n2.New customer\n3.Exit\n");
	      scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n\n\n   1.delete the user\n   2.Edit details\n   3.View user data\n 4.withdraw money\n  5.Back\n");
			       scanf("%d",&x);

				   if(x==1)
				   {
				    printf("Enter customer ID-");
				    scanf("%d",&cno);
				    if(cno<=z && cno>0)
				    {
				    ptr=start;
				    while(ptr->c_no!=cno)
				    ptr=ptr->next;


				    }
				 if(cno>z)
				 {
				   printf("This customer number does not exist");
				 }
				 else if(ptr->del==1)
				 {
				 printf("User subscription is already canceled press 1 to subscribe again\n or press 2 to go back");
				 scanf("%d",&dc);
				 if(dc==1)
				 {
				 ptr->del=0;
				 printf("Subscription revoked\n ");
				 }
				 }
				 else
				 {
			       delete_(cno);
				printf("User subscription canceled");
				}

				   

				

				  }
			       else if(x==2)
				 {

				 printf("Enter customer no.");
				scanf("%d",&cno);
				edit(cno);

				 }
				   else if(x==3)
				 {
				printf("Enter customer no.");
				scanf("%d",&cno);
				display(cno);

				     }
                                   
				   else if(x==4)
				   {
				    printf("Enter customer ID-");
				    scanf("%d",&cno);
				    withdraw(cno);
				    }

				 else if(x!=5)
				 {
				 printf("Invalid input\n");

				 }
                                  break;
			case 2:insert_end();
				break;
			default:
			printf("Invalid input\n");
			break;
		}
	}while(ch!=3);
	return 0;
}