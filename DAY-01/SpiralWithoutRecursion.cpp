#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r, c, i, j, k = 0, jlow, jhigh, ilow, ihigh;
	scanf("%d%d", &r, &c);
	int **arr = (int **)malloc(sizeof(int *)*r);
	for (i = 0; i < r; i++)
		arr[i] = (int *)malloc(sizeof(int)*c);
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int *spiral = (int *)malloc(sizeof(int)*r*c);
	jlow = 0, jhigh = c - 1, ilow = 0, ihigh = r - 1;
	while (k<(c*r))
	{
		i = ilow;
		for (j = jlow; j <= jhigh; j++)
		{
			spiral[k] = arr[i][j];
			k++;
		}
		j = j - 1;
		for (i = ilow + 1; i <= ihigh; i++)
		{
			spiral[k] = arr[i][j];
			k++;
		}
		i = i - 1;
		for (j = jhigh - 1; j >= jlow; j--)
		{
			spiral[k] = arr[i][j];
			k++;
		}
		j = j + 1;
		for (i = ihigh - 1; i >= ilow + 1; i--)
		{
			spiral[k] = arr[i][j];
			k++;
		}
		jlow++;
		jhigh--;
		ilow++;
		ihigh--;
	}
	for (i = 0; i<c*r; i++)
		printf("%d ", spiral[i]);
	system("pause");
	return 0;
}
