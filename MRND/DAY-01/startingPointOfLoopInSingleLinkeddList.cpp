#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *create_node(int data);
struct node *findStartPoint(struct node *head);
int main()
{
	int noOfElm, i, data;
	struct node *header = NULL;
	struct node *temp, *newNode,*startPoint;
	scanf("%d", &noOfElm);
	struct node **list = (struct node **)malloc(sizeof(struct node *)*noOfElm);

	for (i = 0; i < noOfElm; i++)
	{
		scanf("%d", &data);
		newNode = create_node(data);
		list[i] = newNode;
		if (header == NULL)
			header = newNode;
		else
		{
			temp = header;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newNode;
		}
	}
	//loop creation
	list[noOfElm - 1]->next = list[2];

	startPoint = findStartPoint(header);
	printf("%d",startPoint->data);
	system("pause");
	return 0;
}
struct node *create_node(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
struct node *findStartPoint(struct node *head)
{
	struct node *slow = head, *fast = head,*temp;
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return 0;
	while (slow->next && fast->next && fast->next->next )
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			break;
	}
	if (fast != slow)
		return NULL;
	temp = head;
	while (temp != slow)
	{
		temp = temp->next;
		slow = slow->next;
	}
	return temp;
}