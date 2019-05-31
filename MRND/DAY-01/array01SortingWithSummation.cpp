#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sortWithSummation(int *arr, int noOfELm);
int main()
{
	int noOfElm, indx;
	scanf("%d",&noOfElm);
	int *arr = (int *)malloc(sizeof(int)*noOfElm);
	for (indx = 0; indx < noOfElm; indx++)
	    scanf("%d", &arr[indx]);
	
	sortWithSummation(arr, noOfElm);

	for (indx = 0; indx < noOfElm; indx++)
		printf("%d ",arr[indx]);

	system("Pause");
	return 0;
}
void sortWithSummation(int *arr, int noOfElm)
{
	int indx,sum=0;
	for (indx = 0; indx < noOfElm;indx++)
	{ 
		sum += arr[indx];
	}
	for (indx = 0; indx < noOfElm-sum; indx++)
	{
		arr[indx] = 0;
	}
	for (; indx < noOfElm; indx++)
	{
		arr[indx] = 1;
	}
}
