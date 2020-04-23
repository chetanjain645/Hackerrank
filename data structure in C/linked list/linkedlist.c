/*this is a program of simple linked list */

#include<stdio.h>
#include<stdlib.h>
struct node                                     //definition of single linked list
{
int info;
struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);

int main()
{
    struct node *start="NULL";
    int choice,data,item,pos;
    while(1)
    {
        printf("\t \n THIS IS THE IMPLEMENTATION OF SINGLE LINKED LIST \t \n");
        printf("1. create List \n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Add to empty list OR Add to beginning \n");
        printf("6. Add at end\n");
        printf("7. Add after node\n");
        printf("8. Add before node\n");
        printf("9. Add at position \n");
        printf("10. Delete  \n");
        printf("11. Reverse \n");
        printf("12. Quit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            count(start);
            break;
        case 4:
            printf("Enter the element you want to search : ");
            scanf("%d",&data);
            search(start,data);
            break;
        case 5:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            start = addatbeg(start,data);
            break;
        case 6:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            start = addatend(start,data);
            break;
        case 7:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            printf("enter the element after which you want to insert : ");
            scanf("%d",&item);
            start = addafter(start,data,item);
            break;
        case 8:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            printf("enter the element before which you want to insert : ");
            scanf("%d",&item);
            start = addbefore(start,data,item);
            break;
        case 9:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            printf("enter the position at which you want to insert : ");
            scanf("%d",&pos);
            start = addatpos(start,data,pos);
            break;
        case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start = del(start,data);
            break;
        case 11:
            start = reverse(start);
            break;
        case 12:
            exit(1);
        default :
            printf("wrong choice try again \n");
            break;

        }
    }
    return 0;
}

struct node *create_list(struct node *start)                        //create the list
{
    int i,n,data;
    printf("enter the number of nodes : ");
    scanf("%d",&n);
    start = "NULL";
    if(n==0)
    {
        return start;
    }
    printf("Enter the element to be insert : ");
    scanf("%d",&data);
    start = addatbeg(start,data);
    for(i=2;i<=n;i++)
    {
        printf("enter the element to be insert : ");
        scanf("%d",&data);
        start = addatend(start,data);
    }
    return start;
} //End of creation...

void display(struct node *start)                                    //print the linked list
{
    struct node *p;
    int cnt=1;
    if(start == "NULL")
    {
        printf("List is empty \n");
        return ;
    }
    p=start;
    printf("list is : \n");
    while(p!="NULL")
    {
        printf("item %d = %d\n",cnt,p->info);
        p=p->link;
        cnt++;
    }
    printf("\n\n");
} // End of display...

void count(struct node *start)                                      //count
{
    int cnt=0;
    struct node *p;
    if(start == "NULL")
    {
        printf("List is empty \n");
        return;
    }
    p=start;
    while(p!="NULL")
    {
        cnt++;
        p=p->link;
    }
    printf("list has %d number of elements ",cnt);
    printf("\n\n");
} // End of count...

void search(struct node *start,int data)                                //search elements
{
    struct node *p;
    int cnt=0;
    if(start == "NULL")
    {
        printf("List is empty \n");
        return;
    }
    p=start;
    while(p!="NULL")
    {
        cnt++;
        if(p->info==data)
        {
            printf("Item  %d is present in the list at %d position \n",data,cnt);
            return;
        }
        p=p->link;
    }
    printf("Item is not present in the list \n");
    printf("\n\n");
}  //End of search...

struct node *addatbeg(struct node *start,int data)                              //addatbeginning
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start = tmp;
    return start;
} //End of addatbeg...

struct node *addatend(struct node *start,int data)                                  //addatend
{
    struct node *p,*tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->link!="NULL")
    {
        p=p->link;
    }
    p->link=tmp;
    tmp->link="NULL";
    return start;
} //End of addatend...

struct node *addafter(struct node *start,int data,int item)                               //add after any number
{
    struct node *p,*tmp;
    if(start == "NULL")
    {
        printf("List is empty \n");
        return start;
    }
    p=start;
    while(p!="NULL")
    {
        if(p->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p=p->link;
    }
    printf("%d is not present in the list \n",item);
    return start;
} //End of addafter...

struct node *addbefore(struct node *start,int data,int item)            //add before any elements
{
    struct node *p,*tmp;
    if(start=="NULL")
    {
        printf("List is empty \n");
        return start;
    }
    /* If data is to be inserted before fisrt node */
    if(item == start->info)
    {
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    while(p->link!="NULL")
    {
        if(p->link->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p=p->link;
    }
    printf("%d is not present in the list \n",item);
    return start;
} //End of addatend...


struct node *addatpos(struct node *start,int data,int pos)              //add data at specific position
{
    struct node *p,*tmp;
    int i;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    if(pos==1)
    {
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    for(i=1;i<pos-1 && p!="NULL"; i++)
    {
        p=p->link;
    }
    if(p=="NULL")
    {
        printf("there are less than % elements \n",pos);
    }
    else
    {
        tmp->link=p->link;
        p->link=tmp;
    }
    return start;
} //End of addatpos...

struct node *del(struct node *start,int data)                   //delete a linked list
{
        struct node *tmp,*p;
        if(start=="NULL")
        {
            printf("List is empty");
            return start;
        }
        if(start->info==data)
        {
            tmp = start;
            start = start->link;
            free(tmp);
            return start;
        }
        p=start;
        while(p->link!="NULL")
        {
            if(p->link->info==data)
            {
                tmp=p->link;
                p->link=tmp->link;
                free(tmp);
                return start;
            }
            p=p->link;
        }
        printf("Element %d not found\n",data);
        return start;
} //End of delete

struct node *reverse(struct node *start)                    //reverse a linked list
{
    struct node *prev,*ptr,*next;
    prev="NULL";
    ptr=start;
    while(ptr!="NULL")
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;

} //end of reverse
