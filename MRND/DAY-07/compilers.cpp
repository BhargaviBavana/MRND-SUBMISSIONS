#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SYMBOLTABLESIZE 100
#define BLOCKTABLESIZE 100
#define INTERMEDIATELANGUAGETABLESIZE 100

void readFile(char fileName[10]);
void parseString(char str[20]);
int getToken(char str[20], char *token);
void insertIntoSymbolTable(char c, int addr, int size);
int getAddr(char variable[5]);
int getOpcodeOfRegr(char regr[10]);
int getOpcodeOfToken(char token[10]);
void insertIntoIntermediateLanguageTable(int ln, int t, int p1, int p2, int p3, int p4);
void insertIntoBlockTable(char block[10], int Lno);
int getBlockNumber(char block[10]);
int popFromStack();
void pushToStack(int ln);

int addr = 0;
int lNo = 1;
int stack[100];
int stackPointer = -1;

int s_indx = 0;
int b_indx = 0;
int i_indx = 0;

struct symbol
{
	char variable;
	int addr;
	int size;
};

struct block
{
	char blockName[10];
	int blockLineNumber;
};

struct intermediateLanguage
{
	int lNo;
	int opcode;
	int parameters[4];
};

struct opcode
{
	char instruction[10];
	int op_code;
};

struct registerCode
{
	char rgstr[10];
	int op_code;
};

struct opcode opcodeList[14];
struct registerCode registerCodelist[8];


struct symbol symbolTable[SYMBOLTABLESIZE];
struct block blockTable[BLOCKTABLESIZE];
struct intermediateLanguage intermediateLanguageTable[INTERMEDIATELANGUAGETABLESIZE];

int main()
{
	FILE *fp;

	strcpy(opcodeList[0].instruction,"MOV");
	opcodeList[0].op_code = 1;

	strcpy(opcodeList[1].instruction, "MOV");
	opcodeList[1].op_code = 2;

	strcpy(opcodeList[2].instruction, "ADD");
	opcodeList[2].op_code = 3;

	strcpy(opcodeList[3].instruction, "SUB");
	opcodeList[3].op_code = 4;

	strcpy(opcodeList[4].instruction, "MUL");
	opcodeList[4].op_code = 5;

	strcpy(opcodeList[5].instruction, "JMP");
	opcodeList[5].op_code = 6;

	strcpy(opcodeList[6].instruction, "IF");
	opcodeList[6].op_code = 7;

	strcpy(opcodeList[7].instruction, "EQ");
	opcodeList[7].op_code = 8;

	strcpy(opcodeList[8].instruction, "LT");
	opcodeList[8].op_code = 9;

	strcpy(opcodeList[9].instruction, "GT");
	opcodeList[9].op_code = 10;

	strcpy(opcodeList[10].instruction, "LTEQ");
	opcodeList[10].op_code = 11;

	strcpy(opcodeList[11].instruction, "GTEQ");
	opcodeList[11].op_code = 12;

	strcpy(opcodeList[12].instruction, "PRINT");
	opcodeList[12].op_code = 13;

	strcpy(opcodeList[13].instruction, "READ");
	opcodeList[13].op_code = 14;

	strcpy(registerCodelist[0].rgstr,"AX");
	registerCodelist[0].op_code = 0;

	strcpy(registerCodelist[1].rgstr, "BX");
	registerCodelist[1].op_code = 1;

	strcpy(registerCodelist[2].rgstr, "CX");
	registerCodelist[2].op_code = 2;

	strcpy(registerCodelist[3].rgstr, "DX");
	registerCodelist[3].op_code = 3;

	strcpy(registerCodelist[4].rgstr, "EX");
	registerCodelist[4].op_code = 4; 

	strcpy(registerCodelist[5].rgstr, "FX");
	registerCodelist[5].op_code = 5;

	strcpy(registerCodelist[6].rgstr, "GX");
	registerCodelist[6].op_code = 6;

	strcpy(registerCodelist[7].rgstr, "HX");
	registerCodelist[7].op_code = 7;

	char fileName[10];
	scanf("%s",fileName);

	readFile(fileName);
	//parseString("	JUMP X");
	char s[200];
	fp = fopen("compileroutput.txt","w");
	if (fp != NULL)
	{
		for (int i = 0; i < i_indx; i++)
		{
			fprintf(fp, "%d %d %d %d %d %d\n", intermediateLanguageTable[i].lNo, intermediateLanguageTable[i].opcode, intermediateLanguageTable[i].parameters[0], intermediateLanguageTable[i].parameters[1], intermediateLanguageTable[i].parameters[2], intermediateLanguageTable[i].parameters[3]);
		}
	}
	fclose(fp);
	for (int i = 0; i < s_indx; i++)
		printf("%c %d %d\n",symbolTable[i].variable,symbolTable[i].addr,symbolTable[i].size);
	
	printf("\n");

	for (int i = 0; i < b_indx; i++)
		printf("%s %d\n",blockTable[i].blockName,blockTable[i].blockLineNumber);

	printf("\n");

	for (int i = 0; i < i_indx; i++)
		printf("%d %d %d %d %d %d\n", intermediateLanguageTable[i].lNo, intermediateLanguageTable[i].opcode, intermediateLanguageTable[i].parameters[0], intermediateLanguageTable[i].parameters[1], intermediateLanguageTable[i].parameters[2], intermediateLanguageTable[i].parameters[3]);

	system("pause");
	return 0;
}

void readFile(char fileName[10])
{
	char str[100];
	FILE *fp;
	fp = fopen(fileName,"r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fgets(str,100,fp);
			//printf("%s\n",str);
			parseString(str);

		}
	}
	fclose(fp);
}

void parseString(char str[100])
{
	int size,indx,value,flag=0,l,l1,i;
	char variable, regr[3], arg1[10], arg2[10], arg3[10], opr[10];
	char *token=(char *)malloc(10);
	indx=getToken(str,token);
	
	if (strcmp(token,"DATA") == 0)
	{
		size = 0;
		for (; str[indx] == ' '; indx++){}
		variable = str[indx];
		indx++;
		if (str[indx] == '\n' || str[indx] == '\0')
			size = 1;
		else
		{
			for (; str[indx] == ' '; indx++){}
			indx++;
			for (; str[indx] == ' '; indx++){}
			size = str[indx] - '0';
		}
		insertIntoSymbolTable(variable, addr, size);
		addr = addr + size;
	}

	else if (strcmp(token, "CONST") == 0)
	{
		for (; str[indx] == ' '; indx++){}
		variable = str[indx];
		indx++;
		for (; str[indx] == ' '; indx++){}
		indx++;
		for (; str[indx] == ' '; indx++){}
		value = str[indx] - '0';
		insertIntoSymbolTable(variable,addr,0);
		addr = addr + 1;
	}
	else if (strcmp(token,"START:")==0)
	{
	}

	else if (strcmp(token, "READ") == 0)
	{
		for (; str[indx] == ' '; indx++){}
		regr[0] = str[indx];
		indx++;
		regr[1] = str[indx];
		regr[2] = '\0';
		insertIntoIntermediateLanguageTable(lNo,getOpcodeOfToken(token),getOpcodeOfRegr(regr),-1,-1,-1);
		lNo = lNo + 1;
	}
	else if (strcmp(token, "MOV") == 0)
	{
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != ' ' && str[indx] != ','; indx++, i++)
			arg1[i] = str[indx];
		arg1[i] = '\0';
		if (str[indx] == ' ')
		{
			for (; str[indx] == ' '; indx++){}
			indx++;
		}
		else
			indx++;
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != '\n' && str[indx] != '\0'; indx++, i++)
			arg2[i] = str[indx];
		arg2[i] = '\0';
		if (strcmp(arg1, "AX") == 0 || strcmp(arg1, "BX") == 0 || strcmp(arg1, "CX") == 0 || strcmp(arg1, "DX") == 0 || strcmp(arg1, "EX") == 0 || strcmp(arg1, "FX") == 0 || strcmp(arg1, "GX") == 0)
			insertIntoIntermediateLanguageTable(lNo, 2, getOpcodeOfRegr(arg1),getAddr(arg2), -1, -1);
		else
			insertIntoIntermediateLanguageTable(lNo, 1, getAddr(arg1), getOpcodeOfRegr(arg2), -1, -1);
		lNo = lNo + 1;
	}
	else if (strcmp(token, "ADD") == 0)
	{
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != ','; indx++, i++)
			arg1[i] = str[indx];
		arg1[i] = '\0';
		indx++;
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != ','; indx++, i++)
			arg2[i] = str[indx];
		arg2[i] = '\0';
		indx++;
		for (; str[indx] == ' '; indx++){}
		for(i = 0; str[indx] != '\0' && str[indx]!='\n'; indx++, i++)
			arg3[i] = str[indx];
		arg3[i] = '\0';
		insertIntoIntermediateLanguageTable(lNo, getOpcodeOfToken(token), getOpcodeOfRegr(arg1), getOpcodeOfRegr(arg2), getOpcodeOfRegr(arg3),-1 );
		lNo++;
	}
	else if (strcmp(token,"IF")==0)
	{
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != ' ' ; indx++, i++)
			arg1[i] = str[indx];
		arg1[i] = '\0';
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != ' ' ; indx++, i++)
			opr[i] = str[indx];
		opr[i] = '\0';
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != '\n' && str[indx]!=' '; indx++, i++)
			arg2[i] = str[indx];
		arg2[i] = '\0';
		insertIntoIntermediateLanguageTable(lNo,getOpcodeOfToken(token),getOpcodeOfRegr(arg1),getOpcodeOfRegr(arg2),getOpcodeOfToken(opr),-99);
		pushToStack(lNo);
		lNo++;
	}
	else if (strcmp(token, "ELSE") == 0)
	{
		insertIntoIntermediateLanguageTable(lNo,getOpcodeOfToken("JMP"),-99,-1,-1,-1);
		pushToStack(lNo);
		insertIntoBlockTable(token,lNo+1);
		lNo++;
	}
	else if (strcmp(token,"PRINT")==0)
	{
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != '\0' && str[indx] != '\n'; indx++, i++)
			arg1[i] = str[indx];
		arg1[i] = '\0';
		insertIntoIntermediateLanguageTable(lNo,getOpcodeOfToken(token),getAddr(arg1),-1,-1,-1);
		lNo++;
	}
	else if (strcmp(token, "JUMP") == 0)
	{
		for (; str[indx] == ' '; indx++){}
		for (i = 0; str[indx] != '\0' && str[indx] != '\n'; indx++, i++)
			arg1[i] = str[indx];
		arg1[i] = '\0';
		insertIntoIntermediateLanguageTable(lNo,getOpcodeOfToken("JMP"),getBlockNumber(arg1),-1,-1,-1);
		lNo++;
	}
	else if (strcmp(token,"ENDIF")==0)
	{
		l = popFromStack();
		intermediateLanguageTable[l-1].parameters[0] = lNo;
		l1 = popFromStack();
		intermediateLanguageTable[l1-1].parameters[3] = l;
		insertIntoBlockTable(token, lNo);
		lNo++;
	}
	else if (strcmp(token, "END") == 0)
	{

	}
	else if (strcmp(token,"X:")==0)
	{
		str[indx-1] = '\0';
		insertIntoBlockTable(str,lNo);
	}
	
}

int popFromStack()
{
	int res = stack[stackPointer];
	stackPointer--;
	return res;
}
int getBlockNumber(char block[10])
{
	int i;
	for (i = 0;i<b_indx; i++)
	{
		if (strcmp(blockTable[i].blockName, block) == 0)
			break;
	}
	return blockTable[i].blockLineNumber;
}

void pushToStack(int ln)
{
	stackPointer++;
	stack[stackPointer] = ln;
}
void insertIntoBlockTable(char block[10],int Lno)
{
	strcpy(blockTable[b_indx].blockName, block);
	blockTable[b_indx].blockLineNumber = Lno;
	b_indx++;
}
int getAddr(char variable[5])
{
	int res=0,i;
	for (i = 0; i < s_indx; i++)
	{
		if (symbolTable[i].variable == variable[0])
			break;
	}
	res = symbolTable[i].addr;
	if (variable[1] == '[')
	{
		res = res + (variable[2] - '0');
	}
	return res;
}

void insertIntoIntermediateLanguageTable(int ln,int t,int p1,int p2,int p3,int p4)
{
	intermediateLanguageTable[i_indx].lNo = ln;
	intermediateLanguageTable[i_indx].opcode = t;
	intermediateLanguageTable[i_indx].parameters[0] = p1;
	intermediateLanguageTable[i_indx].parameters[1] = p2;
	intermediateLanguageTable[i_indx].parameters[2] = p3;
	intermediateLanguageTable[i_indx].parameters[3] = p4;
	i_indx++;
}


int getOpcodeOfToken(char token[10])
{
	int res;
	for (int i = 0; i < 14; i++)
	{
		if (strcmp(opcodeList[i].instruction, token) == 0)
		{
			res = opcodeList[i].op_code;
			break;
		}
	}
	return res;
}

int getOpcodeOfRegr(char regr[10])
{
	int res;
	for (int i = 0; i < 8; i++)
	{
		if (strcmp(registerCodelist[i].rgstr, regr) == 0)
		{
			res = registerCodelist[i].op_code;
			break;
		}
	}
	return res;
}


int getToken(char str[100],char *token)
{
	int indx = 0,i;
	if (str[indx] == '\t')
		indx++;
	for (; str[indx] == ' '; indx++){}
	for (i = 0; str[indx] != ' ' && str[indx] != '\n' && str[indx]!='\0'; indx++, i++)
		token[i] = str[indx];
	token[i] = '\0';
	return indx;
}

void insertIntoSymbolTable(char c,int addr,int size)
{
	symbolTable[s_indx].variable = c;
	symbolTable[s_indx].addr = addr;
	symbolTable[s_indx].size = size;
	s_indx++;
}
