/* this is a program of linked list as a queue */

#include<stdio.h>
#include<stdlib.h>
struct node                              //definition of linked list
{
	int item;
	struct node *next;
};
struct node *START=NULL;

void insertnode()                       //insert process
{
	struct node *temp,*t;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter a number for add it in linked list:\t");
	scanf("%d",&temp->item);
	printf("\n%d has been added to linked list.\n",temp->item);
	temp->next=NULL;
	if(START==NULL)
		START=temp;
	else
	{
		t=START;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
}
void deletenode()                              //delete the node
{
	struct node *t;
	if(START==NULL)
		printf("\nList is empty\n");
	else
	{
		t=START;
		START=START->next;
		printf("\n%d has been deleted.\n",t->item);
		free(t);
	}
}
void viewList()                                   //print the list
{
	struct node *t;
	if(START==NULL)
		printf("\nList is empty\n");
	else
	{
		t=START;
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
	printf("\nThis Programs is a implementation of linked list as a queue\n");
	printf("\n1. Add value in the list");
	printf("\n2. Delete first value");
	printf("\n3. View list");
	printf("\n4. Exit");
	printf("\n\nEnter your choice : \t");
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
				insertnode();
				break;
			case 2:
				deletenode();
				break;
			case 3:
				viewList();
				break;
			case 4:
                exit(0);
			default:
				printf("Invalid Choice\n");
                break;
		}
	}
}



