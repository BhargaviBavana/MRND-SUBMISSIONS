#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;
};
struct node *addition(struct node *head1,struct node *head2);
struct node *create_node(int data);
struct node *add(struct node *head1,struct node *head2,int *carry);
int main()
{
	int n1, n2,i;
	char *str1 = (char *)malloc(100);
	char *str2 = (char *)malloc(100);
	scanf("%d%d",&n1,&n2);
	struct node *head1=NULL, *head2=NULL,*newNode,*prev=NULL,*res,*temp;
	i = 0;
	while (n1 != 0)
	{
		str1[i]= n1 % 10 +'0';
		n1 = n1 / 10;
		i++;
	}
	str1[i] = '\0';
	i = 0;
	while (n2 != 0)
	{
		str2[i] = n2 % 10 +'0';
		n2 = n2 / 10;
		i++;
	}
	str2[i] = '\0';
	i = strlen(str1)-1;
	while (i>=0)
	{
		newNode = create_node(str1[i]-'0');
		if (head1 == NULL)
		{
			head1 = newNode;
			prev = newNode;
		}
		else
		{
			prev->next = newNode;
			prev = prev->next;
		}
		i--;
	}
	i = strlen(str2) - 1;
	while (i >= 0)
	{
		newNode = create_node(str2[i] - '0');
		if (head2 == NULL)
		{
			head2 = newNode;
			prev = newNode;
		}
		else
		{
			prev->next = newNode;
			prev = prev->next;
		}
		i--;
	}
	res = addition(head1, head2);
	temp = res;
	while (temp != NULL)
	{
		printf("%d",temp->data);
		temp = temp->next;
	}
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


struct node *addition(struct node *head1, struct node *head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	struct node *temp,*store=NULL,*start=NULL,*prev=NULL,*res,*newNode;
	int c1 = 1, c2 = 1,diff=0,c,carry=0;
	temp = head1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		c1++;
	}
	temp = head2;
	while (temp->next != NULL)
	{
		temp = temp->next;
		c2++;
	}
	if (c1 > c2)
	{
		diff = c1 - c2;
		store = head2;
		head2 = NULL;
	}
	if (c2>c1)
	{
		diff = c2 - c1;
		store = head1;
		head1 = NULL;
	}
	
	if (diff != 0){
		c = 0;
		while (c < diff)
		{
			temp = create_node(0);
			if (start == NULL)
			{
				start = temp;
				prev = start;
			}
			else
			{
				prev->next = temp;
				prev = prev->next;
			}
			c++;
		}
	}
	if (head1 == NULL)
	{
		prev->next = store;
		head1 = start;
	}
	if (head2==NULL)
	{
		prev->next = store;
		head2 = start;
	}
	res= add(head1,head2,&carry);
	if (carry != 0){
		newNode = create_node(carry);
		store = res;
		res = newNode;
		newNode->next = store;
	}
	return res;
}
struct node *add(struct node *head1, struct node *head2, int *carry)
{
	int s,sum;
	struct node *res,*newNode;
	if (head1->next == NULL && head2->next == NULL)
	{
		s = head1->data + head2->data;
		sum = s % 10;
		*carry = s / 10;
		return create_node(sum);
	}
	res = add(head1->next, head2->next, carry);
	s = head1->data + head2->data +*carry;
	sum = s % 10;
	*carry = s / 10;
   newNode= create_node(sum);
   newNode->next = res;
   return newNode;
}