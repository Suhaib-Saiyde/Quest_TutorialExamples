#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next,*prev;
};
struct node *head=NULL,*new,*temp,*del,*tail=NULL;
int count=0;
void add();
void printh();
void printt();
void sort();
void delete();
void inter();
void main()
{
int i,n;
char a;
char c='y';
while(c=='y')
{
printf("Press 1.add	2.print		3.sort		4.delete	5.inter-add\n");
scanf("%d",&n);
	switch(n)
	{
		case 1:
			add();
			count++;
			break;
		case 2:	
			printf("printf h for head end  and t for tail end.\n");
			scanf(" %c",&a);
			if(a=='h')
			{
			printh();
			break;
			}
			if(a=='t')
			{
			printt();
			break;
			}
			break;

		case 3:
			sort();
			break;
		case 4:
			delete();
			count--;
			break;
		case 5:
			inter();
			count++;
			break;
		default:
			printf("Invalid Entry\n");
	
	}
printf("Press 'y' to Continue\n");
scanf(" %c",&c);
	if(c!='y')
	{
	printf("Completed.\n");
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
	head=tail=new;
	head->next=NULL;
	head->prev=NULL;
	}
	else
	{
	for(temp=head;temp->next!=NULL;temp=temp->next);
	temp->next=new;
	new->next=NULL;
	new->prev=temp;
	tail=new;
	}
}

void printh()
{
for(temp=head;temp!=NULL;temp=temp->next)
{
printf("%d\n",temp->data);
}
}

void printt()
{
for(temp=tail;temp!=NULL;temp=temp->prev)
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
head->prev=NULL;
free(del);
}
else if(node==count)
{
for(temp=head,i=1;i<count-1;temp=temp->next,i++);
del=temp->next;
tail=temp;
temp->next=NULL;
free(del);
}
else
{
for(temp=head,i=1;i<node-1;temp=temp->next,i++);
del=temp->next;
temp->next=del->next;
del->next->prev=temp;
free(del);
}	
}

void inter()
{
int i,node;
printf("Enter the intermediate position\n");
scanf("%d",&node);
new=(struct node*)malloc(1*sizeof(struct node));
printf("Enter the Data\n");
scanf("%d",&new->data);
for(temp=head,i=1;i<node;temp=temp->next,i++);
del=temp->next;
new->next=del;
new->prev=temp;
del->prev=new;
temp->next=new;

}

