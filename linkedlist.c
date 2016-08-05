/* Drew French */

/* Does stuff with
 * linked lists.
 */

/* Did not finish; trying
 * to figure out why what
 * there is so far is
 * getting errors.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int n;
	struct node *next;
} nodeType;

void printList(nodeType *head)
{
	nodeType *current = head;
	while(current != NULL)
	{
		printf("%d\n", current->n)
		current = current->next;
	}
}

void clear(nodeType *head)
{
	nodeType *current = head;
	while(current != NULL)
	{
		free(*current);
	}
}

int main()
{	
	nodeType *head = NULL;

	head = malloc(sizeof(nodeType));
	head->n = 3;
	head->next = malloc(sizeof(nodeType));
	head->next->n = 1;
	head->next->next = malloc(sizeof(nodeType));
	head->next->next->n = 4;
	head->next->next->next = malloc(sizeof(nodeType));
	head->next->next->next->n = 1;
	head->next->next->next->next = malloc(sizeof(nodeType));
	head->next->next->next->next->n = 5;
	head->next->next->next->next->next = malloc(sizeof(nodeType));
	head->next->next->next->next->next->n = 9;
	head->next->next->next->next->next->next = NULL;

	printList(*head);

	clear(*head);

	return 0;
}