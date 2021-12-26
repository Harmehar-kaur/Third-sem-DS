#include <stdio.h>
#include <stdlib.h>
struct node
{

    int info;
    int rno;
    char name[20];
    struct node *next;
} * start;
void count()

{

    int cnt = 0;

    struct node *node;
    if (start == NULL)
    {

        printf("\nlist is empty");
    }

    node = start;
    while (node != NULL)
    {

        cnt++;

        node = node->next;
    }

    printf(" no of elements are : %d", cnt);
    getch();
}

void create_list(int rno, char name[20])

{

    struct node *node, *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->rno = rno;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    if (start == NULL)
        start = new_node;
    else
    {

        node = start;

        while (node->next != NULL)
        {

            node = node->next;
        }

        node->next = new_node;
    }
}

void display()

{

    struct node *node;
    if (start == NULL)
    {

        printf("\nlist is empty");
    }

    node = start;
    while (node != NULL)
    {

        printf("%d\t%s", node->rno, node->name);
        node = node->next;
        printf("\n");
    }

    getch();
}

void insert_beg(int rno, char name[20])

{

    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    new_node->rno = rno;
    strcpy(new_node->name, name);
    new_node->next = start;
    start = new_node;
    display();
}

void insert_specific(int rno, char name[20])

{

    struct node *new_node, *node = start;
    new_node = malloc(sizeof(struct node));
    new_node->rno = rno;
    strcpy(new_node->name, name);
    int location, c = 1;

    printf("\nenter the location where you want to insert element:");
    scanf("%d", &location);
    while (c < location - 1)

    {

        node = node->next;
        c++;
    }

    new_node->next = node->next;
    node->next = new_node;
    display();
}

void insert_end(int rno, char name[20])

{

    struct node *new_node, *node = start;
    new_node = malloc(sizeof(struct node));
    new_node->rno = rno;
    strcpy(new_node->name, name);
    while (node->next != NULL)

    {

        node = node->next;
    }

    new_node->next = NULL;
    node->next = new_node;
    display();
}

void del_beg()

{

    struct node *node;
    node = start;
    start = node->next;
}

void del_specific()

{

    int location, c = 1;
    struct node *node;
    node = start;
    printf("\nenter the location from wfere you want to delete element:");
    scanf("%d", &location);
    while (c < location - 1)

    {

        node = node->next;
        c++;
    }

    node->next = node->next->next;
}
void del_end()

{

    struct node *node;
    node = start;
    while (node->next->next != NULL)

    {

        node = node->next;
    }

    node->next = NULL;
}

void reverse()

{

    struct node *p1, *p2, *p3;
    if (start->next == NULL)
    {

        printf("only one element");
    }

    p1 = start;
    p2 = p1->next;
    p3 = p2->next;
    p1->next = NULL;
    p2->next = p1;
    while (p3 != NULL)
    {

        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
    }

    start = p2;
    display();
    getch();
}

int main()

{
    system("cls");
    int ch, n, m, rno, pos, i;
    char name[20];
    start = NULL;
    while (1)
    {

        system("cls");
        printf("\n Harmehar Kaur( 04613202720 CSE1)");
        printf("\n1.create list\n2.display list\n3.insert at begining\n4.insert at specific location\n5.insert at end\n6.delete at begining\n7.delete at specific location\n8.delete at end\n9.reverse\n10.count\n11.quit\n\nenter a choice : ");
        scanf("%d", &ch);

        system("cls");
        switch (ch)
        {
        case 1:
            printf("\nenter number of nodes: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {

                printf("\nenter roll number:");
                scanf("%d", &rno);
                printf("enter name:");
                scanf("%s", name);
                create_list(rno, name);
            }

            break;

        case 2:
            display();
            break;

        case 3:
            printf("\nenter roll number:");
            scanf("%d", &rno);
            printf("enter name:");
            scanf("%s", name);
            insert_beg(rno, name);
            break;

        case 4:
            printf("\nenter roll number:");
            scanf("%d", &rno);
            printf("enter name:");
            scanf("%s", name);
            insert_specific(rno, name);
            break;

        case 5:
            printf("\nenter roll number:");
            scanf("%d", &rno);

            printf("enter name:");
            scanf("%s", name);
            insert_end(rno, name);
            break;

        case 6:
            del_beg();
            break;

        case 7:

            del_specific();
            break;

        case 8:
            del_end();
            break;

        case 9:
            reverse();
            break;

        case 10:
            count();
            break;

        case 11:
            return 0;

        default:
            printf("\nwrong input");
        }
    }
}
