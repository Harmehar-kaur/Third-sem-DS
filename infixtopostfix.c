#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top = -1;
char s[50];
void push(char data)
{
    top += 1;
    s[top] = data;
}
char pop()
{
    char data = s[top];
    top -= 1;
    return data;
}
int empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int prec(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
void infix_postfix(char source[])
{
    char infix[50];
    strcpy(infix, source);
    int i = 0, j = 0;
    char output[50];
    push('N');
    while (infix[i] != '\0')
    {

        if (infix[i] >= 'a' && infix[i] <= 'z')
        {

            output[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (s[top] != 'N' && s[top] != '(')
            {
                char ch = pop();
                output[j] = ch;
                j++;
            }
            if (s[top] == '(')
                pop();
        }
        else
        {
            while (s[top] != 'N' && prec(infix[i]) <= prec(s[top]))
            {
                char ch = pop();
                output[j] = ch;
                j++;
            }
            push(infix[i]);
        }
        i++;
    }
    while (s[top] != 'N')
    {
        char ch = pop();
        output[j] = ch;
        j++;
    }
    output[j] = '\0';
    printf("%s", output);
    printf("\n");
}
int main()
{
    system("cls");
    char source[50];
    printf("\n Enter the expression : ");
    scanf("%s", source);
    printf(" Postfix Expression : ");
    infix_postfix(source);
    printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
}
