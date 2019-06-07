#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct leafPage
{
	int sid[3];
	char unused[4];
	char name[3][5];
	char pageType;

};

struct nonLeafPage
{
	char pageType;
	char unused[3];
	int children[4];
	int value[3];
};

int main()
{
	FILE *fp;
	struct nonLeafPage nlp;
	struct leafPage lp[4];
	fp = fopen("leafs.txt","rb");
	if (fp != NULL)
	{
		fread(&nlp,32,1,fp);
		for (int i = 0; i < 4; i++)
		{
			fread(&lp[i],32,1,fp);
		}
	}
	fclose(fp);
	printf("%c %s %d %d %d %d %d %d %d\n", nlp.pageType, nlp.unused, nlp.children[0], nlp.children[1], nlp.children[2], nlp.children[3], nlp.children[4], nlp.value[0], nlp.value[1], nlp.value[2]);
	for (int i = 0; i < 4; i++)
	{
		printf("%d %d %d\n%s\n%s %s %s\n%c\n", lp[i].sid[0], lp[i].sid[1], lp[i].sid[2], lp[i].unused, lp[i].name[0], lp[i].name[1], lp[i].name[2],lp[i].pageType);
	}
	system("pause");
	return 0;
}