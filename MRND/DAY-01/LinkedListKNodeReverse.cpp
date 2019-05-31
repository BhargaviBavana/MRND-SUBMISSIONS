#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *create_node(int data);
struct node *LikedListKNodeReverse(struct node *head,int k);
struct node *reverseK(struct node *start,int k);
int main()
{
	int noOfELm,i,data,k;
	struct node *header=NULL;
	struct node *temp, *newNode,*res;
	scanf("%d",&noOfELm);
	for (i = 0; i < noOfELm; i++)
	{
		scanf("%d",&data);
		newNode= create_node(data);
		if (header == NULL)
			header = newNode;
		else
		{
			temp=header;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	scanf("%d",&k);
	res = LikedListKNodeReverse(header,k);
	temp = res;
	while (temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	system("pause");
	return 0;
}

struct node *create_node(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp ->data = data;
	temp->next = NULL;
	return temp;
}

struct node *LikedListKNodeReverse(struct node *head, int k)
{
	struct node *prev=NULL,*temp=head,*res;
	while((temp!=NULL) && (res = reverseK(temp, k)))
	{
		if (prev == NULL)
		{
			head = res;
			prev = temp;
		}
		else
		{
			prev->next = res;
			prev = temp;
		}
		temp = temp->next;
	}
	return head;
}

struct node *reverseK(struct node *head, int k)
{
	struct node *temp = head,*store,*prev,*curr,*start=head;
	int i=1;
	while (i < k)
	{
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		i++;
	}
	store = temp->next;
	prev = head;
	head = head->next;
	curr = head;
	while (head->next != store)
	{
		head = head->next;
		curr->next = prev;
		prev = curr;
		curr = head;
	}
	head->next = prev;
	start->next = store;
	return head;
}