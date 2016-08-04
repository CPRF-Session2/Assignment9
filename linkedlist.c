#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	int data;
	struct node *next;
} node;

node* add(node *ptr, int data) {
	node *ptr2 = (struct node*) malloc (sizeof(struct node));
	ptr2->next = ptr;
	ptr2->data = data;
	return ptr2;
}

void printList(node *ptr) {
	while (ptr->next!=NULL) {
		printf("%d \n", ptr->data);
		ptr = ptr->next;
	}
}

node* rem(node *ptr, int test) {
	struct node *temp = ptr;
	while (temp->next != NULL && temp->data != test) {
		if (temp->data == test) {
			break;
		}
		temp = temp->next;
	}
	if (temp->next == NULL) {
		printf("The number you're looking for is not in the list.\n");
		return temp;
	}

	temp = temp->next->next;
	ptr = temp;
	printf("temp\n");
	printList(temp);
	return ptr;
}

void smallestLength(node *ptr, node *ptr2) {
	int c1, c2;
	struct node *temp = ptr;
	while (temp->next != NULL) {
		printf("%d", c1);
		c1++;
	}
	while (temp->next !=NULL) {
		c2++;
		printf("%d", c2);
	}
	if (c1<c2) {
		printf("%d", c1);
	}
	if (c2<c1) {
		printf("%d", c2);
	}
	return;
}

int main() {
	struct node *ptr;
	ptr = (struct node *) malloc (sizeof(struct node));
	ptr->next = NULL;
	ptr = add(ptr, 12);
	ptr = add(ptr, 13);
	ptr = add(ptr, 14);
	ptr = add(ptr, 15);
//	printf("%d", ptr->data);

	struct node *ptr2;
	ptr2 = (struct node *) malloc (sizeof(struct node));
	ptr2->next = NULL;
	ptr2 = add(ptr2, 12);
	ptr2 = add(ptr2, 11);
	ptr2 = add(ptr2, 10);
	ptr2 = add(ptr2, 9);
	ptr2 = add(ptr2, 8);
	printf("list1\n");
	printList(ptr);
//	smallestLength(ptr, ptr2);
	ptr = rem(ptr, 14);
	printf("list1removed\n");
	printList(ptr);
	printf("list2\n");
	printList(ptr2);


	return 0;
}
