//Ashank Kumar program does various Linked List Functions
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void create(node *pointer, int x) 
{
	while(pointer->next != NULL)
	{
		pointer = pointer -> next;
	}

	pointer->next = (node *)malloc(sizeof(node));
	pointer = pointer->next;
	pointer->data = x;
	pointer->next = NULL;
}

node *add(node *oldHead, int x)
{
	node *newHead;

	newHead = (node *) malloc(sizeof(node));
	
	newHead->next = oldHead;
	oldHead=newHead;

	return oldHead;
}

void print(node *current)
{
	while(current != NULL)
	{
		printf("%d\n",current->data);
		current = current->next;
	}
}

void newPrint(node *head)
{
	printf("New List\n");

	while(head != NULL)
	{
		printf("%d\n",head->data);
		head = head->next;
	}
}

int delete(node *pointer, int x)
{
	while(pointer->next != NULL &&(pointer->next)->data != x)
	{
		pointer = pointer -> next;
	}

	node *temp = pointer->next;
	pointer->next = temp->next;
	free(temp);

	return 0;
}

void clear(node *pointer)
{
	while(pointer->next != NULL)
	{	
		node *temp = pointer;
		pointer = pointer->next;
		free(temp);
		pointer = pointer->next;
	}
}

void smallestLength(node *pointer1, node *pointer2)
{
	int i = 0;
	int x = 0;

	while(pointer1 != NULL)
	{
		pointer1 = pointer1->next;
		i++;
	}

	while(pointer2 != NULL)
	{
		pointer2 = pointer2->next;
		x++;
	}

	if(i > x)
	{
		printf("The second linked list is shorter\n");
	}

	else if(x > i)
	{
		printf("The first linked list is shorter\n");
	}
	else
	{
		printf("The linked lists are equal length\n");
	}

}

void smallestSum(node *pointer1, node *pointer2)
{
	int firstTotal = 0;
	int secondTotal = 0;

	while(pointer1 != NULL)
	{
		firstTotal = firstTotal + pointer1->data;
		pointer1 = pointer1->next;
	}

	while(pointer2 != NULL)
	{
		secondTotal = secondTotal + pointer2->data;
		pointer2 = pointer2->next;
	}

	if(firstTotal > secondTotal)
	{
		printf("The second list has the smaller sum:%d\n",secondTotal);
	}
	else if(secondTotal > firstTotal)
	{
		printf("The first list has the smaller sum:%d\n",firstTotal);
	}
	else
	{
		printf("The sum of both lists are equal:%d\n",firstTotal);
	}
}

int main()
{
	node *head; 
	node *head2;

	head = (node *)  malloc(sizeof(node));
	head->data = 1;
	head->next = NULL;
	
	for(int i = 2; i <= 5; i++)
	{
		create(head, i);
	}

	head2 = (node *) malloc(sizeof(node));
	head2->data = 1;
	head2->next = NULL;

	for(int i = 2; i<= 6; i++)
	{
		create(head2, i);
	}

	print(head);
	delete(head, 3); 
	printf("New Linked List\n");
	print(head);
	head = add(head, 0);
	printf("New Linked List\n");
	print(head);
	clear(head);
	head->next = NULL;
	printf("New Linked List\n");
	print(head);
	printf("Second Linked List\n");
	print(head2);
	smallestLength(head, head2);
	smallestSum(head, head2);


	return 0;
}
