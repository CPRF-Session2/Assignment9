#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} node;

void printList(node *n){/*prints out linked list*/
	if(n->next==NULL){
		printf("\n%d\n", n->data);
		return;
	}
	n=n->next;
	do{
		printf("%d\n", n->data);
		n=n->next;
	}while(n->next!=NULL);
	printf("%d\n", n->data);/*prints out data of last node*/
}

void add(node *n, int i){
	node *new = (node *) malloc(sizeof(node));/*allocated space*/
	new->data=i;/*sets data to i*/
	new->next=n->next;/*sets node pointer of new to first node*/
	n->next=new;/*sets head pointer to new pointer*/
}

void remove1(node *n, int i){
	int index=0;
	node *tempHead=n;
	while(n->next!=NULL && n->data!=i){/*finds location of int*/
		index++;
		n=n->next; /*increments to next location in list*/
	}
	if(n->next==NULL && n->data!=i)/*prints error if no int found*/
		fprintf(stderr,"\nError, integer not found in list.\n");
	else {
		node *before;
		node *after;
		node *temp;
		temp=n;
		before=tempHead;/*starts at beginning of list*/
		after=n->next;
		int j;
		for(j=0; j<index-1; j++)
			before=before->next;/*sets before pointer*/
		before->next=after;/*moves before pointer to after*/
		free(temp);

	}
}
int lastNode(node *n){/*returns last node data integer*/
	while(n->next!=NULL){
		n=n->next;
	}
	
	return n->data;
}
int sizeOfList(node *n){/*returns size of list*/
	int i=0;
	while(n->next!=NULL){
		i++;
		n=n->next;
	}
	
	return i;
}
void clear(node *n){
	node *temphead = n;
	int last = lastNode(n);
	int size = sizeOfList(n);
	while(size>0){
		remove1(temphead, last);/*removes last element*/
		last = lastNode(temphead);
		size = sizeOfList(temphead);
	}
	free(temphead);/*frees head node*/
}

int smallestLength(node *one, node *two){
	int oneSize = sizeOfList(one);
	int twoSize = sizeOfList(two);
	if(oneSize<twoSize){
		fprintf(stderr, "\nThe first list given is smallest\n");
		return oneSize;
	}
	fprintf(stderr, "\nThe second list given is smallest\n");
	return twoSize;
}

void smallestSum(node *one, node *two){
	int oneSize = sizeOfList(one);/*gets size of list*/
	int twoSize = sizeOfList(two);/*gets size of list*/
	int count1=0;
	int count2=0;
	one=one->next;/*sets to node past header*/
	two=two->next;/*sets to node past header*/
	for(int i=0; i<oneSize; i++){
		count1+=one->data;
		one=one->next;
	}
	for(int j=0; j<twoSize; j++){
		count2+=two->data;
		two=two->next;
	}
	if(count1>count2){
		fprintf(stderr, "The sum of the second list is smaller.");
		return;
	}
	fprintf(stderr, "The sum of the first list is smaller.");
}

int main(){
	node *head = (node *) malloc(sizeof(node));/*creates head node*/
	node *one = (node *) malloc(sizeof(node));
	node *two = (node *) malloc(sizeof(node));
	node *three = (node *) malloc(sizeof(node));
	node *four = (node *) malloc(sizeof(node));/*creates pointers*/
		
	head->next=one;
	one->next=two;
	two->next=three;
	three->next=four;/*sets next pointer for all nodes*/
	four->next=NULL;

	head->data=-1;
	one->data=1;
	two->data=2;
	three->data=3;
	four->data=4;/*sets data for all nodes*/

	node *head2 = (node *) malloc(sizeof(node));
	node *one2 = (node *) malloc(sizeof(node));
	node *two2 = (node *) malloc(sizeof(node));

	head2->next=one2;
	one2->next=two2;
	two2->next=NULL;

	head2->data=-1;
	one2->data=111;
	two2->data=222;

	free(head);
	free(head2);
	free(one);
	free(one2);
	free(two);
	free(two2);
	free(three);
	free(four);/*frees all data*/
	return 0;
}
