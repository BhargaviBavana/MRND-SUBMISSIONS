#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int sumOfArrayElm(int *a, int indx, int len);
int main()
{
	int n,i;
	scanf("%d",&n);
	int *arr = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%d",sumOfArrayElm(arr,0,n));
	return 0;
}





int sumOfArrayElm(int *a, int indx,int len)
{
	if (indx >= len)
		return 0;
	return a[indx] + sumOfArrayElm(a, indx + 1, len);
}