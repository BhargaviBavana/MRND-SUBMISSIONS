#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *arr, int noOfELm);
int main()
{
	int noOfElm,indx;
	scanf("%d",&noOfElm);
	int *arr = (int *)malloc(sizeof(int)*noOfElm);
	for (indx = 0; indx < noOfElm; indx++)
		scanf("%d", &arr[indx]);

	bubbleSort(arr, noOfElm);

	for (indx = 0; indx < noOfElm; indx++)
		printf("%d ",arr[indx]);
	system("Pause");
	return 0;
}
int bubbleSort(int *arr, int noOfElm)
{
	int poss = 1, indx, temp;
	while (poss)
	{
		poss = 0;
		for (indx = 0; indx<noOfElm - 1; indx++)
		{
			if (arr[indx]>arr[indx + 1])
			{
				temp = arr[indx];
				arr[indx] = arr[indx + 1];
				arr[indx + 1] = temp;
				poss = 1;
			}
		}
	}
	return 0;
}
