/*this program is a implementation of simple queue */

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct
{
	int front,rear;
	int item[MAX];
}queue;
void insert(queue *qptr,int add)
{
	if(qptr->rear!=MAX-1)
	{
		qptr->rear=qptr->rear+1;
		qptr->item[qptr->rear]=add;
		printf("\n insert successful \n");
		if(qptr->front==-1)
			qptr->front=0;
	}
	else
		printf("Queue is full");
}
void delete(queue *qptr)
{
//	int item;
	if(qptr->front>=0)
	{
		printf("%d\n",qptr->item[qptr->front]);
		qptr->item[qptr->front]=0;
		if(qptr->front==qptr->rear)
		{
			qptr->front=qptr->rear=-1;

		}
		else
			qptr->front=qptr->front+1;
//		return item;
        printf("delete successful\n");
	}
	else
	{
		printf("Not Entered any data\n");
//		return NULL;
	}
}
void main()
{
	queue qptr;
	int data=0,sel,i;
	qptr.front=-1;
	qptr.rear=-1;
	printf("this program is a implementation of simple queue\n");
	while(1)
	{
		printf("1).\tAdd data\n2).\tRetrieve data\n3).\tExit\n");
		printf("Enter your choice : ");
		scanf("%d",&sel);
		if(sel==1)
	//	for(i=0;i<5;i++)
		{
		    printf("enter data : ");
			scanf("%d",&data);
			insert(&qptr,data);
		}
		else if(sel==2)
	//	for(i=0;i<5;i++)
		{
			delete(&qptr);
//			printf("%d\n",data);
		}
		else if(sel==3)
			exit(1);
		else
			printf("You entered incorrect value");
	}
}




