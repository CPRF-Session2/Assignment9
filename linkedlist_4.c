#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node {  //defining by structure 
	int x;
	struct node *next;} node_t;

node_t *head = NULL;   //first node is head
node_t *current = NULL;//declares a current address

void create_link(){
	head = malloc(sizeof(node_t));		//allocates first node
	head -> x = 5;		//first node value will be 5
	head-> next = malloc(sizeof(node_t));  //allocating second node
	head -> next -> x = 10;
	head -> next -> next = malloc(sizeof(node_t));
	head -> next -> next -> x = 15;
}

void printList(){
	int node_num;
	if (head == NULL)		//error situation		
		printf("error");
	current = head;
	while (current != NULL){  //going through all of the nodes in the list until it reaches NULL
	node_num++; //which node number you are on
	printf("Node number %d has data value %d\n", node_num, current->x);
	current = current -> next; //goes to next node
	};
	current = head;
}

void add(int user_x){
	node_t *new_beg = NULL; //declares a new beginning address
	new_beg = malloc(sizeof(node_t));  //allocating spaces for this new address
	new_beg -> x = user_x;    
	new_beg -> next = head; //showing that new_beg will be first in the list, before head
	head = new_beg;  //moving head to the new beginning 
}

void remoove(int user_y){
	current = head;  //starting at the first node
	node_t *temp = current; //declaring a new node temp as equal to current
	if (head->x == user_y){
		head = head->next;
		free(temp);
	};

	current = head;
	temp = current;

	while (current->next != NULL){
		if (current->next->x == user_y){
			current->next = current->next->next;
			free (temp);
		};

		current = current->next;
	};
}

void clear_list(){
	current = head;
	
	while (current->next != NULL){
		node_t *temp = current;
		current = current->next;
		free (temp);
	};

}

void smallest(){ 
	int node_num;
	int node_num2;
	int node_sum;
	int node_sum2;
	node_t *temp = head;/*start of first list*/
	while (temp != NULL){
	node_num ++;
	node_sum = temp -> x + node_sum;
	temp = temp -> next;
	};
	printf("first list length is %d\n", node_num);
	printf("sum of first list is %d\n", node_sum);
	
	temp = head->next; /*start of second list*/
	while (temp != NULL){
	node_num2 ++;
	node_sum2 = temp -> x + node_sum2;
	temp = temp -> next;
	};
	printf("second list length is %d\n", node_num2);
	printf("sum of second list is %d\n", node_sum2);
	if (node_num < node_num2)
		printf("The first list is the shortest\n");
	if (node_num > node_num2)
		printf("The second list is the shortest\n");
	}
	

int main(){
create_link();
node_t *store_head1 = head;
printList();
add(0);
printList();
remoove(5);
printList();
//clear_list();
//printList();
head = store_head1;
smallest();
return 0;
}

