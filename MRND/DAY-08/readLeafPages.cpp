//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//
//struct leafPage
//{
//	int sid[3];
//	char unused[4];
//	char name[3][5];
//	char pageType;
//
//};
//
//int main()
//{
//	struct leafPage lp[4];
//	//struct nonLeafPage nlp;
//	FILE *fp;
//	fp = fopen("leafs.tx","rb");
//	if (fp != NULL)
//	{
//		for (int i = 0; i < 4; i++){
//			fread(&lp[i], 32, 1, fp);
//			printf("%c %s\n %d %d %d\n %s %s %s\n\n", lp[i].pageType, lp[i].unused, lp[i].sid[0], lp[i].sid[1], lp[i].sid[2], lp[i].name[0], lp[i].name[1], lp[i].name[2] );
//		}
//	}
//	fclose(fp);
//	system("pause");
//	return 0;
//}