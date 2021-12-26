#include <stdio.h>
#include <stdlib.h>
void shellsort(int a[], int n)
{
    int gap = n, i, temp, flag = 1;
    while (flag == 1 || gap > 1)
    {
        flag = 0;
        gap = (gap + 1) / 2;
        for (i = 0; i < (n - gap); i++)
        {
            if (a[i + gap] < a[i])
            {
                temp = a[i + gap];
                a[i + gap] = a[i];
                a[i] = temp;
                flag = 0;
            }
        }
    }
}
int main()
{
    system("cls");
    int m, i;
    printf("\n Enter no. of elements: ");
    scanf("%d", &m);
    int x[m];
    printf("\n Enter elements: \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &x[i]);
    }
    shellsort(x, m);
    printf("\n Sorted array is : \n");
    for (i = 0; i < m; i++)
        printf(" %d ", x[i]);
    printf("\n Harmehar Kaur (CSE-1 04613202720)Shell Sort\n");
}
