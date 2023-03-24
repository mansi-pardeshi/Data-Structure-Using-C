/* Que. : Max Min 
* Owner : Mansi pardeshi.
* Batch : PPA9
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* createnode()
{
	int value;
	struct node* newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("memory not allocated\n");
	}
	else
	{
		printf("enter a value : ");
		scanf("%d",&value);
		newnode -> data = value;
		newnode -> next = NULL;
	}
	return newnode;
}

void createlinkedlist(struct node** head)
{
	struct node* newnode = NULL;
	struct node* tempnode = *head;
	newnode = createnode();
	if(*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while(tempnode -> next != NULL)
		{
			tempnode = tempnode -> next;
		}
		tempnode -> next = newnode;
	}
}

int countnode(struct node* head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head -> next;
	}
	return count;
}

void display(struct node* head)
{
	while(head != NULL)
	{
		printf("%d => ",head -> data);
		head = head -> next;
	}
	printf("\n");
}

void half(struct node* head)
{
	int n,i;
	int max = head -> data;
	int min = max;
	struct node* tempnode = head;
	n = countnode(head);
	for(i = 1 ; i < n/2 ; i++)
	{
		if(max < (head -> next -> data))
		{
			max = head -> next -> data;
		}
		head = head -> next;
	}
	printf("Maximum value is : %d\n",max);
	for(i = n/2 ; i < n ; i++)
	{
		if(min > (head -> next -> data))
		{
			min = head -> next -> data;
		}
		head = head -> next;
	}
	printf("Maximum value is : %d\n",min);
}

void main()
{
	int choice;
	struct node* first = NULL;
	do{
		printf("1. Create a linked list\n");
		printf("2. Display a linked list\n");
		printf("3. Print maximum value from 1st half and minimum value from 2nd half\n");
		printf("0. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1 : createlinkedlist(&first);
			break;
		case 2 : display(first);
			break;
		case 3 : half(first);
			break;
		case 0 : printf("Thank you\n");
			break;
		default : printf("Invalid choice\n");
		}
	}while(choice != 0);
	getch();
}