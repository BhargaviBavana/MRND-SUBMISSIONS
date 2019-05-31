//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<Windows.h>
//int **create_data(int rows,int cols);
//void input_call(int **data,int rows,int cols);
//void get_command(char *commandStr, int **data,int rows,int cols);
//void set(char *commandStr, int commandStrIndx, int **data);
//int removespaces(char *commandStr, int commandStrIndx);
//int pow(int a, int b);
//void upper(char *str);
//void get(char *commandStr, int commandStrIndx, int **data);
//void print(char *commandStr, int commandStrIndx, int **data,int rows,int cols);
//void exportTo(char *commandStr, int commandStrIndx, int **data,int rows,int cols);
//void import(char *commandstr, int commandStrIndx, int **data);
//int convertToInt(char *str);
//int findColId(char *colId);
//int findRowId(char *rowId);
//void exportTo(char *commandStr, int commandStrindx, int **data, int rows, int cols);
//void import(char *commandStr, int indx, int **data, int rows, int cols);
//char *convertToStr(int data);
//
//int main()
//{
//	int **data = create_data(10,10);
//	while (!GetAsyncKeyState(VK_CONTROL))
//		input_call(data,10,10);
//
//	system("pause");
//	return 0;
//}
//int **create_data(int rows,int cols)
//{
//	int **data = (int **)malloc(sizeof(int) * rows);
//	int i;
//	for (i = 0; i < rows; i++)
//		data[i] = (int *)calloc(sizeof(int), cols);
//	return data;
//}
//
//void input_call(int **data,int rows,int cols)
//{
//	printf(">");
//	
//	char *commandStr = (char *)malloc(100);
//	fgets(commandStr, 100, stdin);
//	get_command(commandStr, data,rows,cols);
//}
//
//void get_command(char *commandStr, int **data,int rows,int cols)
//{
//	int commandStrIndx, commandIndx = 0;
//	char *command = (char *)malloc(10);
//	commandStrIndx=removespaces(commandStr,0);
//	for (; commandStr[commandStrIndx] != ' ' && commandStr[commandStrIndx] != '\0' && commandStr[commandStrIndx] != '\n'; commandStrIndx++, commandIndx++)
//		command[commandIndx] = commandStr[commandStrIndx];
//	command[commandIndx] = '\0';
//	upper(command);
//	if (strcmp(command, "SET") == 0)
//		set(commandStr, commandStrIndx, data);
//	if (strcmp(command, "GET") == 0)
//		get(commandStr, commandStrIndx, data);
//	if (strcmp(command, "PRINT") == 0)
//		print(commandStr, commandStrIndx, data,rows,cols);
//	if (strcmp(command, "EXPORT") == 0)
//		exportTo(commandStr, commandStrIndx, data,rows,cols);
//	if (strcmp(command, "IMPORT") == 0)
//		import(commandStr, commandStrIndx, data,rows,cols);
//}
//
//void set(char *commandStr, int commandStrIndx, int **data)
//{
//	int value,expIndx;
//	commandStrIndx = removespaces(commandStr, commandStrIndx);
//	if (commandStrIndx == -1)
//		return;
//	char *rowId = (char *)malloc(10);
//	char *colId = (char *)malloc(10);
//	char *exp = (char *)malloc(20);
//	int k = 0;
//	for (; !(commandStr[commandStrIndx] >= '1' && commandStr[commandStrIndx] <= '9'); commandStrIndx++, k++)
//	{
//		colId[k] = commandStr[commandStrIndx];
//	}
//	colId[k] = '\0';
//	k = 0;
//	for (; commandStr[commandStrIndx] >= '1' && commandStr[commandStrIndx] <= '9'; commandStrIndx++, k++)
//	{
//		rowId[k] = commandStr[commandStrIndx];
//	}
//	rowId[k] = '\0';
//	commandStrIndx = removespaces(commandStr, commandStrIndx);
//	if (commandStr[commandStrIndx] != '=')
//		return;
//	commandStrIndx++;
//	commandStrIndx = removespaces(commandStr, commandStrIndx);
//	k = 0;
//	for (; commandStr[commandStrIndx] != '\n'; commandStrIndx++, k++)
//	{
//		exp[k] = commandStr[commandStrIndx];
//	}
//	exp[k] = '\0';
//	value = 0;
//	for (expIndx = 0; exp[expIndx] != '\0'; expIndx++)
//	{
//		value = value * 10 + (exp[expIndx] - '0');
//	}
//	int row_id = findRowId(rowId);
//	int col_id = findColId(colId);
//	data[row_id][col_id] = value;
//}
//
//
//void get(char *commandStr, int commandStrIndx, int **data)
//{
//	int k;
//	char *colId = (char *)malloc(10);
//	char *rowId = (char *)malloc(10);
//	commandStrIndx = removespaces(commandStr, commandStrIndx);
//	k = 0;
//	for (; !(commandStr[commandStrIndx] >= '1' && commandStr[commandStrIndx] <= '9'); commandStrIndx++, k++)
//	{
//		colId[k] = commandStr[commandStrIndx];
//	}
//	colId[k] = '\0';
//	k = 0;
//	for (; commandStr[commandStrIndx] >= '1' && commandStr[commandStrIndx] <= '9'; commandStrIndx++, k++)
//	{
//		rowId[k] = commandStr[commandStrIndx];
//	}
//	rowId[k] = '\0';
//	int row_id = findRowId(rowId);
//	int col_id = findColId(colId);
//	printf("%d\n",data[row_id][col_id]);
//}
//
//void print(char *commandStr, int commandStrindx, int **data,int rows,int cols)
//{
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			printf("%d ", data[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//void exportTo(char *commandStr, int commandStrIndx, int **data, int rows, int cols)
//{
//	int strIndx, numStrIndx;
//	commandStrIndx = removespaces(commandStr, commandStrIndx);
//	if (commandStrIndx == -1)
//		return;
//	char *filename = (char *)malloc(15);
//	int fileIndx=0,flag;
//	for (; commandStr[commandStrIndx] != '\0' && commandStr[commandStrIndx] != ' ' && commandStr[commandStrIndx] != '\n'; commandStrIndx++, fileIndx++)
//	{
//		filename[fileIndx] = commandStr[commandStrIndx];
//		if (commandStr[commandStrIndx] == '.')
//			flag = 1;
//	}
//	if (flag == 0)
//	{
//		filename[fileIndx] = '.';
//		fileIndx++;
//		filename[fileIndx] = 'c';
//		fileIndx++;
//		filename[fileIndx] = 's';
//		fileIndx++;
//		filename[fileIndx] = 'v';
//		fileIndx++;
//	}
//	filename[fileIndx] = '\0';
//	FILE *fp;
//	fp = fopen(filename, "w");
//	int rowIndx,colIndx;
//	char *str = (char *)malloc(100);
//	char *numstr = (char *)malloc(100);
//	for (rowIndx = 0; rowIndx < rows; rowIndx++)
//	{
//		strIndx=0;
//		for (colIndx = 0; colIndx < cols; colIndx++)
//		{
//			_itoa(data[rowIndx][colIndx],numstr,10);
//			for (numStrIndx = 0; numstr[numStrIndx] != '\0'; numStrIndx++, strIndx++)
//				str[strIndx] = numstr[numStrIndx];
//
//			str[strIndx]= ',';
//			strIndx++;
//		}
//		str[strIndx] = '\n';
//		strIndx++;
//		str[strIndx] = '\0';
//		fputs(str,fp);
//	}
//	fclose(fp);
//}
//
//void import(char *commandStr, int commandStrIndx, int **data, int rows, int cols)
//{
//	int fileIndx=0,d = 0,row_id,col_id;
//	commandStrIndx = removespaces(commandStr, commandStrIndx);
//	char *filename = (char *)malloc(20);
//	char *res = (char *)malloc(20);
//	for (; commandStr[commandStrIndx] != '\0' && commandStr[commandStrIndx] != '\n' && commandStr[commandStrIndx] != ' '; commandStrIndx++, fileIndx++)
//		filename[fileIndx] = commandStr[commandStrIndx];
//	filename[fileIndx] = '\0';
//	FILE *fp;
//	fp = fopen(filename, "r");
//	if (fp == NULL)
//	{
//		printf("Fille does not exists\n");
//		return;
//	}
//	for (row_id = 0; row_id < rows; row_id++)
//	{
//		for (col_id = 0; col_id < cols; col_id++)
//		{
//			fscanf(fp,"%[^,]s",res);
//			//printf("%s",res);
//			fscanf(fp, ",");
//			data[row_id][col_id] = convertToInt(res);
//		}
//		fscanf(fp,"\n");
//	}
//	
//}
//
//
//int removespaces(char *commandStr, int indx)
//{
//	int i;
//	for (i = indx; commandStr[i] != '\0' && commandStr[i] == ' '; i++)
//	{
//	}
//	if (commandStr[i] == '\0')
//		return -1;
//	return i;
//}
//int findRowId(char *rowId)
//{
//	int i, r = 0;
//	for (i = 0; rowId[i] != '\0'; i++)
//	{
//		r = r * 10 + (rowId[i] - '1');
//	}
//	return r;
//}
//int findColId(char *colId)
//{
//	int i, c = 0;
//	for (i = 0; colId[i] != '\0'; i++)
//	{
//		c = c * 10 + (colId[i] - 'A');
//	}
//	return c;
//}
//char *convertToStr(int data)
//{
//	int reversedata = 0,indx=0,duplicatedata=data;
//
//	if (data == 0)
//		return "0";
//	while (data)
//	{
//		reversedata = reversedata * 10 + data % 10;
//		data = data / 10;
//	}
//	char *str=(char *)malloc(100);
//	while (reversedata)
//	{
//		str[indx] = (reversedata % 10) + '0';
//		indx++;
//		reversedata = reversedata / 10;
//	}
//	if (duplicatedata % 10 == 0)
//		str[indx] = '0';
//	indx++;
//	str[indx] = '\0';
//	return str;
//}
//
//void upper(char *str)
//{
//	int i;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		if (str[i] >= 97 && str[i] <= 122)
//			str[i] = str[i] - 32;
//	}
//}
//int convertToInt(char *str)
//{
//	int i, value = 0;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		value = value * 10 + str[i] - '0';
//	}
//	return value;
//}