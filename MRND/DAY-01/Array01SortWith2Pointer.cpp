#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sortWith2Pointer(int *arr, int noOfELm);
int main()
{
	int noOfElm, indx;
	scanf("%d", &noOfElm);
	int *arr = (int *)malloc(sizeof(int)*noOfElm);
	for (indx = 0; indx < noOfElm; indx++)
		scanf("%d", &arr[indx]);

	sortWith2Pointer(arr, noOfElm);

	for (indx = 0; indx < noOfElm; indx++)
		printf("%d ", arr[indx]);

	system("Pause");
	return 0;
}
void sortWith2Pointer(int *arr, int noOfElm)
{
	int low=0, high=noOfElm-1;
	while(1)
	{
		while (arr[low] == 0)
			low++;
		while (arr[high] == 1)
			high--;
		if (low >= high)
			break;
		else
		{
			arr[low] = 0;
			arr[high] = 1;
		}
	}
}
