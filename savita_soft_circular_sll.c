#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    char singer[50];
    int duration;
    struct Node *next;
};

void readSong(struct Node *p)
{
    printf("\nEnter song details : \n");
    scanf("%s%s%d",p->name,p->singer,&p->duration);
}

void displaySong(struct Node *p)
{
    printf("\nName : %s   Singer : %s   Duration : %d",p->name,p->singer,p->duration);
}

struct Node *getNode()
{
    return malloc(sizeof(struct Node));
};

struct Node *insertRear(struct Node *first)
{
    struct Node *nw,*last;

    nw = getNode();
    readSong(nw);

    if(first == NULL)
    {
        nw->next = nw;
        first= nw;
    }
    else
    {
        for(last=first;last->next != first;last=last->next);
        last->next = nw;
        nw->next = first;
    }
    return first;
}


void displayList(struct Node *first)
{
    struct Node *cur;

    printf("\n-----------------List --------------------");

    if(first == NULL)
        printf("\nList empty");
    else
    {
        cur = first;
        do{
            displaySong(cur);
            cur=cur->next;
        }while(cur!=first);
    }
    printf("\n----------------------------------------");
}

struct Node *deleteBySinger(struct Node *first,char singer[])
{
    struct Node *prev,*cur;
    int count = 0;

    if(first == NULL)
    {
        printf("\nList empty");
        return first;
    }
    for(prev=first;prev->next!=first;prev=prev->next);
    cur = first;
    while(1)
    {
        printf("\nCheck 1");
        if(strcmp(cur->singer,singer)==0)
        {
            count++;
            if(cur == first)
            {
                first = first->next;
                prev->next = first;
                free(cur);
                cur=first;
                continue;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev;
            }
        }
        prev = cur;
        cur=cur->next;
        if(cur == first)
            break;
    }

    return first;
};

int countDuration(struct Node *first)
{
    struct Node *cur;
    int count=0;

    cur = first;
    do
    {
        if(cur->duration>5)
            count++;
        cur = cur->next;
    }while(cur != first);
    return count;
}


void deleteAlternate(struct Node *first)
{
    struct Node *prev,*cur;
    if(first == NULL ||  first==first->next)
        return;

    prev = first;
    cur = first->next;

    do
    {
        prev->next = cur->next;
        free(cur);
        prev = prev->next;
        cur=prev->next;
    }while(prev != first  && cur != first);

}


int main()
{
   struct Node *first=NULL;

   int ch,count;
   char singer[50];

   do{
        printf("\n0->Exit   1->Insert song   2->Display  all   3->Delete by singer   4->Count greater than 5 min dur   5->Delete alternate");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0: break;
            case 1: first = insertRear(first); break;
            case 2: displayList(first); break;
            case 3: printf("\nEnter singer : ");
                        scanf("%s",singer);
                        first = deleteBySinger(first,singer);
                        break;
            case 4: count = countDuration(first);
                        printf("\nNo of nodes : %d",count);
                        break;
            case 5: deleteAlternate(first);
                        break;
        }
   }while(ch!=0);
    return 0;
}









