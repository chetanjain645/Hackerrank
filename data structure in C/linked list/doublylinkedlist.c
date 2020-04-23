/* this program is a implementation of double linked list */

#include<stdio.h>
#include<stdlib.h>
struct node                                      //definition of double linked list
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start,int data);
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
        printf("\t \n THIS IS THE IMPLEMENTATION OF DOUBLE LINKED LIST \t \n");
        printf("1. create List \n");
        printf("2. Display\n");
        printf("3. Add to empty list\n");
        printf("4. Add at beginning \n");
        printf("5. Add at end\n");
        printf("6. Add after node\n");
        printf("7. Add before node\n");
        printf("8. Delete  \n");
        printf("9. Reverse \n");
        printf("10. Quit \n");
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
            printf("Enter the element you want to insert ");
            scanf("%d",&data);
            start=addtoempty(start,data);
            break;
        case 4:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            start = addatbeg(start,data);
            break;
        case 5:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            start = addatend(start,data);
            break;
        case 6:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            printf("enter the element after which you want to insert : ");
            scanf("%d",&item);
            start = addafter(start,data,item);
            break;
        case 7:
            printf("Enter the element you want to insert : ");
            scanf("%d",&data);
            printf("enter the element before which you want to insert : ");
            scanf("%d",&item);
            start = addbefore(start,data,item);
            break;
        case 8:
            printf("Enter the element to be deleted : ");
            scanf("%d",&data);
            start = del(start,data);
            break;
        case 9:
            start = reverse(start);
            break;
        case 10:
            exit(1);
        default :
            printf("wrong choice try again \n");
            break;
        }
    }
    return 0;
}

struct node *create_list(struct node *start)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    start="NULL";
    if(n==0)
    {
        return start;
    }
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    start = addtoempty(start,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=addatend(start,data);
    }
    return start;
} //end of create_list


void display(struct node *start)
{
    struct node *p;
    int cnt=1;
    if(start=="NULL")
    {
        printf("List is empty");
        return ;
    }
    p=start;
    printf("List is : \n");
    while(p!="NULL")
    {
        printf("Item %d = %d\n",cnt,p->info);
        cnt++;
        p=p->next;
    }
    printf("\n");
} //end of display

struct node *addtoempty(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev="NULL";
    tmp->next="NULL";
    start=tmp;
    return start;
} //end of addtoempty

struct node *addatbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev="NULL";
    tmp->next=start;
    start->prev="NULL";
    start=tmp;
    return start;
} //end of addtobeginnig

struct node *addatend(struct node *start,int data)
{
    struct node *tmp,*p;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->next!="NULL")
    {
        p=p->next;
    }
    p->next=tmp;
    tmp->next="NULL";
    tmp->prev=p;
    return start;
} //end of addatend

struct node *addafter(struct node *start,int data,int item)
{
     struct node *p,*tmp;
     tmp=(struct node *)malloc(sizeof(struct node));
     tmp->info=data;
     p=start;
     while(p!="NULL")
     {
        if(p->info==item)
        {
            tmp->prev=p;
            tmp->next=p->next;
            if(p->next!="NULL")
            {
                p->next->prev=tmp;
            }
            p->next=tmp;
            return start;
        }
        p=p->next;
     }
     printf("%d not present in the list\n",item);
     return start;
} //endofaddafter

struct node *addbefore(struct node *start,int data,int item)
{
     struct node *q,*tmp;
    if(start=="NULL")
     {
         printf("List is empty \n");
         return start;
     }
     if(start->info == item)
     {
         tmp = (struct node*)malloc(sizeof(struct node));
         tmp->info=data;
         tmp->prev="NULL";
         tmp->next=start;
         start->prev=tmp;
         start = tmp;
         return start;
     }
     q=start;
     while(q!="NULL")
     {
        if(q->info==item)
        {
            tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->prev = q->prev;
            tmp->next = q;
            q->prev->next=tmp;
            q->prev = tmp;
            return start;
        }
        q = q->next;
     }
     printf("%d not present in the list\n",item);
     return start;
} //endofaddbefore

struct node *del(struct node *start,int data)
{
    struct node *tmp;
    if(start == "NULL")
    {
        printf("List is empty\n");
        return start;
    }
    if(start->next =="NULL")
        if(start->info==data)
        {
            tmp=start;
            start = "NULL";
            free(tmp);
            return start;
        }
        else
        {
            printf("Element %d not found\n",data);
            return start;
        }
        if(start->info == data)
        {
            tmp=start;
            start=start->next;
            start->prev="NULL";
            free(tmp);
            return start;
        }
        tmp=start->next;
        while(tmp->next!="NULL")
        {
            if(tmp->info==data)
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                free(tmp);
                return start;
            }
            tmp=tmp->next;
        }
        if(tmp->info == data)
        {
            tmp->prev->next = "NULL";
            free(tmp);
            return start;
        }
        printf("Element %d not found\n",data);
        return start;
} //endofdelete


struct node *reverse(struct node *start)
{
    struct node *p1,*p2;
    p1 = start;
    p2 = p1->next;
    p1->next = "NULL";
    p1->prev=p2;
    while(p2!="NULL")
    {
        p2->prev = p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start =p1;
    printf("List reversed \n");
    return start;
} //End of reverse
