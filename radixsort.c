#include <stdlib.h>
#include <stdio.h>
#define size 100
int largest(int a[], int n)
{
	int large = a[0], i;
	for (i = 1; i < n; i++)
	{
		if (a[i] > large)
			large = a[i];
	}
	return large;
}
void radix_sort(int a[], int n)
{

	int i, j, k, rem, d = 0, div = 1, large, pass;
	large = largest(a, n);
	while (large > 0)
	{
		d++;
		large /= size;
	}
	int bucket[size][size], bucketcount[size];
	for (pass = 0; pass < d; pass++)
	{
		for (i = 0; i < size; i++)
			bucketcount[i] = 0;
		for (i = 0; i < n; i++)
		{
			rem = (a[i] / div) % size;
			bucket[rem][bucketcount[rem]] = a[i];
			bucketcount[rem] += 1;
		}
		i = 0;
		for (k = 0; k < size; k++)
		{
			for (j = 0; j < bucketcount[k]; j++)
			{
				a[i] = bucket[k][j];
				i++;
			}
		}
		div *= size;
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
	radix_sort(x, m);
	printf("\n Sorted array is: \n");
	for (i = 0; i < m; i++)
		printf(" %d ", x[i]);
	printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
}
