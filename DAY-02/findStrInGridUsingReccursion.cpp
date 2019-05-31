//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int isFound(int i, int j, char **grid, int r, int c, char *str,int dir,int strIndx);
//void findMatching(char **grid, char *str, int r, int c);
//int di1(int ,int ,char ** ,int ,int ,char * ,int );
//int di2(int, int, char **, int, int, char *, int);
//int di3(int, int, char **, int, int, char *, int);
//int di4(int, int, char **, int, int, char *, int);
//int di5(int, int, char **, int, int, char *, int);
//int di6(int, int, char **, int, int, char *, int);
//int di7(int, int, char **, int, int, char *, int);
//int di8(int, int, char **, int, int, char *, int);
//int main()
//{
//	int r, c, i;
//	scanf("%d%d", &r, &c);
//	char **grid = (char **)malloc(sizeof(char *)*r);
//	char *str = (char *)malloc(100);
//	for (i = 0; i < r; i++)
//	{
//		grid[i] = (char *)malloc(c);
//		scanf("%s", grid[i]);
//	}
//
//	scanf("%s", str);
//	findMatching(grid, str, r, c);
//	system("pause");
//	return 0;
//}
//
//void findMatching(char **grid, char *str, int r, int c)
//{
//	int i, j, v,strIndx=0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			if (grid[i][j] == str[0])
//			{
//				v=di1(i,j,grid,r,c,str,strIndx);
//				if (v == 1)
//					printf("%d %d 1",i,j);
//				v=di2(i, j, grid, r, c, str, strIndx);
//				if (v == 1)
//					printf("%d %d 2", i, j);
//
//				v = di3(i, j, grid, r, c, str, strIndx);
//				if (v == 1)
//						printf("%d %d 3", i, j);
//
//				v=di4(i, j, grid, r, c, str, strIndx);
//				if (v == 1)
//					printf("%d %d 4", i, j);
//
//				v=di5(i, j, grid, r, c, str, strIndx);
//				if (v == 1)
//					printf("%d %d 5", i, j);
//
//				v=di6(i, j, grid, r, c, str, strIndx);
//				if (v == 1)
//					printf("%d %d 6", i, j);
//
//				v=di7(i, j, grid, r, c, str, strIndx);
//				if (v == 1)
//					printf("%d %d 7", i, j);
//
//				v=di8(i, j, grid, r, c, str, strIndx);
//				if (v == 1)
//					printf("%d %d 8", i, j);
//
//			}
//		}
//	}
//}
//
//int di1(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	i--;
//	strIndx++;
//	return di1(i, j, grid, r, c, str, strIndx);
//
//}
//
//int di2(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	i++;
//	strIndx++;
//	return di2(i, j, grid, r, c, str, strIndx);
//
//}
//
//int di3(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	j--;
//	strIndx++;
//	return di3(i, j, grid, r, c, str, strIndx);
//
//}
//
//int di4(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	j++;
//	strIndx++;
//	return di4(i, j, grid, r, c, str, strIndx);
//
//}
//
//int di5(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	i--;
//	j--;
//	strIndx++;
//	return di5(i, j, grid, r, c, str, strIndx);
//
//}
//
//int di6(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	i--;
//	j++;
//	strIndx++;
//	return di6(i, j, grid, r, c, str, strIndx);
//
//
//}
//
//int di7(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	i++;
//	j++;
//	strIndx++;
//    return di7(i, j, grid, r, c, str, strIndx);
//}
//
//int di8(int i, int j, char **grid, int r, int c, char *str, int strIndx)
//{
//	if (str[strIndx] == '\0')
//		return 1;
//
//	if (i < 0 || j < 0 || i >= r || j >= c)
//		return 0;
//	if (grid[i][j] != str[strIndx])
//		return 0;
//	i++;
//	j--;
//	strIndx++;
//	return di8(i, j, grid, r, c, str, strIndx);
//}