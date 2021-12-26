#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAXSTACK 100

float stack[MAXSTACK];
void push(float stack[], float value);
float pop(float stack[]);
int top = -1;
float evaluatePostfixExp(char exp[]);

void push(float stack[], float value)
{

    if (top == MAXSTACK - 1)
    {
        printf("stack over flow");
    }
    else
    {
        top = top + 1;
        stack[top] = value;
    }
}

float pop(float stack[])
{
    float value = -1;
    if (top == -1)
    {
        printf("stack under flow");
    }
    else
    {
        value = stack[top];
        top = top - 1;
    }
    return value;
}
float EvalPostfix(char exp[])
{

    int i = 0;
    float value;
    float op1, op2;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(stack, (float)(exp[i] - '0'));
        }
        else
        {
            op1 = pop(stack);
            op2 = pop(stack);

            switch (exp[i])
            {
            case '*':
                value = op2 * op1;
                break;

            case '/':
                value = op2 / op1;
                break;

            case '+':
                value = op2 + op1;
                break;

            case '-':
                value = op2 - op1;
                break;
            }
            push(stack, value);
        }
        i++;
    }
    return (pop(stack));
}
void main()
{
    float value;
    int i;
    char exp[100];
    system("cls");
    printf("There are only five operators(*, /, +, -)\n");
    printf(" \n Enter postfix expression : \n");
    gets(exp);
    value = EvalPostfix(exp);
    printf("\n Value of The Postfix Expression=%2f", value);
    printf("\n Harmehar kaur(CSE-1 04613202720)\n");
    getch();
}
