#include <stdio.h>
#include <stdlib.h>
int main()
{
    system("cls");
    int n;
    printf("\n Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("\n Enter elements: \n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        printf("\n %d", i);
        printf(".");
        for (int x = 0; x < n; x++)
        {
            printf(" %d ", a[x]);
        }
    }

    printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
}
