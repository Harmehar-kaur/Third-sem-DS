#include <stdio.h>
#include <math.h>
int main()
{
    system("cls");
    int n, ar[1000]; //number of elements in array
    int i = 1, k;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("element [%d] is:", i);
        scanf("%d", &ar[i]);
        i++;
    }
    printf("\n The array is: \n");
    i = 1;
    while (i <= n)
    {
        printf("%d ", ar[i]);
        i++;
    }
    //deletion
    printf("\nEnter position to be deleted:");
    scanf("%d", &k);
    i = k + 1;
    while (i <= n)
    {
        ar[i - 1] = ar[i];
        i++;
    }
    n = n - 1;
    i = 1;
    printf("\n New array after deletion: \n");
    while (i <= n)
    {
        printf("%d ", ar[i]);
        i++;
    }
    printf("\n Harmehar Kaur [CSE-1 04613202720]");
    return 0;
}
