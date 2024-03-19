#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song
{
    struct song* prev;
    char name[25];
    int min;
    int sec;
    struct song* next;
} NODE;

NODE* create()
{
    NODE* t= (NODE*)malloc(sizeof(NODE));
    if (t == NULL)
    {
        printf("insufficient memory\n");
        return NULL;
    }
    t->next = t;
    t->prev = t;
    return t;
}

void read(NODE* temp)
{
    printf("enter song details\n");
    printf("enter song name\n");
    scanf("%s", temp->name);
    printf("enter song duration \nmin\nsec\n");
    scanf("%d%d", &temp->min, &temp->sec);
    return;
}
NODE* insert_rear(NODE* head)
{    NODE*nw;
     nw=create();
     read(nw);

    if (head == NULL)
    {
        head = nw;
    }
    else
    {
        nw->next = head;
        nw->prev = head->prev;
        head->prev->next = nw;
        head->prev = nw;
    }
    return head;
}
void first_lastsong(NODE* head)
{
    if (head == NULL)
    {
        printf("LIST EMPTY\n");
        return;
    }

    NODE* firstSong = head;
    NODE* lastSong = head->prev;

    printf("FIRST SONG: %s\n", firstSong->name);
    printf("LAST SONG: %s\n", lastSong->name);
}


void display(NODE* head)
{
    if (head == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        NODE* cur = head;
        printf("song name |song duration\n");
        do
        {
            printf("%s    | %d:%d\n", cur->name, cur->min, cur->sec);
            cur = cur->next;
        } while (cur != head);
    }
    return;
}
void remove_song(NODE* head)
{
    if (head == NULL)
    {
        printf("empty list\n");
        return;
    }

    NODE*Min_1 = head;
    NODE*Min_2 = head->next;
    for (NODE* cur = head->next; cur != head; cur = cur->next)
    {
        if (cur->min < Min_1->min)
        {
            Min_1 = cur;
        }
        else if (cur->min == Min_1->min && cur->sec < Min_1->sec)
        {
            Min_1 = cur;
        }
    }

    for (NODE* cur = head->next; cur != head; cur = cur->next)
    {
        if (cur != Min_1 && (cur->min < Min_2->min || (cur->min == Min_2->min && cur->sec < Min_2->sec)))
        {
            Min_2 = cur;
        }
    }
    if (Min_2 == head)
    {
        head = del_front(head);
    }
    else
    {
        Min_1->prev->next = Min_1->next;
        Min_1->next->prev = Min_1->prev;
        free(Min_1);
    }
    if (Min_2 == head)
    {
        head = del_front(head);
    }
    else
    {
        Min_2->prev->next = Min_2->next;
        Min_2->next->prev = Min_2->prev;
        free(Min_2);
    }
}

NODE *del_front(NODE* head)
{
    if (head == NULL)
    {
        printf("list empty\n");
        return NULL;
    }
    else if (head->next == head)
    {
        free(head);
        return NULL;
    }
    else
    {
        NODE* cur = head;
        head = head->next;
        head->prev = cur->prev;
        cur->prev->next = head;
        free(cur);
        return head;
    }
}
int main()
{
    int ch;
    NODE* head = NULL;
    while (1)
    {
        printf("   enter 1 to insert song\n   enter 2 to find first and last song\n   enter 3 to remove 2 song with min duration\n   enter 4 to display\n   enter 5 to delete front\n   enter 0 to exit\n     ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            head = insert_rear(head);
        }
        else if(ch == 2)
        {
            first_lastsong(head);
        }
        else if (ch == 3)
        {
            remove_song(head);
        }
        else if (ch == 4)
        {
            display(head);
        }
        else if (ch == 5)
        {
            head = del_front(head);
        }
        else if (ch == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
return 0;
}
