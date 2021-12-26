// to implement sparse matrix using array 
#include <stdio.h>
#include <stdlib.h>
void main()
{
    system("cls");
    int i, j, a[50][50], b[50][50];
    int n, m, t = 0;

    printf("enter the no of rows: ");
    scanf("%d", &n);

    printf("enter the no of column: ");
    scanf("%d", &m);
    printf("enter matrix elements: \n");
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= m; j++)

        {

            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
            {
                t = t + 1;
            }
        }
    }

    b[1][1] = n;
    b[1][2] = m;
    b[1][3] = t;
    int q = 2;

    for (i = 1; i <= n; i++)

    {

        for (j = 1; j <= m; j++)

        {

            if (a[i][j] != 0)

            {
                b[q][1] = i;
                b[q][2] = j;
                b[q][3] = a[i][j];
                q = q + 1;
            }
        }
    }

    printf("sparse matrix is : \n");
    for (int i = 1; i <= t + 1; i++)
    {

        for (j = 1; j <= 3; j++)

        {

            printf("%d ", b[i][j]);
        }

        printf("\n");
    }
printf("\nHarmehar kaur (04613202720 CSE1) \n");    
}
