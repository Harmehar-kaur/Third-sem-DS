
#include <stdio.h>
#include <conio.h>
int main()
{
    system("cls");
    int a, ar[50];//a=number of elements , ar=array
    int k,i;
    int el;//el=element to be inserted 
    printf("Enter the number of elements in the array:");
    scanf("%d", &a);
    while (i < a)//entering the elements

    {

        printf("[%d] element is: ", i+1);

        scanf("%d", &ar[i+1]);
        i++;
    }

    printf("\n Initially the array is:\n");//array input given by user
    i = 1;
    while (i <= a)

    {

        printf("%d ", ar[i]);
        i++;
    }

    //insertion

    printf("\nEnter the element to be inserted:\n");
    scanf("%d", &el);
    printf("Enter the position where element is to be inserted:");

    scanf("%d", &k);
    i = a;
    while (k <= i)

    {

        ar[i + 1] = ar[i];
        i--;
    }

    ar[k] = el;
    a = a + 1;
    printf("\n Final Array after insertion:\n");
    i = 1;
    while (i <= a)

    {

        printf("%d ", ar[i]);
        i++;
    }

    printf("\n Harmehar Kaur[CSE-1 04613202720]");

    getch();
    return 0;
}
