#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * head;
void push(int item)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("\n underflow");
    }
    else
    {
        struct Node *temp = head;
        printf("\n Elements are :\n");
        while (temp != NULL)
        {
            printf("|%d| \n", temp->data);
            temp = temp->next;
        }
    }
}
int pop()
{
    if (head == NULL)
    {
        printf("\n underflow");
        return -1;
    }
    else
    {
        printf("\n popped element : %d", head->data);
        int item = head->data;
        head = head->next;
        return item;
    }
}

int main()
{   
    system("cls");
    head = NULL;
    int choice, item;
    while (1)
    {
        printf("\n 1.Push ");
        printf("\n 2.Pop ");
        printf("\n 3.Display ");
        printf("\n 4.Exit ");

        printf("\n Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n enter element : ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
            exit(0);
        }
    }
}
