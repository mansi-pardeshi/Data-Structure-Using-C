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

void createLL(struct node** head)
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

void display(struct node* head)
{
	while(head != NULL)
	{
		printf("%d => ",head -> data);
		head = head -> next;
	}
	printf("\n");
}

void search(struct node* head)
{
	int element;
	int flag = 0;
	printf("enter an element to search : ");
	scanf("%d",&element);
	while(head != NULL)
	{
		if(element == head -> data)
		{
			flag = 1;
		}
		head = head -> next;	
	}
	if(flag == 1)
		printf("element is found\n");
	else
		printf("element is not found");
}

void main()
{
	int choice;
	struct node* first = NULL;
	do{
		printf("1. create a linked list\n");
		printf("2. display a linked list\n");
		printf("3. search an element\n");
		printf("0. exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1 : createLL(&first);
			break;
		case 2 : display(first);
			break;
		case 3 : search(first);
			break;
		case 0 : printf("thank you\n");
			break;
		default : printf("invalid choice\n");
		}
	}while(choice != 0);
	getch();
}