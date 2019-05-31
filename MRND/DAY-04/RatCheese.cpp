#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int findPathFromStartToENd(int ,int ,int ,int ,int ** ,int ,int ,int ,int ** ,int );
int main()
{
	int grid_rows, grid_colouns,rowIndx,colIndx,noOfObstacles,startIndxI,startIndxJ,endIndxI,endIndxJ;
	scanf("%d%d",&grid_rows,&grid_colouns);
	int **grid = (int **)calloc(sizeof(int *),grid_rows);
	for (rowIndx = 0; rowIndx < grid_rows; rowIndx++)
		grid[rowIndx] = (int *)calloc(sizeof(int),grid_colouns);
	int **path = (int **)calloc(sizeof(int) , 2);
	path[0] = (int *)calloc(sizeof(int),(grid_rows*grid_colouns));
	path[1] = (int *)calloc(sizeof(int), (grid_rows*grid_colouns));
	scanf("%d",&noOfObstacles);
	while (noOfObstacles)
	{
		scanf("%d%d", &rowIndx, &colIndx);;
		grid[rowIndx][colIndx] = -1;
		noOfObstacles--;
	}
	scanf("%d%d%d%d",&startIndxI,&startIndxJ,&endIndxI,&endIndxJ);
	findPathFromStartToENd(startIndxI,startIndxJ,endIndxI,endIndxJ,grid,grid_rows,grid_colouns,1,path,0);
	for (colIndx = 0; colIndx < (grid_rows*grid_colouns); colIndx++)
		printf("%d ",path[0][colIndx]);
	printf("\n");
	for (colIndx = 0; colIndx < (grid_rows*grid_colouns); colIndx++)
		printf("%d ", path[1][colIndx]);
	system("pause");
	return 0;
}

int findPathFromStartToENd(int startIndxI,int startIndxJ,int endIndxI,int endIndxJ,int **grid,int grid_rows,int grid_colouns,int direction,int **path,int pathIndx)
{
	int poss=0;
	if (startIndxI < 0 || startIndxI >= grid_rows || startIndxJ < 0 || startIndxJ >= grid_colouns || (grid[startIndxI][startIndxJ] == -1))
		return 0;
	if (startIndxI == endIndxI && startIndxJ == endIndxJ)
		return 1;
	if (direction == 1)
	{
		path[0][pathIndx] = startIndxI;
		path[1][pathIndx] = startIndxJ;
		pathIndx++;
		poss=findPathFromStartToENd(startIndxI,startIndxJ+1,endIndxI,endIndxJ,grid,grid_rows,grid_colouns,1,path,pathIndx);
		if (poss = 0)
			pathIndx--;
	}
	if (direction == 2)
	{
		path[0][pathIndx] = startIndxI;
		path[1][pathIndx] = startIndxJ;
		pathIndx++;
		poss = findPathFromStartToENd(startIndxI, startIndxJ - 1, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 2, path, pathIndx);
		if (poss = 0)
			pathIndx--;


	}
	if (direction == 3)
	{
		path[0][pathIndx] = startIndxI;
		path[1][pathIndx] = startIndxJ;
		pathIndx++;
		poss = findPathFromStartToENd(startIndxI-1, startIndxJ, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 3, path, pathIndx);
		if (poss = 0)
			pathIndx--;

	}
	if (direction == 4)
	{
		path[0][pathIndx] = startIndxI;
		path[1][pathIndx] = startIndxJ;
		pathIndx++;
		poss = findPathFromStartToENd(startIndxI+1, startIndxJ, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 4, path, pathIndx);
		if (poss = 0)
			pathIndx--;

	}
	if (direction == 1)
	{
		findPathFromStartToENd(startIndxI -1, startIndxJ, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 3, path, pathIndx);
		findPathFromStartToENd(startIndxI + 1, startIndxJ, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 4, path, pathIndx);
	}
	if (direction == 2)
	{
		findPathFromStartToENd(startIndxI - 1, startIndxJ, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 3, path, pathIndx);
		findPathFromStartToENd(startIndxI + 1, startIndxJ, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 4, path, pathIndx);
	}
	if (direction == 3)
	{
		findPathFromStartToENd(startIndxI, startIndxJ-1, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 2, path, pathIndx);
		findPathFromStartToENd(startIndxI, startIndxJ+1, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 1, path, pathIndx);
	}
	if (direction == 4)
	{
		findPathFromStartToENd(startIndxI , startIndxJ-1, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 2, path, pathIndx);
		findPathFromStartToENd(startIndxI, startIndxJ+1, endIndxI, endIndxJ, grid, grid_rows, grid_colouns, 1, path, pathIndx);
	}
	return poss;
}