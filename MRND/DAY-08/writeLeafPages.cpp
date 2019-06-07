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
//int main()
//{
//	struct leafPage lp[4];
//	strcpy(lp[0].name[0],"Aman");
//	strcpy(lp[0].name[1], "Anu");
//	strcpy(lp[0].name[2], "Bala");
//	lp[0].sid[0] = 10,
//	lp[0].sid[1] = 20;
//	lp[0].sid[2] = 30;
//	strcpy(lp[0].unused, "unus");
//	lp[0].pageType = '1';
//
//
//	strcpy(lp[1].name[0], "bapu");
//	strcpy(lp[1].name[1], "Don");
//	strcpy(lp[1].name[2], "Eega");
//	lp[1].sid[0] = 40,
//	lp[1].sid[1] = 50;
//	lp[1].sid[2] = 60;
//	strcpy(lp[1].unused, "unus");
//	lp[1].pageType = '1';
//
//
//	
//	strcpy(lp[2].name[0], "Fana");
//	strcpy(lp[2].name[1], "Guna");
//	strcpy(lp[2].name[2], "Hema");
//	lp[2].sid[0] = 70,
//	lp[2].sid[1] = 80;
//	lp[2].sid[2] = 90;
//	strcpy(lp[2].unused, "unus");
//	lp[2].pageType = '1';
//
//
//	strcpy(lp[3].name[0], "Isac");
//	strcpy(lp[3].name[1], "Sai");
//	strcpy(lp[3].name[2], "Sana");
//	lp[3].sid[0] = 100,
//    lp[3].sid[1] = 110;
//	lp[3].sid[2] = 120;
//	strcpy(lp[3].unused, "unus");
//	lp[3].pageType = '1';
//	FILE *fp = fopen("leafs.tx","wb");
//	if (fp != NULL)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			fwrite(&lp[i],32,1,fp);
//		}
//	}
//	fclose(fp);
//	return 0;
//}