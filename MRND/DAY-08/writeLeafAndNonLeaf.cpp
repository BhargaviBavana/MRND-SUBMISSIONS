//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct leafPage
//{
//
//	int sid[3];
//	char unused[4];
//	char name[3][5];
//	char pageType;
//
//};
//
//struct nonLeafPage
//{
//	char pageType;
//	char unused[3];
//	int children[4];
//	int value[3];
//};
//
//int main()
//{
//	struct nonLeafPage nlp;
//	struct leafPage lp[4];
//	nlp.pageType = '0';
//
//	FILE *fp = fopen("leafs.tx","rb");
//	if (fp != NULL)
//	{
//		for (int i = 0; i< 4; i++)
//		{
//			fread(&lp[i],32,1,fp);
//		}
//	}
//	fclose(fp);
//
//	for (int i = 0; i < 4; i++)
//	{
//		nlp.children[i] = i;
//		if (i != 3)
//			nlp.value[i] = lp[i].sid[0];
//	}
//	fp = fopen("leafs.txt","wb");
//	if (fp != NULL){
//		fwrite(&nlp, 32, 1, fp);
//		for (int i = 0; i < 4; i++)
//		{
//			fwrite(&lp[i],32,1,fp);
//		}
//	}
//	fclose(fp);
//	return 0;
//}
//
