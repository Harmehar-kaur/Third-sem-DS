// To implement insertion and deletion operation in linear que using linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue()
{

    int item;
    printf("\n Enter the data : ");
    scanf("%d", &item);
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = item;
    if (front == NULL)
    {
        new_node->next = front;
        front = new_node;
        rear = front;
    }
    else
    {
        new_node->next = NULL;
        rear->next = new_node;
        rear = new_node;
    }
}
void dequeue()
{
    if (front == NULL)
    {
        printf("\n Underflow ");
        return;
    }
    else
    {
        int item = front->data;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            struct Node *node = front;
            front = front->next;
            free(node);
        }
        printf("\n Dequeue item : %d", item);
    }
}
void display()
{
    struct Node *node = front;
    if (front == NULL)
    {
        printf("\n Underflow");
        return;
    }
    printf("|");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("|");
}
int main()
{
    system("cls");
    int choice;
    printf("Implementation of Queue using Linked list:\n ");
    while (1)
    {
        printf("\n 1.To Enqueue ");
        printf("\n 2.To Dequeue ");
        printf("\n 3.Display ");
        printf("\n 4.Exit ");

        printf("\n Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
