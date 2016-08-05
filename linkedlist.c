#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

void printList(node *head) {
	node *current = head;
	current = current -> next;
	while (current != NULL) {
		printf("%d\n", current -> data);
		current = current -> next;}
}

void add(node *head,int num) {
	node *newnode;
	newnode = malloc(sizeof(struct node));
	newnode -> data = num;
	newnode -> next = head -> next;
	head -> next = newnode;
}

void removal (node *head, node *n) {
	node *temp = head;
	while (temp->next != NULL && temp->next != n) {
		temp = temp->next;}
	if (temp -> next == NULL) {
		printf("The node does not exist!");
		return;}
	temp->next = temp->next->next;
	free(n);
}

void clear (node *head) {
	node *temp = head;
	node *after;

	while (temp != NULL) {
		after = temp->next;
		free(temp);
		temp = after;
	}
	head = NULL;
}

int smallestLength (node *head1, node *head2) {
	int count1=0;
	int count2=0;
	int b;
	node *current1 = head1;
	node *current2 = head2;
	current1 = current1 -> next;
	current2 = current2 -> next;
	while (current1 != NULL) {
		count1++;
		current1 = current1 -> next;}
	while (current2 != NULL) {
		count2++;
		current2 = current2 -> next;}
		if (count1 > count2){
			b = 1;}
		if (count2 > count1){
			b = 2;}
	return b;
}

int smallestSum (node *head1, node *head2) {
	int sum1=0;
	int sum2=0;
	int a;	
	node *current1 = head1;
	node *current2 = head2;
	current1 = current1 -> next;
	current2 = current2 -> next;
	while (current1 != NULL) {
		sum1 = sum1 + current1 -> data;
		current1 = current1 -> next;}
	while (current2 != NULL) {
		sum2 = sum2 + current2->data;
		current2 = current2 -> next;}
	
	if (sum1 > sum2)
		a = 1;
	if(sum2 > sum1)
		a = 2;
	return a;
}

int main () {
	int  a, b;
	node *head =(struct node*) malloc(sizeof(struct node));
	head -> next = NULL;
	add(head, 14);
	add(head, 16);
	add(head, 11); 
	printf("The list:\n");
	printList(head);	
	add(head, 7);	
	printf("Added 7:\n");
	printList(head);
	removal(head,head->next->next->next);
	printf("Removed 16:\n");
	printList(head);
	clear(head);
	printf("Cleared List\n");
	node *head1 = (struct node*) malloc(sizeof(struct node));
	node *head2 = (struct node*) malloc(sizeof(struct node));
	head1 -> next = NULL; head2 -> next = NULL;
	add (head1, 9); add (head1, 11); add (head1, 10); add (head1, 1);

	add (head2, 16); add (head2, 6); add (head2, 8);
	printf("1st List:\n");
	printList(head1);
	printf("2nd List:\n");
	printList(head2);
	b = smallestLength(head1, head2);
	printf("Longer:%d\n", b);
	a= smallestSum(head1, head2);
	printf("Bigger one is:%d\n", a);
	
	return 0;
}
