#include<stdio.h>
#include<conio.h>

int linear_search(int arr[] , int n , int data)//Linear Search Implementation
{
	int i;
	for(i=0 ; i<n ; i++)
	{
		if(arr[i] == data)
		{
			return i;
		}
	}
	
	return -1;
}

void main()
{
	int arr[50] , i , n , data , result;

	printf("Enter how mnay elments you want to insert in array\n");
	scanf("%d",&n);

	printf("Enter elements\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]);//taking input
	}

	printf("Enter a elemnt which you want to find \n");
	scanf("%d",&data);

	printf("Using Linear Serach\n");
	result = linear_search(arr,n,data);//Linear search function call
	if(result == -1)
	{
		printf("Given data %d is not present in an array\n",data);
	}
	else
	{
		printf("Given data %d is present in an array\n",data);
	}

	getch();
}
