//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int fibanoci(int n,int *arr);
//int main()
//{
//	int n,i;
//	scanf("%d",&n);
//	int *arr = (int *)malloc(sizeof(int)*(n+1));
//	for (i = 0; i <=n; i++)
//		arr[i] = 0;
//	printf("%d",fibanoci(n,arr));
//	system("pause");
//	return 0;
//}
//int fibanoci(int n,int *arr)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//	if (arr[n] != 0)
//		return arr[n];
//	return arr[n]=(fibanoci(n - 1,arr) + fibanoci(n - 2,arr));
//}