//to implement push and pop operation in stack using array
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#define MAX 6

int array[MAX], top = -1;

void display()

{

    if (top == MAX)
        printf("\nOverflow\n");
    else if (top == -1)
        printf("\nempty stack");
    else

    {

        printf("\n Elements in stack are : \n");
        for (int i = top; i >= 0; i--)
            printf("|%d|\n", array[i]);
    }
}

void push(int a[], int value)

{

    if (top == MAX - 1)
        printf("\nOverflow\n");
    else
    {

        top = top + 1;
        a[top] = value;
    }

    display();
}

void pop(int a[])

{

    if (top == -1)
        printf("\nUnderflow\n");
    else

    {

        int value;
        value = a[top];
        top--;
        printf("\nElement %d popped", value);
    }

    display();
}

int main()

{
    system("cls");
    int choice, info;
    while (1)
    {

        printf("\n Press 1 for PUSH \n Press 2 for POP \n Press 3 for DISPLAY \n Press 4 for EXIT\n");

        scanf("%d", &choice);
        switch (choice)
        {

        case 1:

            printf("\nEnter the element : ");
            scanf("%d", &info);
            push(array, info);
            break;
        case 2:

            pop(array);
            break;
        case 3:

            display(array);
            break;
        case 4:

            printf("\n Harmehar kaur (04613202720 CSE1)\n");
            exit(0);
            break;
        default:
            printf("\nwrong input");
            break;
        }
    }

    getch();
    return 0;
}
