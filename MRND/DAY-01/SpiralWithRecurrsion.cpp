#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void spiralRecursion(int jlow,int jhigh,int ilow,int ihigh,int** arr,int r,int c,int k,int *spiral);
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
	spiralRecursion(jlow,jhigh,ilow,ihigh,arr,r,c,0,spiral);
	for (i = 0; i<c*r; i++)
		printf("%d ", spiral[i]);
	system("pause");

	return 0;
}
void spiralRecursion(int jlow, int jhigh, int ilow, int ihigh, int** arr, int r, int c, int k, int *spiral)
{
	int i, j;
	if (k<(c*r))
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
		spiralRecursion(jlow, jhigh, ilow, ihigh, arr, r, c, k, spiral);
	}

}