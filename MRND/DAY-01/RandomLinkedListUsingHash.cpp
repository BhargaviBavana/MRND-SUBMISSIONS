#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iterator>
#include<map>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *random;
};
struct node *create_node(int v);
struct node *cloningUsingHash(struct node *);
int main()
{
	int n, i, v;
	scanf("%d", &n);
	struct node *temp, *t, *newHead, *head = NULL;
	struct node **list = (struct node **)malloc(sizeof(struct node *)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v);
		temp = create_node(v);
		list[i] = temp;
		if (head == NULL)
			head = temp;
		else
		{
			t = head;
			while (t->next != NULL)
				t = t->next;
			t->next = temp;
		}
	}
	//random
	list[1]->random = list[2];
	list[2]->random = list[4];
	list[4]->random = list[0];

	newHead = cloningUsingHash(head);
	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	temp = head;
	while (temp != NULL)
	{
		if (temp->random != NULL)
			printf("%d ", temp->random->data);
		else
			printf("0 ");
		temp = temp->next;
	}
	printf("\n");
	printf("\n");
	temp = newHead;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	temp = newHead;
	while (temp != NULL)
	{
		if (temp->random != NULL)
			printf("%d ", temp->random->data);
		else
			printf("0 ");
		temp = temp->next;
	}
	printf("\n");
	system("pause");
	return 0;
}

struct node *create_node(int v)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = v;
	temp->next = NULL;
	temp->random = NULL;
	return temp;
}
struct node *cloningUsingHash(struct node *head)
{
	struct node *newHead = NULL,*tempNew,*temp,*prev=NULL,*r,*t1,*t2;
	map<struct node *, struct node *> hash;
	temp = head;
	while (temp != NULL)
	{
		tempNew = create_node(temp->data);
		hash[temp] = tempNew;
		if (newHead == NULL)
		{
			newHead = tempNew;
			prev = newHead;
		}
		else
		{
			prev->next = tempNew;
			prev = prev->next;
		}
		temp = temp->next;
	}
	temp = head;
	while (temp != NULL)
	{
		tempNew = hash[temp];
		r = hash[temp->random];
		tempNew->random = r;
		temp = temp->next;
	}
	
	return newHead;
}