#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int *arr, int n);
int main()
{
	int noOfElm,indx;
	scanf("%d",&noOfElm);
	int *arr = (int *)malloc(sizeof(int)*noOfElm);
	for (indx = 0; indx < noOfElm; indx++)
	{
		scanf("%d",&arr[indx]);
	}

	sort(arr,noOfElm);
	for (indx = 0; indx < noOfElm; indx++)
	{
		printf("%d ", arr[indx]);
	}
	system("pause");
	return 0;
}
void sort(int *arr, int noOfElm)
{
	int low = 0, high = noOfElm - 1,i;
	while(1)
	{
		while (arr[low] == 0)
			low++;
		while (arr[high] > 0)
			high--;
		if (low >= high)
			break;
		else
		{
			arr[high] = arr[low];
			arr[low] = 0;
		}
	}
	high = noOfElm - 1;
	while (1)
	{
		while (arr[low] == 1)
			low++;
		while (arr[high] == 2)
			high--;
		if (low >= high)
			break;
		else
		{
			arr[high] = 2;
			arr[low] = 1;
		}
	}
}