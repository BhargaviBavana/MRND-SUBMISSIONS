#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void printSeries(int n,int *arr,int indx);
void print(int *arr,int indx);
int power(int a, int indx);
int main()
{
	int n,i;
	scanf("%d",&n);
	int *arr = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		arr[i] = 0;
	printSeries(n,arr,0);
	system("pause");
	return 0;
}
void printSeries(int n, int *arr, int indx)
{
	int i;
	if (indx==n-1)
	{
		for (i = 0; i <=9; i++)
		{
			arr[indx] = i;
			print(arr, indx);
		}
	}
	else
	{
		for (i = 0; i <=9; i++)
		{
			arr[indx] = i;
			printSeries(n, arr, indx + 1);
		}
	}
}

void print(int *arr, int indx)
{
	int res = 0,i=0;
	while (indx >= 0)
	{
		res += arr[i] * power(10, indx);
		i++;
		indx--;
	}
	printf("%d\n",res);
}

int power(int a, int indx)
{
	int res = 1, i;
	for (i = 0; i < indx; i++)
	{
		res *= a;
	}
	return res;
}