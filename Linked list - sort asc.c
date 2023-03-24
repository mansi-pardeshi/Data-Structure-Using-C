/* Que. : Sort in ascending order
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

void sort(struct node* head)
{
	int temp;
	struct node* tempnode2 = head;
	struct node* tempnode = head -> next;
	printf("sorted elements are :\n");
	while(head != NULL)
	{
		tempnode = head -> next;
		while(tempnode != NULL)
		{
			if((head -> data) > (tempnode -> data))
			{
				temp = head -> data;
				head -> data = tempnode -> data;
				tempnode -> data = temp;
			}
			tempnode = tempnode -> next;
		}
		head = head -> next;
	}
	display(tempnode2);
}

void main()
{
	int choice;
	struct node* first = NULL;
	do{
		printf("1. create a linked list\n");
		printf("2. display a linked list\n");
		printf("3. sort elements an ascending order\n");
		printf("0. exit\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1 : createLL(&first);
			break;
		case 2 : display(first);
			break;
		case 3 : sort(first);
			break;
		case 0 : printf("thank you\n");
			break;
		default : printf("invalid choice\n");
		}
	}while(choice != 0);
	getch();
}