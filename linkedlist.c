#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void printList(node*head)
{
	node *temp=head;
	while(temp->next !=NULL)
	{
		printf("%d\n", temp-> data);
		temp=temp->next;
	}
}
node* add(node *head, int data)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->  data=data;
	temp -> next=head;
	head=temp;
	return head;
}
void delete(node *ptr, int data)
{
	while(ptr->next !=NULL && (ptr->next)->data!=data)
	{
		ptr=ptr->next;
	}
	if(ptr->next==NULL)
	{
		printf("%d does not exist in the list", data);
		return;
	}
	node *temp=ptr->next;
	ptr->next=temp->next;
	free(temp);
}
void clear(node *ptr)
{
	while(ptr->next!= NULL)
	{
		node *temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
	}
	node *temp=ptr->next;
	ptr->next=temp->next;
	free (temp);
}
int smallestLength(node *list_1, node *list_2)
{
	int counter_L1=0;
	int counter_L2=0;

	while(list_1->next !=NULL)
	{
		list_1=list_1->next;
		counter_L1++;
	}
	while(list_2->next!=NULL)

	{
		list_2=list_2->next;
		counter_L2++;
	}
	if (counter_L1>counter_L2)
	{
		printf("the first list is larger\n");
		return counter_L1;
	}
	else if(counter_L2>counter_L1)
	{
		printf("The second one is larger\n");
		return counter_L2;
	}
	else printf("They are the same size\n");
}
void smallestSum(node *list1, node*list2)
{
	int list1size=0;
	int list2size=0;

	while(list1->next !=NULL)
	{
		list1size+=list1->data;
		list1=list1->next;
	}
	while(list2->next=NULL)
	{
		list2size+=list2->data;
		list2=list2->next;
	}
	if(list2size>list1size)
	{
		printf("The first list is smaller, the value is %d\n", list1size);
	}
	else if(list1size>list2size)
	{
		printf("The second list is smaller, the value is %d\n", list2size);
	}
	else printf("Thetare the same size");
}
int main ()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	struct node *headTwo=(struct node*) malloc(sizeof(struct node));

	head=add(head, 4);
	head=add(head,5);
	head=add(head,6);
	head=add(head,5);
	headTwo=add(headTwo,40);
	headTwo=add(headTwo,40);
	delete(head,5);
	printList(headTwo);
	printList(head);
	smallestLength(head,headTwo);
	smallestSum(head,headTwo);
	return 0;
}


