#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 50

struct stack
{
	int arr[max];
	int top;
};

void init(struct stack *stackptr)
{
	stackptr->top = -1;
}

int isempty(struct stack *stackptr)
{
	if(stackptr->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isfull(struct stack *stackptr)
{
	if(stackptr->top == max-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(struct stack *stackptr , int data)
{
	(stackptr->top)++;
	stackptr->arr[stackptr->top] = data;
}

int pop(struct stack *stackptr)
{
	int n;
	n = stackptr->arr[stackptr->top];
	(stackptr->top)--;
	return n;
}

int peek(struct stack *stackptr)
{
	int n;
	n = stackptr->arr[stackptr->top];
	return n;
}

void display(struct stack *stackptr)
{
	int i=stackptr->top;
	while(i != -1)
	{
		printf("%d\t",stackptr->arr[i]);
		i--;
	}
}

void main()
{
	struct stack stack;
	int choice , data;
	init(&stack);

	do
	{
		printf("0. Exit\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("Enter Your Choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			if(isfull(&stack))
			{
				printf("Stack Overflow...Stack is full\n");
			}
			else
			{
				printf("Enter a Data\n");
				scanf("%d",&data);
				push(&stack,data);
				printf("Data Pushed...\n");
			}
			break;
		case 2:
			if(isempty(&stack))
			{
				printf("Stack Underflow...stack is empty\n");
			}
			else
			{
				data = pop(&stack);
				printf("Popped Data is %d\n",data);
			}
			break;
		case 3:
			if(isempty(&stack))
			{
				printf("Stack Underflow...stack is empty\n");
			}
			else
			{
				data = peek(&stack);
				printf("Peek Data is %d\n",data);
			}
			break;
		case 4:
			display(&stack);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Inavalid Choice...\n");
			break;
		}

	}while(choice != 0);
	getch();
}