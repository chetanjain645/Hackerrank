/* this is the program of Circular queue */

#include<stdio.h>
#include<stdlib.h>
#define MAX 3
typedef struct
{
	int front,rear;
	int item[MAX];
}queue;
void insert(queue *qptr,int add)							//Function for insert element
{
	if((qptr->rear==MAX-1&&qptr->front==0)||(qptr->rear==qptr->front-1))		//Check, Queue is Full
		printf("Sorry,Queue is full. Your data (%d) is not inserted.\n\n",add);
	else										//If Queue is not Full then insert element in queue
	{
		if(qptr->rear==MAX-1&&qptr->front>0)
		{
			qptr->rear=0;
			qptr->item[qptr->rear]=add;			//Add integer in our queue
		}
		else
		{
			qptr->rear=qptr->rear+1;
			qptr->item[qptr->rear]=add;			//Add integer in our queue
			if(qptr->front==-1)
				qptr->front=0;
		}
		printf(" Item %d inserted....\n\n",add);
	}
}
void delete(queue *qptr)								//Function for delete element from front in queue
{
	if(qptr->front==-1)								//Check, Queue is empty
		printf("Not Entered any data....\n\n");
	else										//If not empty then delete an element from queue
	{
		printf("Item %d deleted....\n\n",qptr->item[qptr->front]);
		qptr->item[qptr->front]=0;
		if(qptr->front==qptr->rear)
			qptr->front=qptr->rear=-1;
		else if(qptr->front==MAX-1)
			qptr->front=0;
		else
			qptr->front=qptr->front+1;
	}
}
void main()
{
	queue qptr;
	int data=0,sel,i;
	qptr.front=-1;					//Assign value to front
	qptr.rear=-1;					//Assign value to rear
	printf("\tThis program is for CIRCULAR QUEUE and limit of queue is 10\n\n");
	//printf("Select your choice\n\n");
	while(1)					//Loop until user does not exit
	{
		printf("1).\tAdd data\n2).\tRetrieve data\n3).\tExit\n");
		printf("enter your choice : ");
		scanf("%d",&sel);
		if(sel==1)
		{
		    printf("Enter data  : ");
			scanf("%d",&data);
			insert(&qptr,data);		//Call insert function for add data queue
		}
		else if(sel==2)
			delete(&qptr);			//Call delete function for delete data from queue
		else if(sel==3)
		{
			printf("\n\n");
			exit(1);
		}
		else
			printf("\nYou entered incorrect value....\n\n");
		printf("Select your choice again....\n\n");
	}
}




