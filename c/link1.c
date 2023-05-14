#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL,*new,*temp;
int count=0;
void add();
void print();
void main()
{
int i,n;
char c='y';
while(c=='y')
{
printf("Press 1.add	2.print\n");
scanf("%d",&n);
	switch(n)
	{
		case 1:
			add();
			count++;
			break;
		case 2:
			print();
			break;
		default:
			printf("Invalid Entry\n");
	
	}
printf("Press 'y' to Continue\n");
scanf(" %c",&c);
	if(c!='y')
	{
	printf("Entry Completed.\n");
	break;
	}
}
}
void add()
{
new=(struct node*)malloc(1*sizeof(struct node));
printf("Enter the Data\n");
scanf("%d",&new->data);
	if(head==NULL)
	{
	head=new;
	head->next=NULL;
	}
	else
	{
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=new;
	new->next=NULL;
	}
}
void print()
{
for(temp=head;temp!=NULL;temp=temp->next)
{
printf("%d\n",temp->data);
}
}
