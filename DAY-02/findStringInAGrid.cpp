//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int isFound(int i,int j,char **grid,int r,int c,char *str);
//void findMatching(char **grid,char *str,int r,int c);
//int main()
//{
//	int r, c,i;
//	scanf("%d%d",&r,&c);
//	char **grid = (char **)malloc(sizeof(char *)*r);
//	char *str = (char *)malloc(100);
//	for (i = 0; i < r; i++)
//	{
//		grid[i] = (char *)malloc(c);
//		scanf("%s", grid[i]);
//	}
//	
//	scanf("%s",str);
//	findMatching(grid,str,r,c);
//	system("pause");
//	return 0;
//}
//
//void findMatching(char **grid,char *str,int r,int c)
//{
//	int i,j,v;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			if (grid[i][j] == str[0])
//			{
//				v=isFound(i,j,grid,r,c,str);
//				if (v == 1)
//					printf("%d %d",i,j);
//			}
//		}
//	}
//}
//
//int isFound(int i, int j, char **grid, int r, int c, char *str)
//{
//	int strIndx = 1,i1,j1;
//	j1 = j;
//	i1 = i-1;
//	for (; i1 >= 0; i1--)
//	{
//		if (grid[i1][j1] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	j1 = j;
//	i1 = i + 1;
//	for (; i1 < r; i1++)
//	{
//		if (grid[i1][j1] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	j1 = j-1;
//	i1 = i;
//	for (; j1 >= 0; j1--)
//	{
//		if (grid[i1][j1] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	j1 = j+1;
//	i1 = i1;
//	for (; j1 < c; j1++)
//	{
//		if (grid[i1][j1] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	j1 = j-1;
//	i1 = i - 1;
//	for (; i1 >= 0 && j1>=0; i1--,j1--)
//	{
//		if (grid[i1][j1] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	j1 = j+1;
//	i1 = i - 1;
//	for (; i1 >= 0 && j1<c; i1--,j1++)
//	{
//		if (grid[i1][j1] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	j1 = j+1;
//	i1 = i + 1;
//	for (; i1<r && j1<c; i1++,j1++)
//	{
//		if (grid[i1][j1] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	j1 = j-1;
//	i1 = i + 1;
//	for (; i1 < r && j1>=0; i1++,j1--)
//	{
//		if (grid[i][j] != str[strIndx])
//			break;
//		else
//		{
//			strIndx++;
//			if (str[strIndx] == '\0')
//				return 1;
//		}
//	}
//	return 0;
//}