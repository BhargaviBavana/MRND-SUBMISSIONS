#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void compression(char *str);
int main()
{
	char *str = (char *)malloc(1000);
	scanf("%s",str);
	compression(str);
	printf("%s",str);
	system("pause");
	return 0;
}
void compression(char *str)
{
	int strIndx, cmprStrIndx = 0,count,revCount;
	for (strIndx = 0; str[strIndx] != '\0'; strIndx++)
	{
		count = 1;
		while (str[strIndx + 1] != '\0' && (str[strIndx] == str[strIndx + 1]))
		{
			strIndx++;
			count++;
		}
		if (count > 1)
		{
			str[cmprStrIndx] = str[strIndx];
			cmprStrIndx++;
			revCount = 0;
			while (count != 0)
			{
				revCount = revCount * 10 + count % 10;
				count = count / 10;
			}
			while (revCount != 0)
			{
				str[cmprStrIndx] = (revCount % 10) + '0';
				revCount = revCount / 10;
				cmprStrIndx++;
			}
		}
		else
		{
			str[cmprStrIndx] = str[strIndx];
			cmprStrIndx++;
		}
	}
	str[cmprStrIndx] = '\0';
}