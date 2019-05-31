#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r, c, i, j;
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
	int **transpose = (int **)malloc(sizeof(int *)*c);
	for (i = 0; i < c; i++)
		transpose[i] = (int *)malloc(sizeof(int)*r);
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			transpose[i][j] = arr[j][i];
			printf("%d ", transpose[i][j]);
		}
		printf("\n");
	}
	return 0;
}
