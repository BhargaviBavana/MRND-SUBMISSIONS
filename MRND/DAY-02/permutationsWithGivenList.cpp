#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void print(int *arr, int indx);
int power(int a, int indx);
void findPermutations(int *givenList, int n, int *arr, int indx,int *included);
int main()
{
	int n,i;
	scanf("%d",&n);
	int *givenList = (int *)malloc(sizeof(int)*n);
	int *arr = (int *)malloc(sizeof(int)*n);
	int *included = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&givenList[i]);
		arr[i] = 0;
		included[i] = 0;
	}
	findPermutations(givenList,n,arr,0,included);
	system("pause");
	return 0;
}
void findPermutations(int *givenList, int n, int *arr, int indx, int *included)
{
	int i;
	if (indx == n - 1)
	{
		for (i = 0; i < n; i++)
		{
			if (included[i] == 0)
			{
				arr[indx] = givenList[i];
				break;
			}
		}
		print(arr, indx);
	}
	for (i = 0; i < n; i++)
	{
		if (included[i] == 0)
		{
			included[i] = 1;
			arr[indx] = givenList[i];
			findPermutations(givenList, n, arr, indx + 1, included);
			included[i] = 0;
		}
	}
}

void print(int *arr, int indx)
{
	int res = 0, i = 0;
	while (indx >= 0)
	{
		res += arr[i] * power(10, indx);
		i++;
		indx--;
	}
	printf("%d\n", res);
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