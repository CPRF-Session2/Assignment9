/*Mariposa Lee, creates a node structure and implements various functions.
  Incomplete, most is done through research.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int cu;
	struct node *next;
} node;   /*declares node struct*/

struct node *head = NULL;  /*setting heads*/
struct node *current = NULL;

void ins(int cu, int data) {
	struct node *link = (struct node*)malloc(sizeof(struct node));
	link -> cu= link;
	link-> data= data;
	link->next = head;
	head = link;} /*inserts and creates link, points at new nodes. Did it as a function so it would be easier in main()*/


void printList()
{
	struct node *ptr = head;
	printf("\n[ ");
	while(ptr != NULL){
		{
	printf("(%d,%d)", ptr->cu, ptr->data);
	ptr= ptr->next;
		}
		printf("]");
	}

}/*an attempted printlist*/ 

int main () {

printList();
int q, w;
ins(1, 5);
ins(2,6);

return 0;
}
