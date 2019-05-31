#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int findSteps(int n,int k);
int main()
{
	int n, k,res;
	scanf("%d%d",&n,&k);
	res=findSteps(n,k);
	printf("%d",res);
	system("pause");
	return 0;
}
int findSteps(int n,int k)
{
	if (n <=k)
		return n;
	int noOfsteps = 0,i;
	for (i = 1; i <= k; i++)
	{
		noOfsteps += findSteps(n-i,k);
	}
	return noOfsteps;
}