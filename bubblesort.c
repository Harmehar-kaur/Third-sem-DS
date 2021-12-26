#include <stdio.h>
#include <conio.h>
int main()
{
    int n;
    printf("Number of elements in the array:");
    scanf("%d", &n);
    int ar[n], i = 1;
    while (i <= n)
    {
        printf("Element %d=", i);
        scanf("%d", &ar[i]);
        i++;
    }
    printf("The array is:");

    i = 1;
    while (i <= n)
    {
        printf("%d ", ar[i]);
        i++;
    }
    i = 1; //Bubble sort
    while (i < n)
    {
        printf("\n Pass %d : \n", i);
        int ptr = 1;
        while (ptr <= n - i)
        {
            if (ar[ptr] > ar[ptr + 1])
            {
                //swapping
                int temp;
                temp = ar[ptr];
                ar[ptr] = ar[ptr + 1];
                ar[ptr + 1] = temp;
            }
            int j = 1;
            while (j <= n)
            {
                printf("%d ", ar[j]);
                j++;
            }
            printf("\n");

            ptr++;
        }
        i++;
    }
    printf("\nSorted array is:\n");
    i = 1;
    while (i <= n)
    {
        printf("%d ", ar[i]);
        i++;
    }
    printf("\n Harmehar Kaur [CSE-1 04613202720]");
    getch();
    return 0;
}
