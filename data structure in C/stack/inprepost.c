/*this program is the implementation of infix to prefix and infix to postfix */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct
{
	int top;
	char item[MAX];
}stack;
void push(stack *ptr,char p)			//Insert an element to stack
{
	ptr->top++;
	ptr->item[ptr->top]=p;
}
char pop(stack *ptr)				//Access an element from last of stack and delete it
{
	char p;
	p=ptr->item[ptr->top];
	ptr->top--;
	return p;
}
int pr(char elem)				//Checking priority of +,-,*,/
{
    switch(elem)
    {
	    case ')': return 1;
	    case '+': return 2;
	    case '-': return 2;
	    case '*': return 3;
	    case '/': return 3;
    }
}
char *strrev(char *str)				//Function for reverse string
{
    if (!str || !*str)
        return str;
    int i=strlen(str)-1,j=0;
    char ch;
    while(i>j)
    {
        ch=str[i];
        str[i]=str[j];
        str[j]=ch;
        i--;
        j++;
    }
    return str;
}
int prepost(stack *stk,char infix[],int sel)			//Function for converting infix to prefix or postfix per user's choice
{
	int i,j;
	char prepos[MAX];
	j=0;
	if(sel==1)				//Converting infix to prefix
	{
		for(i=0;infix[i]!='\0';i++)
		{
			if(infix[i]==')')
				push(stk,infix[i]);
			else if(infix[i]=='(')
			{
				while(stk->item[stk->top]!=')')
					prepos[j++]=pop(stk);
				pop(stk);
			}
			else if(isdigit(infix[i]))
				prepos[j++]=infix[i];

			else
			{
				while(pr(stk->item[stk->top])>pr(infix[i]))
					prepos[j++]=pop(stk);
				push(stk,infix[i]);
			}
		}
	}
	else if(sel==2)				//Converting infix to postfix
	{
		for(i=0;infix[i]!='\0';i++)
		{
			if(infix[i]=='(')
				push(stk,infix[i]);
			else if(infix[i]==')')
			{
				while(stk->item[stk->top]!='(')
					prepos[j++]=pop(stk);
				pop(stk);
			}
			else if(isdigit(infix[i]))
				prepos[j++]=infix[i];

			else
			{
				while(pr(stk->item[stk->top])>=pr(infix[i]))
					prepos[j++]=pop(stk);
				push(stk,infix[i]);
			}
		}
	}
	while(stk->top!=-1)			//Pop element until it become empty
		prepos[j++]=pop(stk);
	if(sel==1)
	{
		strrev(prepos);
		prepos[j]='\0';			//Create a valid string
		printf("\nGiven Infix Expression\t%s\tconverted to Prefix Expression\t%s\n\n",strrev(infix),prepos);
	}
	else if(sel==2)
	{
		prepos[j]='\0';			//Create a valid string
		printf("\nGiven Infix Expression\t%s\tconverted to Postfix Expression\t%s\n\n",infix,prepos);
	}
	return 0;
}
void main()
{
	stack stk;
	stk.top=-1;
	int sel;
	char infix[MAX];
	printf("\tThis program converts entered infix expression to prefix or postfix as per ur choice.\n\n");
	while(1)					//Loop until user doesn't exit
	{

		printf("1)\tFor Convert Infix to Prefix\n2)\tFor Convert Infix to Postfix\n3)\tFor Exit\nSelect Your Choice:\t");
		scanf("%d",&sel);
		if(sel==3)
		{
			printf("\n\n");
			exit(1);
		}
		printf("Type Infix Expression:-\t");
		scanf("%s",infix);			//Scanning infix expression
		if(sel==1)
		{
			strrev(infix);			//Reverse infix expression
			prepost(&stk,infix,sel);	//Function for convert to prefix
		}
		else if(sel==2)
			prepost(&stk,infix,sel); 	//Function for convert to postfix
		else
			printf("You select incorrect choice...\n\nPlease choose again\n");
	}
}





