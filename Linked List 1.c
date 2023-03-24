#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *createnode()
{
	int value;
	struct node *newnode = NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		printf("Please enter a value\n");
		scanf("%d",&value);
		newnode -> data = value;
		newnode -> next = NULL;
	}
	return newnode;
}

void createlinkedlist(struct node **head)
{
	struct node *tempnode = *head;
	struct node *newnode = NULL;
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

void displaylinkedlist(struct node *head)
{
	while(head != NULL)
	{
		printf("%d =>" , head -> data);
		head = head -> next;
	}
	printf("\n");
}

void insertatfirst(struct node **head)
{
	struct node *newnode = NULL;
	newnode = createnode();
	if(*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		newnode -> next = *head;
		*head = newnode;
	}
}

int countnode(struct node *head)
{
	int count = 0;
	while(head -> next != NULL)
	{
		count ++;
		head = head -> next;
	}
	return count;
}

void insertatposition(struct node **head)
{
	int pos;
	int n;
	int i ;
	struct node *tempnode = *head;
	struct node *newnode = NULL;
	printf("Enter position to insert\n");
	scanf("%d",&pos);
	n = countnode(*head);
	if(pos == 1)
	{
		insertatfirst(head);
	}
	else if(pos == n+1)
	{
		createlinkedlist(head);
	}
	else if(pos < 1 || pos > n+1)
	{
		printf("Invalid position\n");
		insertatposition(head);
	}
	else
	{
		newnode = createnode();
		for(i = 1 ; i < pos-1 ; i++)
		{
			tempnode = tempnode -> next;
			newnode -> next = tempnode -> next;
			tempnode -> next = newnode;
		}
	}
}

void deleteatfirst(struct node **head)
{
	struct node *tempnode = *head;
	if(*head == NULL)
	{
		printf("Linked list not available\n");
	}
	else
	{
		*head = (*head) -> next;
		*head = tempnode ->next;
		free(tempnode);
	}
}

void deleteatposition(struct node **head)
{
	struct node *tempnode = *head;
	struct node *deletenode = NULL;
	int pos;
	int i;
	int n;
	printf("Enter position\n");
	scanf("%d",&pos);
	n = countnode(*head);
	if(pos == 1)
	{
		deleteatfirst(head);
	}
	else if (pos == n)
	{
		deleteatlast(head);
	}
	else if(pos > 1 || pos < n)
	{
		for(i = 1 ; i < pos-1 ; i++)
		{
			tempnode = tempnode -> next;
		}
		deletenode = tempnode -> next;
		tempnode -> next = deletenode -> next;
		free(deletenode);

	}
}

void deleteatlast(struct node **head)
{
	if(head == NULL);
	{
		printf("Linked list not available");
	}
	else if
	{

	}
}

void main()
{
	int choice;
	struct node *first = NULL;
	printf("0. End\n");
	printf("1. Create Linked List\n");
	printf("2. Display Linked List\n");
	printf("3. Insert at first\n");
	printf("4. Insert at pos\n");
	printf("5. Delete at first\n");
	printf("6. Delete at position\n");
	do
	{
		printf("Please enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 0 : printf("Thank You");
			break;
		case 1 : createlinkedlist(&first);
			break;
		case 2 : displaylinkedlist(first);
			break;
		case 3 : insertatfirst(&first);
			break;
		case 4 : insertatposition(&first);
			break;
		case 5 : deleteatfirst(&first);
			break;
		case 6 : deleteatposition(&first);
			break;
		default : printf("Invalid Choice");
		}
	}while(choice != 0);
}
