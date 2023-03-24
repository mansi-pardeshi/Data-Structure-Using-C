/* Que. : Doubly linked list
* Owner : Mansi Pardeshi.
* Batch : PPA9
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	struct node* pre;
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
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Enter a value\n");
		scanf("%d",&value);
		newnode -> pre = NULL;
		newnode -> data = value;
		newnode -> next = NULL;
	}
	return newnode;
}

void create_dll(struct node** head , struct node** tail)
{
	struct node* tempnode = *head;
	struct node* newnode = NULL;
	newnode = createnode();
	if(*head == NULL)
	{
		*head = newnode;
		*tail = newnode;
	}
	else
	{
		(*tail) -> next = newnode;
		newnode -> pre = *tail;
		*tail = newnode;
	}
}
void display_dll_for(struct node* head)
{
	while(head!= NULL)
	{
		printf("%d\t" , head -> data);
		head = head -> next;
	}
	printf("\n");
}

void display_dll_back(struct node* tail)
{
	while(tail!= NULL)
	{
		printf("%d\t" , tail -> data);
		tail = tail -> pre;
	}
	printf("\n");
}

void main()
{
	int choice;
	struct node* first = NULL;
	struct node* last = NULL;	
	printf("0. Exit\n");
	printf("1. Create doubly linked list\n");
	printf("2. Display DLL in forward direction\n");
	printf("3. Display DLL in backward direction\n");

	do
	{
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 0 : printf("Thank You\n");
			break;
		case 1 : create_dll(&first,&last);
			break;
		case 2 : display_dll_for(first);
			break;
		case 3 :display_dll_back(last);
			break;
		default : printf("Invalid choice\n");
		}
	}while(choice != 0);
	getch();
}