#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};


struct node* create_node()
{
	int value;
	struct node* new_node;

	new_node = (struct node*)malloc(sizeof(struct node));

	if(new_node != NULL)
	{
		printf("Enter a value\n");
		scanf("%d",&value);
		new_node-> data = value;
		new_node->next = NULL;
	}
	else
	{
		printf("Memory is not allocated to new node");
	}

	return new_node;
}

void create_LL(struct node** head)
{
	struct node* new_node = create_node();
	struct node* trav_node = *head;

	if(*head == NULL)
	{
		*head = new_node;
		printf("created Successfully\n");
	}
	else
	{
		while(trav_node->next != NULL)
		{
			trav_node = trav_node->next;
		}

		trav_node->next = new_node;
		printf("Created Successfully\n");
	}
}


void insert_at_first(struct node** head)
{
	struct node* new_node = create_node();
	if(*head == NULL)
	{
		*head = new_node;
		printf("Inseted Successfully");
	}
	else
	{
		new_node->next = *head;
		*head = new_node;
		printf("Inseted Successfully");
	}
}

void insert_at_last(struct node** head)
{
	struct node* new_node = create_node();
	struct node* trav_node = *head;

	if(*head == NULL)
	{
		*head = new_node;
		printf("Inseted Successfully");
	}
	else
	{
		while(trav_node->next != NULL)
		{
			trav_node = trav_node->next;
		}

		trav_node->next = new_node;
		printf("Inseted Successfully");
	}
}

void insert_at_pos(struct node** head)
{
	struct node* new_node = create_node();
	struct node* trav_node = *head;
	int n = count(*head);
	int pos , i;
	printf("Enter a position\n");
		scanf("%d",&pos);

	if(*head == NULL)
	{
		printf("There is no Linked List\n");
	}
	else if(pos == 1)
	{
		insert_at_first(head);
	}
	else if(pos == n+1)
	{
		insert_at_last(head);
	}
	else if(pos>n+1 || pos<=0)
	{
		printf("Invalid position\n");
	}
	else
	{
		

		for(i=1 ; i<pos-1 ; i++)
		{
			trav_node = trav_node->next;
		}

		new_node->next = trav_node->next;
		trav_node->next = new_node;
		printf("Inserted Succesfully\n");

	}
}

void delete_at_first(struct node** head)
{
	struct node* tempnode = *head;
	if(*head == NULL)
	{
		printf("Linked List not available\n");
	}
	else
	{
		*head = (*head)->next;
		free(tempnode);
	}
}

void delete_at_last(struct node** head)
{
	struct node* trav_node = *head;
	struct node* temp_node =  NULL;
	int n = count(*head);
	int i;
	if(*head == NULL)
	{
		printf("Linked List not avalable\n");
	}
	else
	{
		for(i=1 ; i<n-1 ; i++)
		{
			trav_node = trav_node->next;
		}

		temp_node = trav_node->next;
		trav_node->next = NULL;
		free(temp_node);
	}


}

void delete_at_pos(struct node** head)
{
	struct node* temp_node = NULL;
	struct node* trav_node = *head;
	int pos,i;
	int n = count(*head);
	printf("Enter a position\n");
	scanf("%d",&pos);

	if(*head == NULL)
	{
		printf("Linked List not available\n");
	}
	else if(pos == 1)
	{
		delete_at_first(head);
	}
	else if(pos == n)
	{
		delete_at_last(head);
	}
	else if(pos<1 || pos>n)
	{
		printf("Invalid position\n");
	}
	else
	{
		for(i=1 ; i<pos-1 ; i++)
		{
			trav_node = trav_node->next;
		}
		temp_node = trav_node->next;
		trav_node->next = temp_node->next;
		free(temp_node);
	}
}

int count(struct node* head)
{
	int c=0;
	while(head != NULL)
	{
		head = head->next;
		c++;
	}
	return c;
}

void display_LL(struct node* head)
{
	printf("Linked List\n");
	while(head != NULL)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
}

void main()
{
	int choice;
	struct node* first = NULL;

	do
	{
		printf("-----------MENU-------------\n");
		printf("0. EXIT\n");
		printf("1. Create Linked List\n");
		printf("2. Display Linked List\n");
		printf("3. Insert at First\n");
		printf("4. Insert at Last\n");
		printf("5. Insert at Position\n");
		printf("6. Delete at First\n");
		printf("7. Delete at Last\n");
		printf("8. Delete at Position\n");
		printf("----------------------------\n");
		printf("Enter your choice\n");
		printf("----------------------------\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
			create_LL(&first);
			break;
		case 2:
			display_LL(first);
			break;
		case 3:
			insert_at_first(&first);
		case 4:
			insert_at_last(&first);
			break;
		case 5:
			insert_at_pos(&first);
		case 6: 
			delete_at_first(&first);
			break;
		case 7:
			delete_at_last(&first);
			break;
		case 8:
			delete_at_pos(&first);
			break;
		}
	}while(choice != 0);

	getch();

}