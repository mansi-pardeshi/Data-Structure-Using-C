/* Que. :Replace node
* Owner :Mansi Pardeshi.
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


void displaylinkedlist(struct node* head)
{
	while(head != NULL)
	{
			printf("%d ",head -> data);
		head = head -> next;
	}
	printf("\n");
}

void replace(struct node** head)
{
	int pos ;
	int n ;
	int i ;
	struct node* tempnode = *head;
	struct node* newnode = NULL;
	struct node* deletenode = NULL;
	printf("Enter a position : ");
	scanf("%d",&pos);
	n = countnode(*head);
	newnode = createnode();
	if(*head == NULL)
	{
		printf("Linked list is empty\n");
	}
	else if(pos == 1 && n == 1)
	{
		tempnode = newnode;
	}
	else if(pos < 1 || pos > n)
	{
		printf("Invalid position\n");
		replace(head);
	}
	else if(pos == 1)
	{
		newnode -> next = tempnode -> next;
		free(tempnode);
		*head = newnode;
	}
	else
	{
		for(i = 1 ; i < pos-1 ; i++)
		{
			tempnode = tempnode -> next;
		}
		deletenode = tempnode -> next;
		newnode -> next = deletenode -> next;
		tempnode -> next = newnode;
		free(deletenode);
	}
}

void main()
{
	int choice;
	struct node* first = NULL;
	do
	{
		printf("1. create a linked list\n");
		printf("2. display a liked list\n");
		printf("3. replace node\n");
		printf("0. exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : createlinkedlist(&first);
				break;
			case 2 : displaylinkedlist(first);
				break;
			case 3 : replace(&first);
				break;
			case 0 : printf("Thank You\n");
				break;
			default : printf("Invalid choice\n");
		}
	}while(choice != 0);
	getch();
}

