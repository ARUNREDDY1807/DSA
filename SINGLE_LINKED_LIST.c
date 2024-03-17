#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[20];
    int roll;
    struct student* next;
} NODE;

NODE* create()
{
    NODE* t = NULL;
    t = (NODE*)malloc(sizeof(NODE));
    if (t == NULL)
    {
        printf("insufficient memory");
        return NULL;
    }
    else
    {
        t->next = NULL;
        return t;
    }
}

void read(NODE* t)
{
    printf("enter the student details\n");
    scanf("%s%d", t->name, &t->roll);
    t->next = NULL;
    return;
}

NODE* insert_front(NODE* head, NODE* t)
{
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        t->next = head;
        head = t;
    }
    return head;
}

NODE* insert_end(NODE* head, NODE* t)
{
    NODE* cur = head;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = t;
    }
    return head;
}

int count(NODE* head)
{
    int count = 0;
    NODE* cur = head;
    while (cur != NULL)
    {
        cur = cur->next;
        count++;
    }
    return count;
}

NODE* insert_position(NODE* head, NODE* t, int pos)
{
    int cnt;
    cnt = count(head);
    if (pos > cnt + 1 || pos < 1)
    {
        printf("invalid position\n");
        return head;
    }

    if (pos == 1)
    {
        t->next = head;
        head = t;
    }
    else
    {
        NODE* cur = head;
        for (int i = 1; i < pos - 1; i++)
        {
            cur = cur->next;
        }
        t->next = cur->next;
        cur->next = t;
    }
    return head;
}

NODE* delete_front(NODE* head)
{
    if (head == NULL)
    {
        printf("empty list\n");
        return NULL;
    }
    NODE* temp = head;
    head = head->next;
    free(temp);
    return head;
}

NODE* delete_rear(NODE* head)
{
    if (head == NULL)
    {
        printf("empty list\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    NODE* cur = head;
    NODE* prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    return head;
}

NODE* delete_at_any_pos(NODE* head, int pos)
{
    int cnt;
    cnt = count(head);
    if (pos > cnt || pos < 1)
    {
        printf("invalid position\n");
        return head;
    }

    if (pos == 1)
    {
        NODE* temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        NODE* cur = head;
        NODE* prev = NULL;
        for (int i = 1; i < pos; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        free(cur);
    }
    return head;
}

NODE* delete_by_name(NODE* head, char nm[])
{
    if (head == NULL)
    {
        printf("empty list\n");
        return NULL;
    }

    if (strcmp(head->name, nm) == 0)
    {
        NODE* temp = head;
        head = head->next;
        free(temp);
        printf("node deleted\n");
        return head;
    }

    NODE* cur = head;
    NODE* prev = NULL;
    while (cur != NULL && strcmp(cur->name, nm) != 0)
    {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("name not found\n");
    }
    else
    {
        prev->next = cur->next;
        free(cur);
        printf("node deleted\n");
    }

    return head;
}

void display(NODE* head)
{
    NODE* cur = head;
    if (head == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        while (cur != NULL)
        {
            printf("%s %d\n\n", cur->name, cur->roll);
            cur = cur->next;
        }
    }
}

int main()
{
    NODE* head = NULL;
    NODE* t = NULL;
    int ch, nodes;

    while (1)
    {
        printf("\nenter 1 to insert data\nenter 2 to insert end \nenter 3 to insert at a position\nenter 4 to count\nenter 5 to deletefront\nenter 6 to deleterear\nenter 7 to delete at any position\nenter 8 to delete by name\nenter 9 to display\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            t = create();
            read(t);
            head = insert_front(head, t);
        }
        else if (ch == 2)
        {
            t = create();
            read(t);
            head = insert_end(head, t);
        }
        else if (ch == 3)
        {
            int pos, n;
            printf("enter the position at which node needs to be inserted\n");
            scanf("%d", &pos);
            n = count(head);
            if (pos > n + 1 || pos < 1)
            {
                printf("invalid position\n");
            }
            else
            {
                t = create();
                read(t);
                head = insert_position(head, t, pos);
            }
        }
        else if (ch == 4)
        {
            nodes = count(head);
            printf("no of nodes =%d\n", nodes);
        }
        else if (ch == 5)
        {
            head = delete_front(head);
        }
        else if (ch == 6)
        {
            head = delete_rear(head);
        }
        else if (ch == 7)
        {
            int pos, n;
            printf("enter the position at which node needs to be deleted\n");
            scanf("%d", &pos);
            n = count(head);
            if (pos > n || pos < 1)
            {
                printf("invalid position\n");
            }
            else
            {
                head = delete_at_any_pos(head, pos);
            }
        }
        else if (ch == 8)
        {
            char name[20];
            printf("enter the name to be deleted\n");
            scanf("%s", name);
            head = delete_by_name(head, name);
        }
        else
        {
            display(head);
        }
    }
    return 0;
}
