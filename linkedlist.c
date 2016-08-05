#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node *next;
}node;


node* add(int data, struct node* pointer)
{
	struct node* pointer = (struct node*) malloc (sizeof(struct node));
	pointer->next = pointer;
	pointer->data = data;
	return pointer;
}

void traverse(node *current) {
	    current = current->next;

while(current!=NULL) {
	current = current->next;
			}

}

node* rem(node* pointer, int data) {
/* Goes to the node for which the node after it has to be deleted */
	    while(pointer->next!=NULL && (pointer->next)->data != data) {
		            pointer = pointer -> next;
			        }
	        if(pointer->next==NULL) {
			        printf("ERROR: Element %d is not present in the list.\n",data);
				        return 0;
					    }
/* Now pointer points to a node and the node next to it has to be removed */
		    node *temp = pointer -> next;  
		    /*temp points to the node which has to be removed*/
		        pointer->next = temp->next;
/* We removed the node next to the pointer.  Because we deleted the node, we no longer require the memory used for it. free() will deallocate the memory.*/
				        free(temp);
					    return 0;
}

void printList(node *x) {
	if(x->next!=NULL) {
		printf("%d\n",x->data);
		x = x->next;
	}

	if(x->next==NULL) {
		printf("%d\n",x->data);
			return;
	}
}

int smallestLength(node *x, node *x2) {
	int count = 0;
	int count2 = 0;

	while(x->next!=NULL) {
		count++;
		x = x->next;
	}

	while(x2->next!=NULL) {
		count2++;
		x2 = x2->next;
	}

	int sameLength = count;

	if(count>count2) {
		return count;
	}
	
	if(count2>count) {
		return count2;
	}

	if(count==count2) {
		return sameLength;
	}
}

node* smallestSum(node *x, node *x2) {
	node* reusex = x;
	node* reusex2 = x2;
	int sumx;
	int sumx2;
	
	while(x->next!=NULL) {
		sumx += x->data;
		x = x->next;

	}
	
	while(x2->next!=NULL) {
		sumx2 += x2->data;
		x2 = x2->next;
	}
	
	if(sumx<sumx2) {
		return reusex;
	}

	if(sumx==sumx2) {
		printf("The linked lists have the same sum.");
		return reusex;
	}
	
	else {
		return reusex2;
	}
}

void clear(node *x) {
	node *tempPtr;
	while(x->next!=NULL){
		tempPtr=x;
		free(x);
		x=tempPtr;
		x=x->next;
	}
}

int main() {

	struct node *head;
	struct node *pointer;
	head = (struct node *) malloc (sizeof(struct node));
	head->next = NULL;

	head = add(head, 3);
	head = add(head, 7);
	head = add(head, 13);
	head = add(head, 16);
	head = add(head, 21);

	printf("The Original Linked List:\n");
	printList(head);

	rem(head, 3);

	printf("First Linked List After Deletion of 3:\n");
	printList(head);

	struct node *head2;
	head2 = (struct node *) malloc (sizeof(struct node));
	head2->next = NULL;

	head2 = add(head2, 4);
	head2 = add(head2, 9);
	head2 = add(head2, 11);
	head2 = add(head2, 17);
	head2 = add(head2, 23);

	printf("\nThe Second Linked List:\n");
	printList(head2);

	printf("The length of the shorter linked list is %d\n",smallestLength(head,head2));

	printf("The linked list with the smaller sum is:\n");
	printList(smallestSum(head, head2));

	clear(head);
	clear(head2);
	/* ^^^ Clears both linked lists. */
