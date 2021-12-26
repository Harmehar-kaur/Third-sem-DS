#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
    int n, ar[1000];//nis the number of elements in array,ar is the linear array
    int i = 1, ele;//ele=element
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("Element [%d] is:", i);
        scanf("%d", &ar[i]);
        i++;
    }
    printf("The array is: \n");
    i = 1;
    while (i <= n)
    {
        printf("%d ", ar[i]);
        i++;
    }
    //linear search algo
    printf("\nEnter the element to be searched:");
    scanf("%d", &ele);
    i = 1;
    int k = 1;
    int loc = 0;//loc =location or position of element searched 
    while (loc == 0 && k <= n)
    {
        if (ele == ar[k])
        {
            loc = k;
        }
        k++;
    }
    if (loc == 0)
        printf("\nElement is not in the array");
    else
        printf("Location of element  is: %d", k - 1);
    printf("\n Harmehar Kaur [CSE-1 04613202720]");
    getch();
    return 0;
}
