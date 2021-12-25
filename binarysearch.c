#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
    int n, ar[1000];
    int i = 1, item;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    printf("enter elements in sorted order:\n");
    while (i <= n)
    {
        printf("Element %d is:", i);
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
    printf("\n");
    //binary search algo
    printf("\n Enter the item to be searched:");
    scanf("%d", &item);
    int BEG = 1, END = n, MID;
    MID = (BEG + END) / 2;
    while (ar[MID] != item && BEG <= END)
    {
        if (item < ar[MID])
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
        MID = (BEG + END) / 2;
        BEG++;
    }
    if (ar[MID] == item)
        printf("\n element is at index number: %d", MID);
    else
        printf("\n item not found");
    printf("\n Harmehar Kaur [CSE-1 04613202720]");
    getch();
    return 0;
}
