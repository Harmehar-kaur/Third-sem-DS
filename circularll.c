#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>
#include <string.h>
struct college
{
    char colname[50];
    int colid;
    struct college *next;
} * start;
void display()
{
    if (start == NULL)
        printf("\nEmpty List\n");
    else
    {
        struct college *ptr = start;
        do
        {
            printf("college id : %d\tcollege name : %s\n", ptr->colid, ptr->colname);
            ptr = ptr->next;
        } while (ptr != start);
    }
}
void createlist(char name[], int data)
{
    struct college *new_node = malloc(sizeof(struct college)), *ptr = start;
    new_node->colid = data;
    strcpy(new_node->colname, name);
    if (start == NULL)
    {
        new_node->next = new_node;
        start = new_node;
    }
    else
    {
        while (ptr->next != start)
            ptr = ptr->next;
        ptr->next = new_node;
                        new_node->next = start;
    }
}
void insertbeg(char name[], int element)
{
    struct college *new_node = malloc(sizeof(struct college)), *ptr = start;
    new_node->colid = element;
    strcpy(new_node->colname, name);
    if (start == NULL)
    {
        new_node->next = ptr;
        start = new_node;
    }
    else
    {
        while (ptr->next != start)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->next = start;
        start = new_node;
    }
}
void delend()
{
    if (start == NULL)
        printf("\nEmpty List,therefore no data to delete\n");
    else
    {
        struct college *ptr = start;
        while (ptr->next->next != start)
            ptr = ptr->next;
        ptr->next = start;
    }
}
void main()
{
    int c, n, id, i;
    char name[50];
    start = NULL;
    system("cls");
    while (1)
    {
        printf("\n Press 1 for creating new list \n Press 2 for insertion at beginning of list \n Press 3 for Deleting "
               " element from end of list \n Press 4 for Display the list \n Press 5 for exit \n ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\n enter the number of elements : ");
            scanf("%d", &n);
            printf("\n start entering elements :\n");
            for (i = 0; i < n; i++)
            {
                printf("Enter College %d Name - ", i + 1);
                scanf("%s", &name);
                printf("Enter College %d Id - ", i + 1);
                scanf("%d", &id);
                createlist(name, id);
            }
            break;
        case 2:
            printf("\n Enter the college name : ");
            scanf("%s", &name);
            printf("\n Enter the college id : ");
            scanf("%d", &id);
            insertbeg(name, id);
            break;
        case 3:
            delend();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n Harmehar Kaur( 04613202720 CSE1)");
            exit(0);
            break;
        default:
            printf("\n wrong input \n ");
            break;
        }
    }
    getch();
}
