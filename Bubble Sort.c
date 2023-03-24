//Bubble Sort

#include<stdio.h>
#include<conio.h>
void main()
{
	int a[20] , n , i , j , temp;

	printf("Enter how many elements you want to enter\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}

	printf("Given array : \n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",a[i]);
	}

	for(i=1 ; i<n ; i++)
	{
	for(j=0 ; j<n-i ; j++)
	{
		if(a[j] > a[j+1])
		{
			temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
		}
	}
	}

	printf("\nSorted array : \n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}