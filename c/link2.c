#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL,*new,*temp,*del;
int count=0;
void add();
void print();
void sort();
void delete();
void main()
{
int i,n;
char c='y';
while(c=='y')
{
printf("Press 1.add	2.print		3.sort		4.delete\n");
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
		case 3:
			sort();
			break;
		case 4:
			delete();
			count--;
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
void sort()
{
int i,x;
for(i=0;i<count;i++)
{
	for(temp=head;temp->next!=NULL;temp=temp->next)
	{
		if(temp->data>temp->next->data)
		{
		x=temp->data;
		temp->data=temp->next->data;
		temp->next->data=x;
		}
	}
}
}
void delete()
{
int i,node;
printf("Enter the node number to be deleted.\n");
scanf("%d",&node);
if(node==1)
{
del=head;
head=del->next;
free(del);
}
else if(node==count)
{
for(temp=head,i=1;i<count-1;temp=temp->next,i++);
del=temp->next;
temp->next=NULL;
free(del);
}
else
{
for(temp=head,i=1;i<node-1;temp=temp->next,i++);
del=temp->next;
temp->next=del->next;
free(del);
}	

}

