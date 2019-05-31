//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int fibbo(int n);
//int **findAN(int n);
//int **matrixMultiplication(int **a,int **b,int r1,int c1,int r2,int c2);
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	printf("%d",fibbo(n));
//	system("pause");
//	return 0;
//}
//int fibbo(int n)
//{
//	if (n == 1)
//		return 0;
//	if (n == 2)
//		return 1;
//	int i, j;
//	int **AN=(int **)malloc(sizeof(int *)*2);
//	AN[0] = (int *)malloc(sizeof(int) * 2);
//	AN[1] = (int *)malloc(sizeof(int) * 2);
//	AN = findAN(n);
//	
//	int **xo = (int **)malloc(sizeof(int) * 2);
//	xo[0] = (int *)malloc(sizeof(int) * 1);
//	xo[1] = (int *)malloc(sizeof(int) * 1);
//	xo[0][0] = 0;
//	xo[1][0] = 1;
//	int **res = (int **)malloc(sizeof(int) * 2);
//	res[0] = (int *)malloc(sizeof(int) * 1);
//	res[1] = (int *)malloc(sizeof(int) * 1);
//	
//	res=matrixMultiplication(AN,xo,2,2,2,1);
//	
//	return res[0][0];
//}
//
//int **findAN(int n)
//{
//	int **A = (int **)malloc(sizeof(int *) * 2);
//	A[0] = (int *)malloc(sizeof(int) * 2);
//	A[1] = (int *)malloc(sizeof(int) * 2);
//	A[0][0] = 0;
//	A[0][1] = 1;
//	A[1][0] = 1;
//	A[1][1] = 1;
//	if (n == 1)
//		return A;
//	return matrixMultiplication(A,findAN(n-1),2,2,2,2);
//}
//
//int **matrixMultiplication(int **a, int **b, int r1, int c1, int r2, int c2)
//{
//	int i,j,k,s;
//	int **res = (int **)malloc(sizeof(int)*r1);
//	for (i = 0; i < r1; i++)
//	{
//		res[i] = (int *)malloc(sizeof(int)*c2);
//	}
//
//	for (i = 0; i < r1; i++)
//	{
//		for (j = 0; j < c2; j++)
//		{
//			s = 0;
//			for (k = 0; k < c1; k++)
//			{
//				s += a[i][k] * b[k][j];
//			}
//			res[i][j] = s;
//		}
//	}
//	return res;
//}
