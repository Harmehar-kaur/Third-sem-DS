#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("\n Enter number of elements ");
    scanf("%d", &n);
    int a[n];
    printf("\n Enter elements ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++)
    {

        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
        printf("\n %d", i);
        printf(".");
        for (int x = 0; x < n; x++)
        {
            printf(" %d ", a[x]);
        }
    }

    printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
}
