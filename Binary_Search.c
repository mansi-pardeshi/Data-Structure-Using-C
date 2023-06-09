#include<stdio.h>
#include<conio.h>

int binary_search(int arr[] , int n , int data)//Iterative Binary Search Implementation
{
	int left = 0 , right = n-1 , mid;

	while(left <= right)
	{
		mid = (left + right)/2;
		if(data == arr[mid])
		{
			return mid;
		}
		else if(data < arr[mid])
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	}

	return -1;
}


int binary_search2(int arr[] , int left , int right , int data)//Recursive Approach
{
	
	if(left <= right)
	{
		int mid = (left+right)/2;

		if(data == arr[mid])
		{
			return mid;
		}
		if(data < arr[mid])
		{
			return binary_search2(arr,left,mid-1,data);
		}
		else
		{
			return binary_search2(arr,mid+1,right,data);
		}
	}
	
	return -1;
}

void main()
{
	int arr[50] , i , n , data , result , result2;

	printf("Enter how mnay elments you want to insert in array\n");
	scanf("%d",&n);

	printf("Enter elements\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&arr[i]);//taking input
	}

	printf("Enter a elemnt which you want to find \n");
	scanf("%d",&data);

	printf("Using Iterative Binary Serach\n");
	result = binary_search(arr,n,data);//Binary search function call
	if(result == -1)
	{
		printf("Given data %d is not present in an array\n",data);
	}
	else
	{
		printf("Given data %d is present in an array\n",data);
	}

	printf("\nUsing Recursive Binary Search\n");
	result2 = binary_search2(arr,0,n-1,data);//Binary search function call
	if(result2 == -1)
	{
		printf("Given data %d is not present in an array\n",data);
	}
	else
	{
		printf("Given data %d is present in an array\n",data);
	}


	getch();
}
