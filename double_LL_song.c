#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct song
{
    struct song*prev;
    char name[25];
    char singer[25];
    int min;
    int sec;
    struct song *next;
}NODE;

NODE * create()
{
    NODE *temp=NULL;
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("insufficient memory\n");
        return 0;
    }
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void read( NODE *temp)
{
    printf("enter song details\n");
    printf("enter song name\n");
    scanf("%s",temp->name);
    printf("enter singer name\n");
    scanf("%s",temp->singer);
    printf("enter song duration \nmin\nsec\n");
    scanf("%d%d",&temp->min,&temp->sec);
    return;
}



NODE *insert_front(NODE *head,NODE *nw)
{

    if(head==NULL)
    {
        head=nw;

    }
    else
    {
        nw->next=head;
        head->prev=nw;
        head=nw;
    }
    return head;
}
NODE *insert_end(NODE *head,NODE *nw)
{
    NODE *last=head;

    if(head==NULL)
    {
        head=nw;
    }
    else
    {
        while(last->next!=NULL)
        last=last->next;
        last->next=nw;
        nw->prev=last;
    }
    return head;
}


void fdisplay(NODE*head)
{
    if(head==NULL)
    {
        printf("empty list\n");

    }
    else
    {
        NODE *cur=head;
        printf("song name |singer name |song duration\n");
        while(cur!=NULL)
        {
            printf("%s    | %s         | %d:%d\n",cur->name,cur->singer,cur->min,cur->sec);
            cur=cur->next;
        }

    }
    return;
}
int count(NODE *head)
{
    int c=0;
    if(head==NULL)
    return c;
    NODE *cur=head;
    do
    {
       c++;
       cur=cur->next;
    } while (cur!=NULL);
    return c;
}
NODE *insert_position(NODE *head,NODE *nw,int pos)
{
    int cnt=count(head);
    if(head==NULL)
    return nw;
    if(pos==1)
    {
        nw->next=head;
        head->prev=nw;
        head=nw;
        return head;
    }
    if(pos==cnt+1)
    {
        NODE *cur=head;
        while(cur->next!=NULL)
        cur=cur->next;
        cur->next=nw;
        nw->prev=cur;
        return head;
    }
    NODE *cur=head;
    for(int i=1;i<pos-1;i++,cur=cur->next);
    nw->next=cur->next;
    cur->next->prev=nw;
    cur->next=nw;
    nw->prev=cur;
    return head;
}
void insert_after(NODE *head,char song[])
{
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    NODE *cur;
    for(cur=head;cur!=NULL&&strcmp(cur->name,song)!=0;cur=cur->next);
    if(cur==NULL&&head!=NULL)
    {
        printf("song not found\n");
        return;
    }
    NODE *nw=create();
    read(nw);
    nw->next=cur->next;
    if(cur->next!=NULL)
    cur->next->prev=nw;
    cur->next=nw;
    nw->prev=cur;
}
NODE * insert_before(NODE *head,char song[])
{
    if(head==NULL)
    {
        printf("empty list\n");
        return head;
    }
    NODE *cur;
    for(cur=head;cur!=NULL&&strcmp(cur->name,song)!=0;cur=cur->next);
    if(cur==NULL&&head!=NULL)
    {
        printf("song not found\n");
        return head;
    }
    NODE *nw=create();
    read(nw);
    nw->prev=cur->prev;
    if(cur->prev!=NULL)
    cur->prev->next=nw;
    nw->next=cur;
    cur->prev=nw;
    if(nw->prev==NULL)
    head=nw;
    return head;
}
void search_and_play(NODE *head,char song[])
{
    if(head==NULL)
    {
        printf("empty list\n");
        return ;
    }
    NODE *cur;
    for(cur=head;cur!=NULL&&strcmp(cur->name,song)!=0;cur=cur->next);
    if(cur==NULL&&head!=NULL)
    {
        printf("song not found\n");
        return ;
    }
    printf("\nplaying the song\n");
    fdisplay(cur);
}
void search_singer(NODE *head,char singer[])
{
    if(head==NULL)
    {
        printf("empty list\n");
        return ;
    }
    NODE *cur;
    for(cur=head;cur!=NULL&&strcmp(cur->singer,singer)!=0;cur=cur->next);
    if(cur==NULL&&head!=NULL)
    {
        printf("singer not found\n");
        return ;
    }
    printf("\nplaying the song by the singer %s\n",singer);
    fdisplay(cur);
}
void prev_next_song(NODE *head,char song[])
{
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    NODE *cur;
    for(cur=head;cur!=NULL&&strcmp(cur->name,song)!=0;cur=cur->next);
    if(cur==NULL&&head!=NULL)
    {
        printf("song not found\n");
        return;
    }
    if(cur->next!=NULL)
    {
        cur=cur->next;
        printf("next song\n");
        fdisplay(cur);
        cur=cur->prev;
    }
    else
    printf("there is no next song to be played\n");
    if(cur->prev!=NULL)
    {
        cur=cur->prev;
        printf("previous song\n");
        fdisplay(cur);
    }
    else
    printf("there is no previous song to be played\n");
}
void max_min_time(NODE *head)
{
    NODE *max=head,*cur;
    NODE *min=head;
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    for(cur=head->next;cur!=NULL;cur=cur->next)
    {
        if(cur->min>head->min)
        max=cur;
        else if(cur->min==head->min)
        {
            if(cur->sec>head->sec)
            max=cur;
        }
    }
    printf("song with maximum run time\n");
    fdisplay(max);
    for(cur=head->next;cur!=NULL;cur=cur->next)
    {
        if(cur->min<head->min)
        min=cur;
        else if(cur->min==head->min)
        {
            if(cur->sec<head->sec)
            min=cur;
        }
    }
    printf("song with minimum run time\n");
    fdisplay(min);
}
NODE *del_front(NODE *head)
{
    NODE *cur = head;
    if(head==NULL)
    {
        printf("list empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        head=head->next;
        free(cur);
        return (head);
    }
}
NODE *del_end(NODE *head)
{
       NODE *cur = head;
    if(head==NULL)
    {
        printf("list empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        for(cur=head;cur->next!=NULL;cur=cur->next);
        cur->prev->next=NULL;
        free(cur);
        return (head);
    }
}
NODE *del_pos(NODE *head,int pos)
{
    NODE *cur = head;

    int cnt =count(head);
    if(pos<1&&pos>cnt)
    {
        printf("invalid input");
    }
    else if(head==NULL)
    {
        printf("list empty");
    }
    else if(pos==1)
    {   if(head->next==NULL)
         {
             free(head);
         }

        if(head->next!=NULL)
        {
        head=head->next;
        free(cur);
        }
       return(head);
    }
    else
    {
        for(int i=1;i<pos;i++,cur=cur->next);
        cur->prev->next=cur->next;
        free(cur);
        return (head);
    }
}
NODE *search_del(NODE *head,char singer[])
{
    if(head==NULL)
    {
        printf("list empty");
    }
    NODE *cur;
    for(cur=head;cur!=NULL&&strcmp(cur->singer,singer)!=0;cur=cur->next);
    if(cur==NULL&&head!=NULL)
    {
        printf("singer not found");
    }
    else
    {
        cur->prev->next=cur->next;
        free(cur);

    }
}
int main()
{
    int ch;
    NODE *head=NULL;
    while(1)
    {
        printf("     enter 1 to insert front\n     enter 2 to fdisplay\n     enter 3 to insert rear\n     enter 4 to count\n     enter 5 to insert at any position\n     enter 6 to insert after a song\n     enter 7 to insert before a song\n     enter 8 to play a particular song\n     enter 9 to search by a singer\n     enter 10 to play previous and next song\n     enter 11 to fdisplay the song with max time\n     enter 12 to delete front\n     enter 13 to delete end\n     enter 14 to delete specified position\n     enter 15 to delete singer\n     enter 0 to exit\n     ");
        scanf("%d",&ch);
        if(ch==1)
        {
            NODE *nw=create();
            read(nw);
            head=insert_front(head,nw);
        }
        else if(ch==2)
        {
            fdisplay(head);
        }
        else if(ch==3)
        {
            NODE *nw=create();
            read(nw);
            head=insert_end(head,nw);
        }
        else if(ch==4)
        {
            int cnt=count(head);
            printf("length of list =%d\n",cnt);
        }
        else if(ch==5)
        {
            int pos,c=count(head);
            printf("enter the position at which node needs to be added\n");
            scanf("%d",&pos);
            if(pos>c+1||pos<1)
            printf("invalid position\n");
            else
           {
                NODE *nw=create();
                read(nw);
                head=insert_position(head,nw,pos);
           }
        }
        else if(ch==6)
        {
            char song[25];
            printf("enter the song after which the new node has to be inserted\n");
            scanf("%s",song);
            insert_after(head,song);

        }
        else if(ch==7)
        {
            char song[25];
            printf("enter the song before which the new node has to be inserted\n");
            scanf("%s",song);
            head=insert_before(head,song);
        }
        else if(ch==8)
        {
            char song[25];
            printf("enter song to be played\n");
            scanf("%s",song);
            search_and_play(head,song);
        }
        else if(ch==9)
        {
            char singer[25];
            printf("enter the singer name\n");
            scanf("%s",singer);
            search_singer(head,singer);
        }
        else if(ch==10)
        {
            char song[25];
            printf("enter the song to play the previous and next song\n");
            scanf("%s",song);
            prev_next_song(head,song);
        }
        else if(ch==11)
        {
            max_min_time(head);
        }
        else if(ch==12)
        {
           head=del_front(head);
        }
        else if(ch==13)
        {
            head=del_end(head);
        }
        else if(ch==14)
        {   int pos,cnt=count(head);
            printf("Enter the position to be deleted");
            scanf("%d",&pos);
            head=del_pos(head,pos);
        }
        else if(ch==15)
        {
            char singer[25];
            printf("Enter the singer name");
            scanf("%s",singer);
            head=search_del(head,singer);
        }
        else
        {
            break;
        }
    }
}
