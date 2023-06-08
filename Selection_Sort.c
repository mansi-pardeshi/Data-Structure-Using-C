#include<stdio.h>
#include<conio.h>

void selection_sort(int arr[] , int n)
{
	int temp , i , j;
	for(i=0 ; i<n-1 ; i++)
	{
		for(j=i+1 ; j<n ; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",arr[i]);
	}
}

 

void main()
{
	int arr[50] , n , i , j;

	printf("How many elements do you want to insert in an array\n");
	scanf("%d",&n);

	printf("Enter %d elements\n",n);
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Unsorted Array\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",arr[i]);
	}

	printf("\nSorted Array With Selection Sort\n");
	selection_sort(arr, n);

	getch();
}