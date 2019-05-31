//# define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int convertToInt(char *str);
//int main()
//{
//	int indx = 0,num=0;
//	char *fileName = (char *)malloc(10);
//	char *numStr = (char *)malloc(10);
//	scanf("%s",fileName);
//	FILE *fp = fopen(fileName, "r");
//	if (fp == NULL)
//		printf("file doesnot exists\n");
//	int *a = (int *)calloc(sizeof(int),10000000);
//	for (; indx < 1000000; indx++)
//	{
//		fscanf(fp,"%[^\n]s",numStr);
//		fscanf(fp, "\n");
//		num = convertToInt(numStr);
//		a[num] = 1;
//	}
//	for (indx = 0; indx < 10000000; indx++)
//	{
//		if (a[indx] == 1)
//			printf("%d\n",indx);
//	}
//	fclose(fp);
//	system("pause");
//	return 0;
//}
//
//int convertToInt(char *str)
//{
//	int i, value = 0;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		value = value * 10 + str[i] - '0';
//	}
//	return value;
//}