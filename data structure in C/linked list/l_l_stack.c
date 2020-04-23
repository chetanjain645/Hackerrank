/* this is a program of linked stack */


#include"stdio.h"
#include<stdlib.h>
struct node                         //definition of a linked list
{
	int item;
	struct node *next;
};
struct node *start = NULL;
void insert()                       //insert element in a list
{
	struct node *temp,*t;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter a number for add it in linked list:\t");
	scanf("%d",&temp->item);
	printf("\n%d has been added to linked list.\n",temp->item);
	temp->next=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		t=start;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
}
void delete()                           //delete a element
{
	struct node *t;
	if(start==NULL)
		printf("\nList is empty\n");
	else
	{
		t=start;
		while((t->next)->next!=NULL)
			t=t->next;
		printf("\nItem %d has been deleted.\n",(t->next)->item);
		free(t->next);
		t->next=NULL;
	}
}
void traverse()                     //traversing
{
	struct node *t;
	if(start==NULL)
		printf("\nList is empty\n");
	else
	{
		t=start;
		while(t!=NULL)
		{
			printf("%d\t",t->item);
			t=t->next;
		}
		printf("\n");
	}
}
int menu()
{
	int ch;
	printf("\nThis Programs is a implementation of linked list as a stack\n");
	printf("\n1. Add value in the list");
	printf("\n2. Delete first value");
	printf("\n3. Traversing");
	printf("\n4. Exit");
	printf("\n\nEnter your choice\t");
	scanf("%d",&ch);
	return(ch);
}
void main()
{
	while(1)
	{
		switch(menu())
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				traverse();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
				break;
		}
	}
}
