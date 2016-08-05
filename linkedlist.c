#include <stdlib.h>
#include <stdio.h>

struct node {
	int x;
	struct node *next;
};

int printlist(struct node *root)
{
	struct node *pt;
	
	pt = root;
	
	printf("%d\n", pt->x);

	while (pt->next!=0) {

		pt = pt->next;	

		printf("%d\n", pt->x);

	}

}

/* void add(struct node *pointer, int data)
{
	while (pointer->next!=NULL){
		
		pointer = pointer->next;
	}

	pointer->next = (struct node *)malloc(sizeof(struct node));
	
	pointer = pointer->next;

	pointer->x = data

}
	
*/
int main()
{
	struct node *root, *node1, *node2, *node3, *node4, *node5;

	root = (struct node *) malloc(sizeof(struct node));
	node1 = (struct node *) malloc(sizeof(struct node));
	node2 = (struct node *) malloc(sizeof(struct node));
	node3 = (struct node *) malloc(sizeof(struct node));
	node4 = (struct node *) malloc(sizeof(struct node));
	node5 = (struct node *) malloc(sizeof(struct node));
	
	root->next = node1;
	root->x = 5;

	node1->next = node2;
	node1->x = 7;

	node2->next = node3;
	node2->x = 11;

	node3->next = node4;
	node3->x = 2;

	node4->next = node5;
	node4->x = 17;

	node5->next = 0;
	node5->x = 9;

}
