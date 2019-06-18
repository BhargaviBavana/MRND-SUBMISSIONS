#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table
{
	char filename[25];
	unsigned int starting;
	unsigned int length;
};

void write(FILE *disc, FILE *fp)
{
	char s;
	while (fread(&s, sizeof(char), 1, fp) > 0)
	{
		fwrite(&s, sizeof(char), 1, disc);
	}
	//fwrite()
}

void copyToDisc(char *cmd, FILE *disc, struct table *metaData, unsigned int *tableEnd, unsigned int *dataEnd)
{
	FILE *fp;
	int i = 0, ind = 0;
	char filename[25];
	while (cmd[i] == ' ')
	{
		i++;
	}
	while (cmd[i] != '\0')
	{
		filename[ind++] = cmd[i++];
	}
	filename[ind] = '\0';
	fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("%d", errno);
	}
	strcpy(metaData->filename, filename);
	metaData->starting = *dataEnd;
	unsigned int val = *dataEnd;
	fseek(disc, val, SEEK_SET);
	write(disc, fp);
	*dataEnd = ftell(disc);
	metaData->length = *dataEnd - metaData->starting;
	fseek(disc, *tableEnd, SEEK_SET);
	if (fwrite(metaData, sizeof(struct table), 1, disc) < 0)
	{
		printf("error occured");
	}
	char newLine = '\n';
	fwrite(&newLine, sizeof(char), 1, disc);
	*tableEnd = ftell(disc);
	fclose(fp);

}

void init(FILE *disc, unsigned int *tableEnd, unsigned int *dataEnd)
{
	struct table *read = (struct table *)malloc(sizeof(struct table));
	fseek(disc, *tableEnd, SEEK_SET);
	//char ch;
	while (fread(read, sizeof(struct table), 1, disc) > 0)
	{
		//
	}
	*tableEnd = ftell(disc);
	fseek(disc, *dataEnd, SEEK_SET);
	//while (fread(&ch, sizeof(char), 1, disc) > 0);
	*dataEnd = ftell(disc);
}

void list(FILE *disc, struct table *metaData, unsigned int *tableEnd, unsigned int *dataEnd)
{
	struct table *read = (struct table *)malloc(sizeof(struct table));
	fseek(disc, 0, SEEK_SET);
	char ch;
	while (ftell(disc)<*tableEnd)
	{
		fread(read, sizeof(struct table), 1, disc);
		fread(&ch, sizeof(char), 1, disc);
		printf("%s\n", read->filename);
	}
}

void copyFromList(char *cmd, FILE *disc, struct table *metaData, unsigned int *tableEnd, unsigned int *dataEnd)
{
	FILE *newFile;
	struct table *read = (struct table *)malloc(sizeof(struct table));
	char ch;
	char discFileName[25], newFileName[25];
	int i = 0, ind = 0, found = 0;
	unsigned int count = 0;
	while (cmd[i]==' ')
	{
		i++;
	}
	while (cmd[i] != ' ')
	{
		discFileName[ind++] = cmd[i++];
	}
	discFileName[ind] = '\0';
	while (cmd[i] == ' ')
	{
		i++;
	}
	ind = 0;
	while (cmd[i] != '\0')
	{
		newFileName[ind++] = cmd[i++];
	}
	newFileName[ind] = '\0';
	newFile = fopen(newFileName, "wb");
	if (newFile == NULL)
	{
		printf("error occurred\n");
	}
	fseek(disc, 0, SEEK_SET);
	while (ftell(disc)<*tableEnd)
	{
		fread(read, sizeof(struct table), 1, disc);
		fread(&ch, sizeof(char), 1, disc);
		if (strcmp(discFileName, read->filename) == 0)
		{
			fseek(disc, read->starting, SEEK_SET);
			found = 1;
			break;
		}
	}
	if (found == 0)
	{
		printf("file not found\n");
		return;
	}
	while (count < read->length)
	{
		fread(&ch, sizeof(char), 1, disc);
		fwrite(&ch, sizeof(char), 1, newFile);
		count++;
	}
	fclose(newFile);
}

void main()
{
	FILE *disc = fopen("hardDisk.hdd", "rb+");
	if (disc == NULL)
	{
		printf("no file found");
	}
	struct table *metaData = (struct table *)malloc(sizeof(struct table));
	//fprintf(disc, "%s\t%s\t%s\n", "filename", "starting", "length");
	unsigned int tableEnd = 0;
	unsigned int dataEnd = 100000;//100054 * 24;
	while (1)
	{
		fflush(stdin);
		char *s = (char *)malloc(sizeof(char) * 1000);
		char *cmd = (char *)malloc(sizeof(char) * 10);
		int ind = 0;
		printf("> ");
		scanf("%[^\n]s", s);
		while (*s == ' ')
		{
			s++;
		}
		while (*s != ' ' && *s != '\0')
		{
			cmd[ind++] = *s;
			s++;
		}
		cmd[ind] = '\0';
		if (strcmp(cmd, "EXIT") == 0 || strcmp(cmd, "exit") == 0)
		{
			break;
		}
		if (strcmp(cmd, "INIT") == 0 || strcmp(cmd, "init") == 0)
		{
			init(disc, &tableEnd, &dataEnd);
		}
		if (strcmp(cmd, "FORMAT") == 0 || strcmp(cmd, "format") == 0)
		{
			tableEnd = 0;
			dataEnd = 100000;//100054 * 24;
		}
		else if (strcmp(cmd, "LIST") == 0 || strcmp(cmd, "list") == 0)
		{
			list(disc, metaData, &tableEnd, &dataEnd);
		}
		else if (strcmp(cmd, "copyToDisc") == 0)
		{
			copyToDisc(s, disc, metaData, &tableEnd, &dataEnd);
		}
		else if (strcmp(cmd, "copyFromDisc") == 0 )
		{
			copyFromList(s, disc, metaData, &tableEnd, &dataEnd);
		}
		else
		{
			printf("invalid command\n");
		}
	}
	fclose(disc);
	system("pause");
}