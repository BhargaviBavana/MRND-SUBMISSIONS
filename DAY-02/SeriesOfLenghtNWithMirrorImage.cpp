#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void printSeries(int n, int *arr, int indx);
void mirrorImage(int *arr, int indx);

int main()
{
	int n, i;
	scanf("%d", &n);
	int *arr = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		arr[i] = 0;
	printSeries(n, arr, 0);
	system("pause");
	return 0;
}
void printSeries(int n, int *arr, int indx)
{
	int i;
	if (indx == n - 1)
	{
		for (i = 0; i <= 9; i++)
		{
			arr[indx] = i;
			mirrorImage(arr, indx);
		}
	}
	else
	{
		for (i = 0; i <= 9; i++)
		{
			arr[indx] = i;
			printSeries(n, arr, indx + 1);
		}
	}
}

void mirrorImage(int *arr,int n)
{
	int i;
	char map[10];
	map[0] = '0';
	map[1] = '1';
	map[2] = '2';
	map[3] = 'E';
	map[4] = 'h';
	map[5] = '5';
	map[6] = '9';
	map[7] = 'L';
	map[8] = '8';
	map[9] = '6';
	for (i = 0; i <= n; i++)
	{
		printf("%c",map[arr[i]]);
	}
	printf("\n");
}