/*Jinoo Hong*/
/*Write a program linkedlist.c creating a node structure as described in class. Implement the following functions for integers:
	printList(): given a linked list, print out the list
	add(): given a linked list and an integer, add a node with the integer to the beginning of the list.
	remove(): given a linked list and an integer, remove the first instance of that integer in the list. Print an error message if the integer is not found.
	clear(): given a linked list, empty the entire linked list (delete all nodes).
	smallestLength(): Given two linked lists of integers, write a function to find the length of the smallest list.
	smallestSum():Given two linked lists of integers, write a function to find the list with the smallest sum.*/

#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *next;
};


//creating a linked list
void insert(struct node *pointer, int data) {
	while(pointer->next!=NULL) {
		pointer = pointer -> next;
	}
	pointer->next = (struct node *)malloc(sizeof(struct node));
	pointer = pointer->next;
	pointer->data = data;
	pointer->next = NULL;
}


//printing the list
void printList(struct node *pointer) {
	printf("List: ");
	pointer = pointer->next;
	while(pointer->next!=NULL) {
		printf("%d ",pointer->data);
		pointer = pointer->next;
	}
	printf("\n");
}


//adding to the front of the list
void addingtofront(struct node *head, int data) {
	struct node *new;
	new=(struct node *) malloc (sizeof(struct node));
	new->next=head->next;
	head->next=new;
	new->data=data;
	printList(head);
}

//deleting an 18
void delete(struct node *pointer, int numbertofind) {
	struct node *head = pointer;
	int end = 0;
	while(pointer->next->data!=numbertofind) {
		pointer=pointer->next;
		if (pointer->next==NULL){
			printf("Number not found in list\n");
			end = 1;
		}
	}
	if (end==0) {
		struct node *temp;
		temp = pointer->next;
		pointer->next=pointer->next->next;
		free(temp);
		printList(head);
	}
}

//clearing/freeing the list
void clear (struct node *pointer) {
	struct node *temp;
	while (pointer->next!=NULL) {
		temp = pointer;
		free(pointer);
		pointer=temp;
		pointer=pointer->next;
	}
		printf("The list has been cleared\n");
}

int findsmaller(struct node *pointer1, struct node *pointer2) {
	int counter;
	for (counter = 0; pointer1->next!=NULL&&pointer2->next!=NULL;counter++, pointer1=pointer1->next, pointer2=pointer2->next) {
	}
	return counter-1;
}

int findsum(struct node *pointer1, struct node *pointer2) {
	int sum1=0;
	int sum2=0;
	while (pointer1->next!=NULL&&pointer2->next!=NULL) {
		sum1+=pointer1->data;
		sum2+=pointer2->data;
		pointer1=pointer1->next;
		pointer2=pointer2->next;
		if (pointer1->next==NULL) {
			return sum1;
		}
		if (pointer2->next==NULL) {
			return sum2;
		}

	}
}

int main () {
	//creating a list
	struct node *head;
	head=(struct node *) malloc (sizeof(struct node));
	head->next = NULL;
	int counter;
	int list [7] = {2,8,18,9,10,3,4};
	for (counter = 0; counter < 8; counter++) {
		insert(head, list[counter]);
	}
	
	//printing the list
	printList(head);
	
	//adding to the front of the list
	addingtofront(head, 7);
	addingtofront(head,12);

	//deleting from list
	delete(head,18);
	
	//clear
	clear(head);

	//creating two linked lists
	struct node *head1;
	head1=(struct node *) malloc (sizeof(struct node));
	head1->next = NULL;
	int list1 [10] = {3,5,17,21,1,13,9,11,9,23};
	for (counter = 0; counter<11;counter++) {
		insert (head1,list1[counter]);
	}

	struct node *head2;
	head2=(struct node*) malloc (sizeof(struct node));
	head2->next = NULL;
	int list2[6] = {17,22,42,8,9,2};
	for (counter = 0; counter<7;counter++) {
		insert (head2,list2[counter]);
	}

	printf("1. ");
	printList(head1);
	printf("2. ");
	printList(head2);

	printf("%d\n",findsmaller(head1,head2));
	
	printf("%d\n",findsum(head1,head2));

	return 0;
}
