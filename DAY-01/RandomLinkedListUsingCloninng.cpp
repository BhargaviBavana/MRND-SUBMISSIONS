#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *random;
};
struct node *create_node(int v);
struct node *cloning(struct node *);
int main()
{
	int n, i, v;
	scanf("%d", &n);
	struct node *temp, *t, *newHead,*head=NULL;
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
	list[1]->random = list[3];
	list[2]->random = list[4];
	list[4]->random = list[0];
	newHead = cloning(head);
	temp = head;
	while (temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	temp = head;
	while (temp != NULL)
	{
		if (temp->random != NULL)
			printf("%d ", temp->random->data);
		else
			printf("0 ");
		temp = temp->next;
	}
	temp = newHead;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	temp = newHead;
	while (temp != NULL)
	{
		if (temp->random != NULL)
			printf("%d ", temp->random->data);
		else
			printf("0 ");
		temp = temp->next;
	}
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

struct node *cloning(struct node *head)
{
	struct node *temp = head, *tempNew, *store, *newHead = NULL, *tempN, *t1, *t2;
	while (temp != NULL)
	{
		tempNew = create_node(temp->data);
		if (newHead == NULL)
			newHead = tempNew;
		store = temp->next;
		temp->next = tempNew;
		tempNew->next = store;
		temp = store;
	}
	temp = head;
	while (temp != NULL)
	{
		if (temp->random != NULL)
			temp->next->random = temp->random->next;
		temp = temp->next->next;
	}

	temp = head;
	tempN = newHead;
	while (tempN->next != NULL)
	{
		t1 = temp->next->next;
		temp->next = t1;
		t2 = tempN->next->next;

		tempN->next = t2;
		temp = t1;
		tempN = t2;
	}
	temp->next = NULL;

	return newHead;
}