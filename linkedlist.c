/* Jared Wasserman -- linkedlist.c */
/* This program has various function for a linked list such as adding, removing, printing, comparing, and clearing the whole list.*/
#include <stdio.h>
#include <stdlib.h> 

/* Node */
typedef struct node{
	int data;
	struct node *next;
}node;

/* add */
node* add(node *pointer, int data){
	node *newPtr = (struct node*) malloc (sizeof(struct node));
	newPtr->next = pointer;
	newPtr->data = data;
	return newPtr;
}

/* printList */
void printList(node *ptr){
	while(ptr->next!=NULL){
		printf("%d\n",(*ptr).data);
		ptr = ptr->next;
	}
}

/* delete */
void delete(node *pointer, int data){
	while(pointer->next!=NULL && (pointer->next)->data != data){ 
		pointer = pointer -> next;
	}
	if(pointer->next==NULL){
	    printf("%d was not found\n",data);
        return;
	}
	node *tempPtr = pointer -> next;
	pointer->next = tempPtr->next;
	free(tempPtr);
	return;
}

/* clear */
void clear(node *ptr){
	node *temp;
	while(ptr->next!=NULL){
		temp=ptr;
		free(ptr);
		ptr=temp;
		ptr=ptr->next;
	}
}

/* smallestLength */
int smallestLength(node *ptr, node *ptr2){
	int ptrCount=0;
	int ptr2Count=0;
	while(ptr->next!=NULL){
		ptrCount++;
		ptr = ptr->next;
	}
	while(ptr2->next!=NULL){
		ptr2Count++;
		ptr2 = ptr2->next;
	}

	if(ptrCount<=ptr2Count){
		return ptrCount;
	}else{
		return ptr2Count;
	}	
}

/* smallestSum*/
node* smallestSum(node *ptr, node *ptr2){
	node* originalPtr = ptr;
	node* originalPtr2 = ptr2;
	int ptrSum=0;
	int ptr2Sum=0;
	while(ptr->next!=NULL){
		ptrSum+=ptr->data;
		ptr = ptr->next;
	}
	while(ptr2->next!=NULL){
		ptr2Sum+=ptr2->data;
		ptr2 = ptr2->next;
	}

	if(ptrSum<ptr2Sum){
		return originalPtr;
	}else if(ptrSum==ptr2Sum){
		printf("**The two lists have the same sum**\n");
		return originalPtr;
	}else{
		return originalPtr2;
	}	
}

int main(){

	/*Making Linked List*/
	struct node *headPtr;
	headPtr = (struct node *) malloc (sizeof(struct node));
	headPtr->next = NULL;
	
	/*Filling The Linked Lists*/
	headPtr = add(headPtr,5);
	headPtr = add(headPtr,10);
	headPtr = add(headPtr,20);
	headPtr = add(headPtr,50);
	headPtr = add(headPtr,23);

	/*Printing*/
	printf("Printing The Linked List:\n");
	printList(headPtr);

	/*Deleting*/
 	delete(headPtr,10);
 	delete(headPtr,50);

 	/*Print After Deleting 10 & 50*/
 	printf("\nPrinting The Linked List After Deleting 10 & 50\n");
	printList(headPtr);

	/*Making Another Linked List*/
	struct node *headPtr2;
	headPtr2 = (struct node *) malloc (sizeof(struct node));
	headPtr2->next = NULL;
	
	/*Filling The Linked List*/
	headPtr2 = add(headPtr2,23);
	headPtr2 = add(headPtr2,778);
	headPtr2 = add(headPtr2,18);
	headPtr2 = add(headPtr2,598);
	headPtr2 = add(headPtr2,234);

	/*Printing*/
	printf("\nPrinting The Second Linked List:\n");
	printList(headPtr2);

	/*Comparing To Find Shortest List*/
	printf("\nThe length of the shorter list is: %d\n",smallestLength(headPtr, headPtr2));
	
	/*Comparing To Find Smallest Sum*/
	/*Since the function return a pointer rather than printing within the function. 
	*If the two lists have the same sum, it will print a message but also return the pointer to the first list. 
	*That is why it print one of the lists and a message saying they are the same if they are equal. */
	printf("\nThe list with the smaller sum is:\n");
	printList(smallestSum(headPtr, headPtr2));

	/*Clearing The Linked List*/
	clear(headPtr);
	clear(headPtr2);

return 0;
}