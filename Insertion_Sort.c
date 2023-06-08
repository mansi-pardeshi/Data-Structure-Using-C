#include<stdio.h>
#include<conio.h>

void insertion_sort(int arr[] , int n)
{
	int i , j , empty , temp;
	for(i=1 ; i<n ; i++)
	{
		empty = i;
		temp = arr[i];
		while(arr[empty-1]>temp && empty>0)
		{
			arr[empty] = arr[empty-1];
			empty--;
		}
		arr[empty] = temp;
	}

	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",arr[i]);
	}
}
void main()
{
	int arr[50],i,j,n;

	printf("Enter how many elemnts you want to insert in an array\n");
	scanf("%d",&n);

	printf("Enter elemnts\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Unsorted Array\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",arr[i]);
	}

	printf("\nSorted Array\n");
	insertion_sort(arr,n);

	getch();
}