//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<Windows.h>
//struct node
//{
//	int data;
//	char *exp;
//	struct node **list;
//};
//int findRowId(char *rowId);
//int findColId(char *colId);
//void input_call(struct node ***data,int rows,int cols);
//struct node ***create_data(int roes,int cols);
//struct node *create_node();
//void get_command(char *commandStr, struct node ***data, int rows, int cols);
//int removespaces(char *commandStr, int indx);
//void upper(char *str);
//void set(char *commandStr, int commandStrIndx, struct node ***data);
//int parseString(char *exp, struct node *currentCell,struct node ***data);
//void get(char *commandStr, int commandStrIndx, struct node ***data);
//void print(char *commandStr, int commandStrindx, struct node ***data, int rows, int cols);
//void import(char *commandStr, int commandStrIndx, struct node ***data, int rows, int cols);
//char *exportTo(char *commandStr, int commandStrIndx, struct node ***data, int rows, int cols);
//int convertToInt(char *str);
//void save(char *fileName, struct node ***data, int rows, int cols);
//int main()
//{
//	struct node ***data = create_data(10,10);
//	while (!GetAsyncKeyState(VK_CONTROL))
//		input_call(data,10,10);
//	system("pause");
//	return 0;
//}
//
//struct node *create_node()
//{
//	int i;
//	struct node *temp = (struct node *)malloc(sizeof(struct node));
//	temp->data = 0;
//	temp->exp = "";
//	temp->list = (struct node **)malloc(sizeof(struct node *) * 10);
//	for (i = 0; i < 10; i++)
//		temp->list[i] = NULL;
//	return temp;
//}
//struct node ***create_data(int rows,int cols)
//{
//
//	int i, j;
//	struct node ***data = (struct node ***)malloc(sizeof(struct node **) * rows);
//	for (i = 0; i < 10; i++)
//		data[i] = (struct node **)malloc(sizeof(struct node *) * cols);
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			data[i][j] = create_node();
//		}
//	}
//	return data;
//}
//void input_call(struct node ***data,int rows,int cols)
//{
//	printf(">");
//	char *commandStr = (char *)malloc(100);
//	fgets(commandStr, 100, stdin);
//	get_command(commandStr, data,rows,cols);
//}
//void get_command(char *commandStr, struct node ***data, int rows, int cols)
//{
//	int commandStrIndx, commandIndx = 0;
//	char *command = (char *)malloc(10);
//	char *fileName=(char *)malloc(10);
//	commandStrIndx = removespaces(commandStr, 0);
//	for (; commandStr[commandStrIndx] != ' ' && commandStr[commandStrIndx] != '\0' && commandStr[commandStrIndx] != '\n'; commandStrIndx++, commandIndx++)
//		command[commandIndx] = commandStr[commandStrIndx];
//	command[commandIndx] = '\0';
//	upper(command);
//	if (strcmp(command, "SET") == 0)
//		set(commandStr, commandStrIndx, data);
//	if (strcmp(command, "GET") == 0)
//		get(commandStr, commandStrIndx, data);
//	if (strcmp(command, "PRINT") == 0)
//		print(commandStr, commandStrIndx, data, rows, cols);
//	if (strcmp(command, "EXPORT") == 0)
//		fileName=exportTo(commandStr, commandStrIndx, data, rows, cols);
//	if (strcmp(command, "IMPORT") == 0)
//		import(commandStr, commandStrIndx, data, rows, cols);
//	if (strcmp(command, "SAVE") == 0)
//		save(fileName,data,rows,cols);
//}
//void set(char *commandStr, int commandStrIndx, struct node ***data)
//{
//	int value,expIndx,flag=0;
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
//	int row_id, col_id;
//	row_id = findRowId(rowId);
//	col_id = findColId(colId);
//	value = 0;
//	for (expIndx = 0; (exp[expIndx] >= '1' && exp[expIndx] <= '9'); expIndx++)
//	{
//		value = value * 10 + (exp[expIndx] - '0');
//	}
//	for (; exp[expIndx] == ' '; expIndx++)
//	{
//	}
//	if (exp[expIndx] == '\0')
//		flag = 1;
//	if (flag == 1)
//	{
//		data[row_id][col_id]->data = value;
//	}
//	else
//	{
//		value = parseString(exp, data[row_id][col_id], data);
//		data[row_id][col_id]->data = value;
//		data[row_id][col_id]->exp = exp;
//	}
//}
//
//int parseString(char *exp, struct node *currentCell,struct node ***data)
//{
//	int expIndx=0,firstValue,secondValue,res,row_id,col_id;
//	char opertr;
//	char *colId = (char *)malloc(10);
//	char *rowId = (char *)malloc(10);
//	char *numstr = (char *)malloc(10);
//	int k = 0,numIndx;
//	if (exp[expIndx] >= '1' && exp[expIndx] <= '9')
//	{
//		for (numIndx = 0; exp[expIndx] >= '1' && exp[expIndx] <= '9'; expIndx++,numIndx++)
//		{
//			numstr[numIndx] = exp[expIndx];
//		}
//		numstr[numIndx] = '\0';
//		firstValue = convertToInt(numstr);
//	}
//	else
//	{
//		for (; !(exp[expIndx] >= '1' && exp[expIndx] <= '9'); expIndx++, k++)
//		{
//			colId[k] = exp[expIndx];
//		}
//
//		colId[k] = '\0';
//		k = 0;
//		for (; exp[expIndx] >= '1' && exp[expIndx] <= '9'; expIndx++, k++)
//		{
//			rowId[k] = exp[expIndx];
//		}
//		rowId[k] = '\0';
//		row_id = findRowId(rowId);
//	    col_id = findColId(colId);
//		firstValue = data[row_id][col_id]->data;
//	}
//	expIndx = removespaces(exp,expIndx);
//	opertr = exp[expIndx];
//	expIndx++;
//	expIndx = removespaces(exp, expIndx);
//	if(exp[expIndx] >= '1' && exp[expIndx] <= '9')
//	{
//		for (numIndx = 0; exp[expIndx] >= '1' && exp[expIndx] <= '9'; expIndx++, numIndx++)
//		{
//			numstr[numIndx] = exp[expIndx];
//		}
//		numstr[numIndx] = '\0';
//		secondValue = convertToInt(numstr);
//	}
//	else
//	{
//		k = 0;
//		for (; !(exp[expIndx] >= '1' && exp[expIndx] <= '9'); expIndx++, k++)
//		{
//			colId[k] = exp[expIndx];
//		}
//		colId[k] = '\0';
//		k = 0;
//		for (; exp[expIndx] >= '1' && exp[expIndx] <= '9'; expIndx++, k++)
//		{
//			rowId[k] = exp[expIndx];
//		}
//		rowId[k] = '\0';
//		row_id = findRowId(rowId);
//		col_id = findColId(colId);
//		secondValue = data[row_id][col_id]->data;
//	}
//	switch (opertr)
//	{
//	case '+':res = firstValue + secondValue;
//		     break;
//	case '-':res = firstValue - secondValue;
//		     break;
//	case '*':res = firstValue * secondValue;
//		    break;
//	case '/':res = firstValue / secondValue;
//		    break;
//	default:break;
//	}
//	return res;
//}
//
//void get(char *commandStr, int commandStrIndx,struct node ***data)
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
//	printf("%d\n", data[row_id][col_id]->data);
//}
//void print(char *commandStr, int commandStrindx, struct node ***data, int rows, int cols)
//{
//	int i, j;
//	for (i = 0; i < rows; i++)
//	{
//		for (j = 0; j < cols; j++)
//		{
//			printf("%d ", data[i][j]->data);
//		}
//		printf("\n");
//	}
//
//}
//char *exportTo(char *commandStr, int commandStrIndx, struct node ***data, int rows, int cols)
//{
//	int strIndx, numStrIndx;
//	commandStrIndx = removespaces(commandStr, commandStrIndx);
//	if (commandStrIndx == -1)
//		return NULL;
//	char *filename = (char *)malloc(15);
//	char *dummyFile;
//	int fileIndx = 0, flag;
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
//	dummyFile = filename;
//	FILE *fp;
//	fp = fopen(filename, "w");
//	int rowIndx, colIndx,expIndx;
//	strIndx = 0;
//	char *str = (char *)malloc(100);
//	char *numstr = (char *)malloc(100);
//	for (rowIndx = 0; rowIndx < rows; rowIndx++)
//	{
//		strIndx = 0;
//		for (colIndx = 0; colIndx < cols; colIndx++)
//		{
//			_itoa(data[rowIndx][colIndx]->data, numstr, 10);
//			for (numStrIndx = 0; numstr[numStrIndx] != '\0'; numStrIndx++, strIndx++)
//				str[strIndx] = numstr[numStrIndx];
//			str[strIndx] = '{';
//			strIndx++;
//			for (expIndx = 0; data[rowIndx][colIndx]->exp[expIndx]!='\0'; expIndx++, strIndx++)
//				str[strIndx] = data[rowIndx][colIndx]->exp[expIndx];
//			str[strIndx] = '}';
//			strIndx++;
//			str[strIndx] = ',';
//			strIndx++;
//		}
//		str[strIndx] = '\n';
//		strIndx++;
//		str[strIndx] = '\0';
//		//printf("%s\n", str);
//		fputs(str, fp);
//	}
//	fclose(fp);
//	return dummyFile;
//}
//
//void import(char *commandStr, int commandStrIndx, struct node ***data, int rows, int cols)
//{
//	int fileIndx = 0, d = 0, row_id, col_id;
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
//			fscanf(fp, "%[^{]s", res);
//			fscanf(fp, "{");
//			data[row_id][col_id]->data = convertToInt(res);
//			fscanf(fp, "%[^}]s", res);
//			data[row_id][col_id]->exp = res;
//			fscanf(fp, "}");
//			fscanf(fp,",");
//		}
//		fscanf(fp, "\n");
//	}
//	fclose(fp);
//}
//void save(char *fileName, struct node ***data,int rows,int cols)
//{
//	//printf("%s",fileName);
//	FILE *fp = fopen(fileName,"w");
//	if (fp == NULL)
//	{
//		printf("file not found");
//		return;
//	}
//	int rowIndx, colIndx, expIndx,strIndx = 0,numStrIndx;
//	char *str = (char *)malloc(100);
//	char *numstr = (char *)malloc(100);
//	for (rowIndx = 0; rowIndx < rows; rowIndx++)
//	{
//		strIndx = 0;
//		for (colIndx = 0; colIndx < cols; colIndx++)
//		{
//			_itoa(data[rowIndx][colIndx]->data, numstr, 10);
//			for (numStrIndx = 0; numstr[numStrIndx] != '\0'; numStrIndx++, strIndx++)
//				str[strIndx] = numstr[numStrIndx];
//			str[strIndx] = '{';
//			strIndx++;
//			for (expIndx = 0; data[rowIndx][colIndx]->exp[expIndx] != '\0'; expIndx++, strIndx++)
//				str[strIndx] = data[rowIndx][colIndx]->exp[expIndx];
//			str[strIndx] = '}';
//			strIndx++;
//			str[strIndx] = ',';
//			strIndx++;
//		}
//		str[strIndx] = '\n';
//		strIndx++;
//		str[strIndx] = '\0';
//		//printf("%s\n", str);
//		fputs(str, fp);
//	}
//	
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
//void upper(char *str)
//{
//	int i;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		if (str[i] >= 97 && str[i] <= 122)
//			str[i] = str[i] - 32;
//	}
//}
//
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