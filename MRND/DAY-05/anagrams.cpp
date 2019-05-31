# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct trie *create_trie(char c);
void placeStrInTrie(char *str, struct trie *head);
void placeSortedStrInTrie(char *str, char *angrm, struct trie *head);
char *sortStr(char *str);
struct node *create_node(char *str);
struct node
{
	char *str;
	struct node *next;
};
struct trie
{
	char alph;
	struct trie **childs;
	struct node *anagrams;
};
int main()
{
	char *fileName = (char *)malloc(10);
	char *word = (char *)malloc(100);
	scanf("%s",fileName);
	char *str = (char *)malloc(100);
	FILE *fp = fopen(fileName, "r");
	struct trie *head,*temp;
	head = create_trie('-');
	while (1)
	{
		fscanf(fp,"%[^\n]s",str);
		placeStrInTrie(str,head);
		if (feof(fp))
			break;
		fscanf(fp,"\n");
	}
	scanf("%s",word);
	word = sortStr(word);
	temp = head;
	for (int indx = 0; word[indx] != '\0'; indx++)
	{
		if (word[indx] >= 'a' && word[indx] <= 'z')
		{
			temp = temp->childs[word[indx] - 'a'];
		}
		else
		{
			temp = temp->childs[26 + word[indx] - 'A'];
		}
	}
	struct node *tempNode=temp->anagrams;
	while (tempNode != NULL)
	{
		printf("%s\n",tempNode->str);
		tempNode = tempNode->next;
	}
	system("pause");
	return 0;
}

struct trie *create_trie(char c)
{
	struct trie *temp = (struct trie *)malloc(sizeof(struct trie));
	temp->alph = c;
	temp->childs = (struct trie **)calloc(sizeof(struct trie *),52);
	temp->anagrams =NULL;
	return temp;
}

void placeStrInTrie(char *str,struct trie *head)
{
	char *sortedStr=sortStr(str);
	placeSortedStrInTrie(sortedStr,str,head);
}
void placeSortedStrInTrie(char *str,char *angrm,struct trie *head)
{
	struct trie *temp=head;
	int strIndx,angrmsIndx;
	for (strIndx = 0; str[strIndx]!= '\0'; strIndx++)
	{
		if (str[strIndx] >= 'a' && str[strIndx] <= 'z')
		{
			temp->childs[str[strIndx] - 'a'] = create_trie(str[strIndx]);
			temp = temp->childs[str[strIndx] - 'a'];
		}
		else
		{
			temp->childs[26+str[strIndx] - 'A'] = create_trie(str[strIndx]);
			temp = temp->childs[26 +str[strIndx] - 'A'];
		}
	}
	if (temp->anagrams == NULL)
	{
		temp->anagrams = create_node(angrm);
	}
	else
	{
		struct node *tempNode=temp->anagrams;
		while (tempNode->next!= NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = create_node(angrm);
	}
}
struct node *create_node(char *str)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->str = str;
	temp->next = NULL;
	return temp;
}
char *sortStr(char *str)
{
	int *alphbts = (int *)calloc(sizeof(int),52);
	char *sortedStr = (char *)malloc(strlen(str));
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			alphbts[str[i] - 'a']++;
		else
			alphbts[26 + str[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (alphbts[i] >=1){
			for (int j = 0; j < alphbts[i]; j++)
			{
				sortedStr[k] = 'a' + i;
				k++;
			}
		}
		if (alphbts[26+i]>=1)
		{
			for (int j = 0; j < alphbts[26+i]; j++)
			{
				str[k] = 'A' + i;
				k++;
			}
		}
	}
	str[k] = '\0';
	return str;
}