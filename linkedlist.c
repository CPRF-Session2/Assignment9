//Matthew Kellerman
//code manipulates linked lists to print them out, add a node with an integer to them, remove a node with a specific intger, find which of two linked list has the smallest length/size

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node *next;
}node;

//allows me to create nodes for data structure
//when you create a new node, it will go the beginnig of the list
node* add(node *pointer,int data)
		 {
node *newPtr =(struct node*)malloc(sizeof(struct node));
newPtr->next = pointer;
newPtr->data = data;
return newPtr;

		}
//prints numbers in linked list
void printList(node *print)
{
while(print->next!=NULL)
{//prints the value of the node
	printf("%d\n",(*print).data);
	print = print->next;
//points to another node 
}
}
//allows me to remove node
void remove1(node *pointer, int data)
{
//while the pointer doesn't point to NULL and the pointer doesn't point to the value you want to delete
while(pointer->next!=NULL &&(pointer->next)->data!=data)
{

pointer = pointer ->next;
}
if(pointer->next==NULL)
{//if the number can't be found
printf("%d does not exist\n",data);
return;
}
node *tempPoint = pointer->next;//temp points to the node which has to be removed

pointer->next = tempPoint->next;//removes node next to pointer
free(tempPoint);
//frees temp
printf("%d was successfully removed\n",data);
return;
}
void clear(node*pr)
{
node *temp;
while(pr->next!=NULL)
{
	//does same thing as remove1 function except does it for all the nodes except the head one

temp = pr;
free(pr);
pr = temp;
pr = pr->next;
}
free(pr);
}

int smallestLength(node*p, node*p2)
{
int counter = 0;
int flag = 0;
while(p->next!=NULL)
	//while loop checks to see how many nodes there are
{
counter++;
p= p->next;
}

while(p2->next!=NULL)
{
	flag++;
	p2 = p2->next;
}
if(flag>counter){

return counter;
}
else {if(flag==counter){

printf("Both linked lists are the same size.\n");
return flag;
}
else{

printf("The first linked list is longer.\n");
return flag;
}
}
}
void smallestSum(node*ptr,node*ptr2)
{
int counter = 0;
int flag =0;

while(ptr->next!=NULL)
{
	counter+=ptr->data;
	ptr = ptr->next;
}                            
while(ptr2->next!=NULL)
{
	flag+=ptr2->data;
	ptr2 = ptr2->next;
}
// flag and counter represent the size of the linked lists
if(counter>flag)
{
	printf("The second list has the smallest sum.\n");
}
else{
if(flag>counter){
	printf("The first list has the smallest sum.\n");

}
else{
printf("The lists have an equal sum.\n");
}
}

}
int main()
{
struct node *head;
//allocates memory for new data structure

head = (struct node*)malloc(sizeof(struct node));

head->next= NULL;

head = add(head,37);
head = add(head,17);
head = add(head,9);
head = add(head,2);

printList(head);

printf("\n");

remove1(head,17);
remove1(head,16);
//since 17 is removed, first linked list has only three nodes
struct node*head2;
//allocates memory for new data structure
head2= (struct node *)malloc(sizeof(struct node));
head2->next=NULL;

head2 = add(head2,34);
head2 = add(head2,56);
head2 = add(head2,1);
head2 = add(head2,5);

printf("The second linked list is:\n");
printList(head2);
printf("\n");

printf("%d is the size of the smaller list\n",smallestLength(head,head2));

printf("\n");
 head2= add(head2,-10);
  printList(head2);

printf("\n");
smallestSum(head,head2);
clear(head);
clear(head2);

free(head);
free(head2);
return 0;
}
