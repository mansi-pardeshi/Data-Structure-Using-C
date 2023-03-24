/* Que. : Rerverse
* Owner : Mansi Pardeshi.
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

int countnodes(struct node* head)
{
	int cnt = 0;
	while(head != NULL)
	{
		cnt++;
		head = head -> next;
	}
	return cnt;
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

void reverse(struct node* head)
{
	int n,i;
	struct node* tempnode = head;
	n = countnodes(head);
	if(head == NULL)
	{
		printf("linked list is empty\n");
	}
	else
	{
		while(n != 0)
		{
			head = tempnode;
			for(i = 1 ; i < n ; i++)
			{
				head = head -> next;
			}
			printf("%d => ",head -> data);
			n--;
		}
	printf("\n");
	}
}

void main()
{
	int choice;
	struct node* first = NULL;
	do{
		printf("1. create a linked list\n");
		printf("2. display a linked list\n");
		printf("3. print linked list in reversly\n");
		printf("0. exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1 : createLL(&first);
			break;
		case 2 : display(first);
			break;
		case 3 : reverse(first);
			break;
		case 0 : printf("thank you\n");
			break;
		default : printf("invalid choice\n");
		}
	}while(choice != 0);
	getch();
}