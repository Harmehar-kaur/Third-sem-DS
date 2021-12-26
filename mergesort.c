#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int r)
{
	int i = l;		 //keeps a track of left index
	int j = m + 1;	 //keeps a track of right index
	int k = l;		 //keeps a track of new index
	int temp[r + 1]; // r= size-1 as passed in main()
	while (i <= m && j <= r)
	{
		if (a[j] <= a[i])
		{
			temp[k] = a[j];
			j++;
			k++;
		}
		else
		{
			temp[k] = a[i];
			i++;
			k++;
		}
	}
	while (i <= m)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j <= r)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	for (int i = l; i <= r; i++) // i<=r as r is an index value not size
	{
		a[i] = temp[i];
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

int main()
{
	system("cls");
    int n;
	printf("\n size of array: ");
	scanf("%d", &n);
	int ar[n];
	printf("\n Enter elements: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ar[i]);
	}

	mergeSort(ar, 0, n - 1);
	printf("\n Sorted array : ");
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", ar[i]);
	}
	printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
}
