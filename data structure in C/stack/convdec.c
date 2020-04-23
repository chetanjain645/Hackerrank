/*this program is a implementation of number system */

#include<stdio.h>
#include<stdlib.h>
#define stacksize 20
typedef struct
{
	int top;
	int item[stacksize];
}stack;
void push(stack *ptr,int p)					/*Function for push element to stack*/
{
	ptr->top++;
	ptr->item[ptr->top]=p;
}
int pop(stack *ptr)						/*Function for pop element to stack*/
{
	int p;
	p=ptr->item[ptr->top];
	ptr->top--;
	return p;
}
int main()
{
	int rem,num,n;
	stack ptr;
	ptr.top=-1;						/*Assign value for top*/
	printf("This program is for convert decimal to binary, octal or hexadecimal as per your choice\n\n");
	while(1)
	{   printf("Choose one\n");
	    printf("1. Convert to Binary\n2. Convert to Octal\n3. Convert to Hexadecimal\n4. Exit\n");
		printf("Select your choice:\t");
		scanf("%d",&n);						/*Scan choice for user*/
		printf("Enter the number for convert:");
		scanf("%d",&num);					/*Scan no. we need to convert which*/

		switch(n)						/*Checking user's choice */
		{
			case 1:						/*If user want to convert into binary*/
				printf("Your Decimal number %d converted to Binary is ",num);
				while(num!=0)
				{
					rem=num%2;
					push(&ptr,rem);
					num=num/2;
				}
				break;
			case 2:						/*If user want to convert into octal*/
				printf("Your Decimal number %d converted to Octal is ",num);
				while(num!=0)
				{
					rem=num%8;
					push(&ptr,rem);
					num=num/8;
				}
				break;
			case 3:						/*If user want ot convert into hexadecimal*/
				printf("Your Decimal number %d converted to Hexadecimal is ",num);
				while(num!=0)
				{
					rem=num%16;
					push(&ptr,rem);
					num=num/16;
				}
				break;
			case 4:
				exit(1);
			default:
				printf("Selected incorrect option............");
		}
		while(ptr.top!=-1)					/*Loop for pop until stack doesn't empty*/
		{
			num=pop(&ptr);
			switch(num)			/*Switched case for popped element because in hexadecimal after 10 is changed with alphabet*/
			{
				case 10:
					printf("A");
					break;
				case 11:
					printf("B");
					break;
				case 12:
					printf("C");
					break;
				case 13:
					printf("D");
					break;
				case 14:
					printf("E");
					break;
				case 15:
					printf("F");
					break;
				default:
					printf("%d",num);
			}
		}
		printf("\n");
	}
	return 0;
}

