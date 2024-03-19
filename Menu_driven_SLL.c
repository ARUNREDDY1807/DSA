#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    char name[20];
    int roll;
    struct student *next;

}NODE;
NODE * create()
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("memory not allocated\n");
        return 0;
    }
    temp->next=NULL;
    return temp;
}
void  read (NODE *head)
{
    printf("enter the name and roll number\n");
    scanf("%s%d",head->name,&head->roll);
    return;
}
void display(NODE *head)
{
    NODE *cur;
    cur =head;
    if(cur==NULL)
    {
        printf("list is empty\n");
        return ;
    }
    while (cur!=NULL)
    {
        printf("%s %d \n",cur->name,cur->roll);
        cur = cur->next;
    }
    return;
}
NODE *insert_front(NODE *head,NODE *t1)
{
    if(head==NULL)
    {
        head=t1;
    }
    else
    {
        t1->next=head;
        head=t1;
    }
    return head;
}
NODE * init(NODE *head)
{
    head=NULL;
    return head;
}
NODE *insertend(NODE *head,NODE *t)
{
    if(head==NULL)
    {
        head=t;
    }
    else
    {
        NODE*cur;
        for(cur=head;cur->next!=NULL;cur=cur->next);
        cur->next=t;
    }
    return head;
}
int count(NODE* head)
{
    int count=0;
    NODE *cur=head;
    while(cur!=NULL)
    {
        cur=cur->next;
        count++;
    }
    return count;
}
int search(NODE *head,char stud[20])
{
    NODE *cur=head;
    while(cur!=NULL)
    {
        if(strcmp(cur->name,stud)==0)
        return 1;
        cur=cur->next;
    }

    return 0;
}
NODE *insertatpos(NODE*head,int n,NODE*t,int pos)
{
    if(head==NULL)
    head=t;
    else if(pos==1)
    {
        t->next=head;
        head=t;
    }
    else if(pos==n+1)
    {
        NODE *cur=head;
        while(cur->next!=NULL)
        cur=cur->next;
        cur->next=t;
    }
    else{
        NODE *cur=head;
        for(int i=1;i<pos-1;i++)
        cur=cur->next;
        t->next=cur->next;
        cur->next=t;
    }
    return head;
}
NODE *insert_name(NODE*head,char na[10],NODE*t)
{
    NODE *cur=head;
    if(head==NULL)
    printf("empty list\n");
    else if(head->next==NULL)
    {
        if(strcmp(head->name,na)==0)
        head->next=t;
        else
        printf("string not found");
    }
    else
    {

        int f=0;
        while(cur!=NULL)
        {
            if(strcmp(cur->name,na)==0)
            {
                f=1;
                t->next=cur->next;
                cur->next=t;
                break;
            }
            else
            cur=cur->next;
        }
        if(f==0)
        {
            printf("not found\n");
        }
    }
    return head;
}
NODE * delete_front(NODE * head)
{
    NODE *cur=head;
    if(head==NULL)
    {
        printf("empty list\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {   head=head->next;
        free(cur);

    }
    return head;
}
NODE *delete_rear(NODE *head)
{
    NODE *cur=head,*temp=NULL;
    if(head==NULL)
    {
        printf("empty list\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(cur->next!=NULL)
        {
            temp=cur;
            cur=cur->next;
        }
        free(cur);
        temp->next=NULL;


    }
    return head;
}
NODE * delete_pos(NODE * head,int n ,int pos)
{
    NODE * cur=head,*prev=NULL;
    if(head==NULL)
    {
        printf("empty list\n");
    }
    else if(head->next==NULL)
    {
        free (head);
        head=NULL;
    }
    else if(pos==1)
    {
        cur=head;
        head=head->next;
        free(cur);
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        free(cur);

    }
    return head;
}
NODE insert_sorted(NODE head,NODE *t)
{
    if(head==NULL)
    head=t;
    else if(head->next==NULL)
    {
        if(head->roll<t->roll)
        head->next=t;
        else
        {
            t->next=head;
            head=t;
        }
    }
    else
    {
        NODE*cur=head,*prev=NULL;
        while(cur->roll<t->roll&cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
            t->next=prev->next;
            prev->next=t;
    }
    return head;
}

int main()
{
    NODE *t1;
     NODE *t;
    NODE *head;
    int ch,flag;
    int nodes;
    int pos,n;
    char stud[20];
    head=init(head);
    char na[10];


    while(1)
    {
        printf("enter choice:- 1->insert front \n               2->display list\n               3->insert rear \n               4->count no of nodes\n               5->search\n               6->insert at a position\n               7->insert after a name\n               8->delete front\n               9->delete rear\n               10->delete at a position\n               11->insert after sorting\n               0->exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :    t1=create();
                        read(t1);
                        head=insert_front(head,t1);
                        break;
            case 2:     display(head);
                        break;
            case 3:     t1=create();
                        read(t1);
                        head=insertend(head,t1);
                        break;
            case 4:     nodes=count(head);
                        printf("no of nodes =%d\n",nodes);
                        break;
            case 5:     if(head==NULL)
                        {
                            printf("the list is empty\n");
                            break;
                        }
                        else
                        {
                            printf("enter the student to be searched\n") ;
                            scanf("%s",stud);
                            flag=search(head,stud);
                            if(flag==0)
                            printf("name not found\n");
                            else
                            printf("name found\n");
                            break;
                        }
            case 6:     printf("enter the position to be inserted");
                        scanf("%d",&pos);
                        n=count(head);
                        if(pos>=1&&pos<=n+1)
                        {

                            t=create();
                            read(t);
                            head=insertatpos(head,n,t,pos);

                        }
                        else
                        printf("invalid position\n");
                        break;
            case 7:     printf("enter the name ");
                        scanf("%s",na);
                        printf("enter detials of node to be added\n");
                        t=create();
                        read(t);
                        head=insert_name(head,na,t);
                        break;
            case 8:     head=delete_front (head);
                        break;
            case 9:     head=delete_rear(head);
                        break;
            case 10:    printf("enter the position to be deleted\n");
                        scanf("%d",&pos);
                        n=count(head);
                        if(pos>=1&&pos<=n)
                        {
                            head=delete_pos(head,n,pos);
                        }
                        else
                        printf("invalid position\n");
                        break;
            case 11:    printf("enter node to be sorted\n");
                        t=create();
                        read(t);
                        head=insert_sorted(head,t);
                        break;

            case 0:     exit(0);

        }
    }
}
