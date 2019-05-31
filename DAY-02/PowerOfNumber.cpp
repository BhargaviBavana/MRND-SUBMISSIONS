#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

long powerA(int a, int n);
int main()
{
	int a, n;
	long res;
	scanf("%d%d",&a,&n);
	res=powerA(a, n);
	res = res % (powerA(10, 9) + 7);
	printf("%ld",res);
	system("pause");
	return 0;
}
long powerA(int a, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	if (n % 2 != 0)
		return powerA(a, n / 2)*powerA(a, n / 2)*a;
	return powerA(a, n / 2)*powerA(a, n / 2);
}