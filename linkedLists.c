#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data; 
	struct node *next;
} node;

node* add(node *head, int num) {
	node *temp = (node *)malloc(sizeof(node));
	temp->data = num;
	temp->next =head;
	head = temp;
	return head;

	}
void printList (node *curr) {
	while (curr->next !=NULL) 
	{
		printf("%d\n", curr -> data);
		curr = curr->next;
	}
}
void delete (node *curr, int rem) {
	while (curr->next != NULL && (curr->next)-> data !=rem) {
		curr= curr -> next;
	}
	if (curr ->next ==NULL) {
		printf("The number %d is not in the list\n", rem);
		return;
	}
	node *temp = curr -> next; 
	curr ->next = temp ->next; 
	free(temp);
	return;
}
node* clear (node *curr) {
	node *head=curr; 
	while (head -> next != NULL)
	{
		head -> next = curr;
	}
	while (curr -> next != NULL)
	{
		curr -> next = head;
	}
		free (curr);
}

void smallestLength (node*l1, node *l2) {
	int countL1=0;
	int countL2=0;

	while (l1 -> next != NULL) {
		l1 ->next = l1;
		countL1++;
	}
	while (l2 -> next != NULL) {
		l2 ->next = l2;
		countL2++;
	}
	if (countL1> countL2) {
		printf("List 1 is bigger\n");
	}
	if (countL2> countL1) {
		printf("List 2 is bigger\n");
	}
	if (countL1== countL2) {
		printf("Lists are the same size\n");
	}
}
void smallestSum (node *l1, node *l2) {
	int sumL1 = 0;
	int sumL2 = 0;
	while (l1->next!=NULL) {
		l1 ->next = l1;
		sumL1+=l1 -> data;
	}
	while (l2->next!=NULL) {
		l2 ->next = l2;
		sumL2+=l2 -> data;
	}
	if (sumL1>sumL2) {
		printf("List one has a bigger sum\n");
		return; 
	}
	if (sumL2>sumL1) {
		printf("List two  has a bigger sum\n");
		return; 
	}

	if (sumL1==sumL2) {
		printf("The lists have equal sums\n");
		return; 
	}
}
int main () {
	struct node * head = (node*) malloc(sizeof(node));
	head -> next = NULL;
	node *curr=head; 
	head =add(head, 23);
	head = add(head, 5);
	head = add(head, 8);
	head = add(head, 12);
	head = add(head, 17);
	printList (head);
	delete (head, 12);
	delete (head, 4);
	node *l1; 
	node *l2;
	l1 -> next= NULL;
	l2 -> next = NULL;
	l1 = add (l1, 34); 
	l1 = add (l1, 1); 
	l1 = add (l1, 2); 
	l1 = add (l1, 43); 
	l1 = add (l1, 12);

	l2 = add (l2, 4);
	l2 = add (l2, 9);
	l2 = add (l2, 23);
	l2 = add (l2, 12);
	
//	smallestSum (l1, l2); 
//	smallestLength (l1, l2);
	printf("test1\n");
	head = clear (head);
	printf("test2\n");
//	printList (head);
	return 0; 
}
