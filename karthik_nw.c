#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char name[50];
    float per;
    int roll_num;
    struct Node *next;
};
 void read_details(struct Node *s)
 {
     printf("Enter the student details");
     scanf("%s%f%d",s->name,&s->per,&s->roll_num);
 }

void display_details(struct Node *s)
{
    printf("\nName=%s,\nPercentage=%f,\nRoll.no=%d\n,",s->name,s->per,s->roll_num);
}
struct Node *getNode()
{
    return malloc(sizeof(struct Node));
};
struct Node *insertfront(struct Node *head)
{
    struct Node *cur=head,*nw;
    nw=getNode();
    read_details(nw);
    if(head==NULL)
    {
       head=nw;
       nw->next=head;
       return head;
    }

    else
    {
        for(cur=head;cur->next!=head;cur=cur->next);

        cur->next=nw;
        nw->next=head;
        head=nw;

         return head;
    }
}
void *insertrear(struct Node *head)
{
    struct Node *cur=head,*nw;
    nw=getNode();
    read_details(nw);
    if(head==NULL)
    {
        head=nw;
        nw->next=head;
        return head;
    }
    else if(head->next==head)
    {
        head->next=nw;
        nw->next=head;
        return head;
    }
    else
    {
        for(cur=head;cur->next!=head;cur=cur->next)
        {
            cur->next=nw;
            nw->next=head;
        }
        return head;
    }
}
struct Node *delfront(struct Node *head)
{
    struct Node *cur=head,*last;
    if(head==NULL)
    {
        printf("list empty");
    }
    else if(head->next=head)
    {
        free(head);
    }
    else
    {
        for(last=head;last->next!=head;last=last->next)
        {
            head=head->next;
            last->next=head;
            free(cur);
        }
        return head;
    }

}
void displayList(struct Node *head)
{
    struct Node *cur;

    printf("\n-----------------List --------------------");

    if(head == NULL)
        printf("\nList empty");
    else
    {
        cur = head;
        do{
            display_details(cur);
            cur=cur->next;
        }while(cur!=head);
    }
    printf("\n----------------------------------------");
}
int main()
{
   struct Node *head=NULL;

   int ch,pos;
   do{
        printf("\n0->Exit   1->Insert front   2->Display  all   3->Insert last   4->delete front ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: break;
            case 1: head = insertfront(head); break;
            case 2: displayList(head); break;
            case 3: insertrear(head);break;
            case 4: head = delfront(head);break;


        }
   }while(ch!=0);
    return 0;
}
