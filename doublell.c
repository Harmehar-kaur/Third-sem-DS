#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    struct Node *next;
    struct Node *prev;
    int roll_no;
    char name[20];
};

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        while (head != NULL)
        {
            printf("Employee Name is : %s and employee id is: %d\n", head->name, head->roll_no);
            head = head->next;
        }
    }
    return;
}

struct Node *create_new_node(int n)
{
    char name1[20];
    int rno;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the employee name: ");
    fflush(stdin);
    gets(name1);
    strcpy(head->name, name1);
    printf("Enter the employee id: ");
    scanf("%d", &rno);
    head->roll_no = rno;
    head->next = NULL;
    head->prev = NULL;
    struct Node *p = head;

    for (int i = 2; i <= n; i++)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the employee name: ", i);
        fflush(stdin);
        gets(name1);
        strcpy(new_node->name, name1);

        printf("Enter the employee id: ", i);
        scanf("%d", &rno);

        new_node->roll_no = rno;
        new_node->next = NULL;
        new_node->prev = p;

        p->next = new_node;
        p = p->next;
    }

    return head;
};

struct Node *insert_new_node(struct Node *head)
{
    int ch, rno;
    char name1[20];

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        printf("Elements in list are\n");
        display(head);

        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        printf("Insertion at beginning\n");

        new_node->prev = NULL;

        printf("Enter the employee name:\n");
        fflush(stdin);
        gets(name1);
        strcpy(new_node->name, name1);

        printf("Enter the employee id: \n");
        scanf("%d", &rno);
        new_node->roll_no = rno;

        new_node->next = head;
        head->prev = new_node;

        head = new_node;

        return head;
    }
};

struct Node *reverse(struct Node *head)
{
    struct Node *p1 = head;
    struct Node *p2 = head->next;
    struct Node *p3 = p2->next;

    p1->next = NULL;
    p1->prev = p2;
    p2->next = p1;
    p2->prev = p3;
    while (p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
        p2->prev = p3;
    }
    head = p2;
    return head;
};

int count_node(struct Node *head)
{
    int count = 1;

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }

    else
    {
        while (head->next != NULL)
        {
            head = head->next;
            count += 1;
        }
        return count;
    }
}

struct Node *delete_node(struct Node *head)
{
    int ch;
    printf("Elements in list are\n");
    display(head);

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        struct Node *p = head;
        printf("Deletion at the end\n");

        while (p->next->next != NULL)
        {
            p = p->next;
        }

        p->next = NULL;
        return head;
    }
};

int main()
{
    system("cls");
    struct Node *head = NULL;
    int ch, choice, flag = 1;
    printf("Harmehar Kaur (CSE-1 04613202720)");
    printf("\n1.Create List\n2.Insertion in beginning\n3.Deletion at end\n4.Display\n5.Exit\n Enter your choice:");
    scanf("%d", &ch);

    while (flag == 1)
    {
        if (ch == 1)
        {
            int num;
            printf("\nEnter the number of nodes\n");
            scanf("%d", &num);
            head = create_new_node(num);
        }
        else if (ch == 2)
        {
            head = insert_new_node(head);
            display(head);
        }
        else if (ch == 3)
        {
            head = delete_node(head);
            display(head);
        }
        else if (ch == 4)
        {
            printf("\n\nElements are\n");
            display(head);
        }
        else if (ch == 5)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid choice\n");
        }

        printf("\n\nDo you want to perform any other operation(yes-1)/ (no-0)??\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
             printf("\n1.Create List\n2.Insertion in beginning\n3.Deletion at end\n4.Display\n5.Exit\n Enter your choice:");
            scanf("%d", &ch);
            flag = 1;
        }

        else
        {
            flag = 0;
        }
    }

    return 0;
}
